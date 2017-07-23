import javax.swing.*;
import java.awt.*;
import javax.swing.event.*;	

/**
 * The main interaction between the user and the 
 * program. creates GUI and communicates with 
 * ColorBuilder to get the color objects.
 *
 * @author Steven Chavez <schavez256@yahoo.com>
 * File: ColorFrame.java
 * Program 4: Color Builder Frame
 * CIS2235
 **/ 
 
 public class ColorFrame extends JFrame
 {
	private ColorBuilder color;
	private String rTxt, gTxt, bTxt, resultsTxt;
	private JSlider redSlider, greenSlider, blueSlider;
	private JLabel lblRed = new JLabel(rTxt);
	private JLabel lblGreen = new JLabel(gTxt);
	private JLabel lblBlue = new JLabel(bTxt);
	private JLabel lblResults = new JLabel(resultsTxt);
	private int rVal, gVal, bVal;
	
	
	public ColorFrame()
	{
		// initiate ColorBuilder object
		color = new ColorBuilder();
		
		// Instantiate red slider
		redSlider = new JSlider(0, 255, 0);
		redSlider.setMajorTickSpacing(50);
		redSlider.setMinorTickSpacing(1);
		redSlider.setPaintTicks(true);
		redSlider.setPaintLabels(true);
		
		// Instantiate red slider
		greenSlider = new JSlider(0, 255, 0);
		greenSlider.setMajorTickSpacing(50);
		greenSlider.setMinorTickSpacing(1);
		greenSlider.setPaintTicks(true);
		greenSlider.setPaintLabels(true);
	
		// Instantiate red slider
		blueSlider = new JSlider(0, 255, 0);
		blueSlider.setMajorTickSpacing(50);
		blueSlider.setMinorTickSpacing(1);
		blueSlider.setPaintTicks(true);
		blueSlider.setPaintLabels(true);
		
		// Set slider values into labels
		rVal = redSlider.getValue();
		rTxt  = "Red Value: " + rVal;
		lblRed.setText(rTxt);
		
		gVal = greenSlider.getValue();
		gTxt  = "Green Value: " + gVal;
		lblGreen.setText(gTxt);
		
		bVal = blueSlider.getValue();
		bTxt  = "Blue Value: " + bVal;
		lblBlue.setText(bTxt);
		
		// instantiate lblResults
		resultsTxt = color.toString();
		lblResults.setText(resultsTxt);
		lblResults.setOpaque(true);
		lblResults.setBackground(color.getMainColor());
		lblResults.setForeground(color.getContrastColor());
		
		
		// Set foreground of label to appropriate color
		lblRed.setForeground(Color.RED);
		lblGreen.setForeground(Color.GREEN);
		lblBlue.setForeground(Color.BLUE);
	
		// initialize a container and set the layout
		Container canvas = getContentPane();
		canvas.setLayout(new GridLayout(7,1, 20, 1));
		canvas.setBackground(Color.black);
		
		//Add components to canvas.
		canvas.add(lblRed);
		canvas.add(redSlider);
		canvas.add(lblGreen);
		canvas.add(greenSlider);
		canvas.add(lblBlue);
		canvas.add(blueSlider);
		canvas.add(lblResults);
		
		// Slider Change Listeners
		redSlider.addChangeListener(new ChangeListener()
		{
			public void stateChanged(ChangeEvent e)
			{
				updateSlider("red");
				updateResults();
			}
		});
		
		greenSlider.addChangeListener(new ChangeListener()
		{
			public void stateChanged(ChangeEvent e)
			{
				updateSlider("green");
				updateResults();
			}
		});
		
		blueSlider.addChangeListener(new ChangeListener()
		{
			public void stateChanged(ChangeEvent e)
			{
				updateSlider("blue");
				updateResults();
			}
		});
	}
	
	/**
	 * gets the current value of the slider. which slider is
	 * is decided by the color put into the parameter. The
	 * colors you can pass is red, green, blue.
	 *
	 * @param color String that contains "red", "green", or "blue"
	 **/
	private void updateSlider(String color)
	{
		if(color.equals("red"))
		{
			rVal = redSlider.getValue();
			rTxt  = "Red Value: " + rVal;
			lblRed.setText(rTxt);
		}
		else if(color.equals("green"))
		{
			gVal = greenSlider.getValue();
			gTxt  = "Green Value: " + gVal;
			lblGreen.setText(gTxt);
		}
		else if(color.equals("blue"))
		{
			bVal = blueSlider.getValue();
			bTxt  = "Blue Value: " + bVal;
			lblBlue.setText(bTxt);
		}				
	}
	
	/**
	 * gets the current RGB values and sets them into
	 * color and updates the results label
	 **/
	private void updateResults()
	{
		color.setRGB(rVal, gVal, bVal);
		resultsTxt = color.toString();
		lblResults.setText(resultsTxt);
		lblResults.setBackground(color.getMainColor());
		lblResults.setForeground(color.getContrastColor());
	}
 }