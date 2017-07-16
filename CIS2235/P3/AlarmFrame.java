import javax.swing.*;	
import java.awt.Container; 
import java.awt.*;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
  
 /**
 * AlarmFrame is a child class of JFrame and also implements the interface
 * ActionListener. This class is the where the program interacts with the user
 * through a GUI. AlarmFrame takes the information from the user and displays 
 * the results back.
 *
 * @author Steven Chavez <schavez256@cnm.edu>
 * File:AlarmFrame.java
 * Program 2: Alarm Calculator Classes GUI
 * CIS2235 
 **/
  public class AlarmFrame extends JFrame implements ActionListener
  {
	 /**
	  * calc contains AlarmCalc object. used to process users info.
	  **/
	 private AlarmCalc calc;
	 /**
	  * contains JLabel objects.
	  **/
	 private JLabel lblInput, lblResults;
	 /**
	  * contains JButton object. 
	  **/
	 private JButton btnCalc;
	 /**
	  * txtInput contains JTextField object.
	  **/
	 private JTextField txtInput;
	 /**
	  * contains string to contain and display user info.
	  **/
	 private String strResults, strMsg, strInput;
	 
	 /**
	 * Constructs AlarmFrame and initializes fields.
	 **/
	 public AlarmFrame() 
	 {
		 strMsg = "<html>Description:<br>Enter a positive Integer value"
		 + " for the year, month, day, hour, minute,<br>and AM or PM "
		 + " separated by commas</html>";
		 
		// create the components for GUI
		calc = new AlarmCalc();
		btnCalc = new JButton("Calculate");
		lblInput = new JLabel(strMsg);
		lblResults = new JLabel(strResults);
		txtInput = new JTextField();
		
		// initialize a container and set the layout
		Container canvas = getContentPane();
		canvas.setLayout(new GridLayout(4,1, 4, 1));
		
		// add the components to the container
		canvas.add(lblInput);
		canvas.add(txtInput);
		canvas.add(btnCalc);
		canvas.add(lblResults); 
		
		// adds the ActionListener to the button
		btnCalc.addActionListener(this);
	 }
	 
	 /**
	  * every time the button is clicked the action calls the 
	  * method calculate.
	  **/
	 public void actionPerformed(ActionEvent e)
	{
		calculate();
	}
	
	/**
	 * calculate takes the users information and places it 
	 * into the calc object where the information is processed 
	 * and results are returned
	 **/
	private void calculate()
	{
		// acquires information from user
		strInput = txtInput.getText();
		
		try
		{
			calc.setUserInput(strInput);
		}
		catch (NumberFormatException nfe)
		{
			JOptionPane.showMessageDialog(this, "Enter appropriate values",
			"NumberFormatException", JOptionPane.WARNING_MESSAGE);
			System.exit(0);
		}
		catch (ArrayIndexOutOfBoundsException aibe)
		{
			JOptionPane.showMessageDialog(this, "Enter all 6 arguments as per the description",
			"ArrayIndexOutOfBoundsException", JOptionPane.WARNING_MESSAGE);
			System.exit(0);
		}
		
		strResults = calc.getResults();
		lblResults.setText(strResults);
	}
  }