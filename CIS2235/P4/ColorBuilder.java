import java.awt.Color;

/**
 * Color builder makes a color object out of RGB color values. The
 * default main color is black. Color builder also builds a contrasting
 * color of the main color. 
 *
 * @author Steven Chavez <schavez256@yahoo.com>
 * File: ColorBuilder.java
 * Program 4: Color Builder Frame
 * CIS2235
 **/ 
 
 public class ColorBuilder
 {
	/**
	 * Contains main Color object 
	 **/
	private Color mainColor;
	/**
	 * Contains contrasting Color object 
	 **/
	private Color conColor;
	/**
	 * Contains integer value of red
	 **/
	private int red ;
	/**
	 * Contains integer value of green
	 **/
	private int green ;
	/**
	 * Contains integer value of blue
	 **/
	private int blue ;
	/**
	 * Contains integer value of contrasting red
	 **/
	private int cRed;
	/**
	 * Contains integer value of contrasting green
	 **/
	private int cGreen;
	/**
	 * Contains integer value of contrasting blue
	 **/
	private int cBlue;
	
	/**
	 * Constructs ColorBuilder and initializes fields
	 * to default values
	 **/
	public ColorBuilder()
	{
		red = 0;
		green = 0;
		blue = 0;
		mainColor = new Color(red, green, blue);
		
		MakeContrastingColor();
	}
	
	/**
	 * Constructs ColorBuilder and initializes fields
	 * with the parameter values. 
	 * 
	 * @param _red Integer value of red between 0-255
	 * @param _green Integer value of green between 0-255
	 * @param _blue Integer value of blue between 0-255
	 **/
	public ColorBuilder(int _red, int _green, int _blue)
	{
		red  = _red;
		green = _green;
		blue = _blue;
		
		mainColor = new Color(red, green, blue);
		MakeContrastingColor();
	}
	
	/**
	 * Sets the integer value for red ranging from 0-255
	 *
	 * @param _red integer value for red
	 **/
	public void setRed(int _red)
	{
		red = _red;
	}
	
	/**
	 * Sets the integer value for green ranging from 0-255
	 *
	 * @param _green integer value for green
	 **/
	public void setGreen(int _green)
	{
		green = _green;
	}
	 
	 /**
	 * Sets the integer value for blue ranging from 0-255
	 *
	 * @param _blue integer value for blue
	 **/
	public void setBlue(int _blue)
	{
		blue = _blue;
	}
	 
	 /**
	  * Sets the integer values for red, green, and blue. 
	  * 
	  * @param _red integer value for red
	  * @param _green integer value for green
	  * @param _blue integer value for blue
	  **/
	public void setRGB( int _red, int _green, int _blue)
	{
		red = _red;
		green = _green;
		blue = _blue;
		
		mainColor = new Color(red, green, blue);
		MakeContrastingColor();
	}
	
	/**
	 * Gets color object that contains the main color. 
	 *
	 * @return mainColor Color object that contains main color
	 **/
	public Color getMainColor()
	{
		return mainColor;
	}
	
	/**
	 * Gets color object that contains the contrasting color. 
	 *
	 * @return conColor Color object that contains contrasting color
	 **/
	 public Color getContrastColor()
	 {
		//add formula to get the contrast color  
		return conColor;
	 }
	 
	 /**
	  * Overridden toString method that summaries the state 
	  * of the object.
	  *
	  * @return String representation of the object
	  */
	  @Override public String toString()
	  {
		return 
				"<html>Contrasting Color<br>"
				+ "r : " + cRed + "<br>"
				+ " g : " + cGreen + "<br>"
				+ " b : " + cBlue + "</html>";
	  }
	  
	  /**
	   * Creates a contrasting color of the main color 
	   **/
	   private void MakeContrastingColor()
	   {
		   
			// Place color RGB values into the contrasting
			// RGB values.
			cRed = red;
			cGreen = green;
			cBlue = blue;
		   
		    // determine the contrasting colors value
		    if(red == 0 && green == 0 && blue == 0)
			{
				// If all RGB values equals 0 make contrasting
				// values 255
				cRed = cGreen = cBlue =255;
			}
			else 
			{
				// check each RGB value to see if it is between 0 
				// and 127. If it is add 127.
				if(red  > 0 && red <= 127 ) {cRed += 127;}
				if(green  > 0 && green <= 127 ) {cGreen += 127;}
				if(blue  > 0 && blue <= 127 )	{cBlue += 127;}
				
				// check each RGB value to see if it is between 127 
				// and 255. If it is subtract 127.
				if(red > 127 && red <= 255) {cRed -= 127;}
				if(green > 127 && green <=255) {cGreen -= 127;}
				if(blue > 127 && blue <= 255) {cBlue -= 127;}
			}
			
			//add the colors to the contrasting color object
			conColor = new Color(cRed, cGreen, cBlue);
			
	   }
	   
 }
 
