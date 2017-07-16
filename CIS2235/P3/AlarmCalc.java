 import java.util.*;  
 import java.text.SimpleDateFormat;
 
  /**
  * AlarmCalc calculates the years, days, and hours until Alarm sounds.
  * Also formats the results and alarm date into a string. 
  *
  * @author Steven Chavez <schavez256@cnm.edu>
  * File:AlarmCalc.java
  * Program 2: Alarm Calculator Classes GUI
  * CIS2235
  **/
 public class AlarmCalc
 {
	 /**
	 * userInput contains input provided by the user
	 **/
	private String userInput;
	/**
	 * results contains formatted alarm date and hours and minutes until alarm 
	 **/
	private String results;	
	/**
	 * hrUntil contains minutes until alarm
	 **/
	private int hrUntil;
	/**
	 * dayUntil contains hours until alarm
	 **/
	private int dayUntil;
	/**
	 * yrUntil contains hours until alarm
	 **/
	private int yrUntil;
	/**
	 *	Calender object for alarm date & time.
	 */
	private Calendar alarmTime;
	/**
	 *	Calender object for current date & time.
	 */
	private Calendar timeNow;
	
	/**
	 * Constructs AlarmCalc and initializes fields.
	 **/
	public AlarmCalc()
	{
		hrUntil = 0;
		dayUntil = 0;
		yrUntil = 0;
		userInput = "";
		results = "";
		alarmTime = Calendar.getInstance();
		timeNow = Calendar.getInstance();
	}
	
	/**
	 * sets the users input into the userInput field
	 *
	 * @param	_userinput the String that contains input provided by the user
	 **/
	public void setUserInput(String _userInput)
	{
		userInput = _userInput;
		setupData();
	}
	
	/**
	 * gets results
	 *
	 * @return results the String that contains summary of calculations 
	 **/
	public String getResults()
	{
		return results;
	}
	
	/**
	 * takes the string and splits it by the (",") delimiter into String array.
     * trims split strings to avoid unnecessary white space and sets them into 
	 * the Calender object. Also enforces uniform capitalization by making all 
	 * characters lower case to avoid conflicts.
	 *
	 * @throws NumberFormatException
	 * @throws ArrayIndexOutOfBoundsException
	 */
	private void setupData() throws NumberFormatException, ArrayIndexOutOfBoundsException
	{
		// split user input into an array
		String[] userInfo = userInput.split(",");
		
		// throw ArrayIndexOutOfBoundsException if userInfo array doesn't contain 6 elements
		if((userInfo.length != 6))
		{
			throw new ArrayIndexOutOfBoundsException("Must enter all 6 values");
		}
		
		// set values into the Calender object and trim
		alarmTime.set(Calendar.YEAR, Integer.parseInt(userInfo[0].trim()));
		alarmTime.set(Calendar.MONTH, Integer.parseInt(userInfo[1].trim()) - 1);
		alarmTime.set(Calendar.DATE, Integer.parseInt(userInfo[2].trim()));
		alarmTime.set(Calendar.HOUR, Integer.parseInt(userInfo[3].trim()));
		alarmTime.set(Calendar.MINUTE, Integer.parseInt(userInfo[4].trim()));
		
		// avoid case issues by enforcing uniformity
		userInfo[5] = userInfo[5].toLowerCase().trim();
		
		// 0 for AM and 1 for PM
		if(userInfo[5].equals("am"))
		{
			alarmTime.set(Calendar.AM_PM, 0);
		}
		else
		{
			alarmTime.set(Calendar.AM_PM, 1);
		}
		
		calculate();
	}
	
	/**
	 * calculates the time until the alarm in years, days, and hours. 
	 */
	private void calculate()
	{
		// get the difference of the two calenders 
		long alarmTimeMilli = alarmTime.getTimeInMillis();
		long timeNowMilli = timeNow.getTimeInMillis();
		long differenceMilli = alarmTimeMilli - timeNowMilli;
		
		// find the total minutes, hours, and days
		double totalMin = (differenceMilli * 0.001) * 0.0166667;
		double totalHours = totalMin *  0.0166667;
		double totalDays = totalHours * 0.0416667;
		
		// decides the time until alarm in hours, days, years
		yrUntil = (int)totalDays / 365;
		dayUntil = (int)totalDays % 365;
		hrUntil = (int)totalHours % 24;
		
		formatResults();
	}
	
	/**
	 * formates results into a String to display to user 
	 */
	private void formatResults()
	{
		Date alarmDate = new Date(alarmTime.getTimeInMillis());
		SimpleDateFormat formatDate = new SimpleDateFormat("E, dd MMM yyyy hh:mm a");
		String dateToStr = formatDate.format(alarmDate);
		
		results = "<html>UNTILL ALARM:" + yrUntil + " yr "  
			+ dayUntil + " day " + hrUntil + " hr " + "<br>ALARM DATE: " + dateToStr + "</html>";
	}
 }
 