/**
 * Steven Chavez
 * schavez256@cnm.edu
 * File: AlarmUI.java
 * Program 2: Alarm Calculator Class
 * CIS2235
 **/
 
 import javax.swing.JOptionPane;
 
 /**
  * AlarmUI handles the interaction with the user.
  * Acquiring information from the user and displaying 
  * the results back to the user.
  * 
  * @author Steven Chavez
  **/
 public class AlarmUI
 {
	/**
	 * calc object calculates time until alarm
	 **/
	private AlarmCalc calc;
	
	/**
	 * doAgain  determines if user wants to set another alarm
	 **/
	private int doAgain;
	
	
	/**
	 * Constructs AlarmUI and initializes fields.
	 **/
	public AlarmUI()
	{
		calc = new AlarmCalc();
		doAgain = 0;
	}
	
	/**
	 * run performs all interaction with the user. acquiring the necessary information and setting 
	 * it into the calc object. Also obtains the results back from calc to display to the user.
	 **/
	public void run()
	{
		do
		{
			// Obtain input from user
			String userInput = JOptionPane.showInputDialog(null, "Enter a positive Integer " 
				+"value for the year, month, day, hour, minute,\nand AM or PM separated"
				+" by commas", "Alarm Clock", JOptionPane.QUESTION_MESSAGE);
			
			calc.setUserInput(userInput);
			String results = calc.getResults();
			
			// Display results
			JOptionPane.showMessageDialog(null, results);
			
			// Determine if user wants to set another alarm
			doAgain = JOptionPane.showConfirmDialog(null,
					"Would you like to set another alarm?", "Please Confirm",
					JOptionPane.YES_NO_OPTION);
					
			// Display Good Bye message
			if (doAgain == JOptionPane.NO_OPTION)
			{
				JOptionPane.showMessageDialog(null,
						"Thank you! Good-Bye!", "Good bye",
						JOptionPane.PLAIN_MESSAGE);
			}
		} while (doAgain == JOptionPane.YES_OPTION);
	}
 }