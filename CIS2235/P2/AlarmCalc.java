/**
* Programmer: Steven Chavez
* Email: schavez256@cnm.edu
* File: AlarmCalc.java
* Program 2: Alarm Calculator Class
* CIS2235
**/

import javax.swing.JOptionPane;
import java.util.*;
import java.text.SimpleDateFormat;

/**
* AlarmCalc calculates the hours and minutes until your alarm. Also formats
* the results and alarm date into a string.
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
	* differenceMin contains minutes until alarm
	**/
	private long differenceMin;

	/**
	* differenceHrs contains hours until alarm
	**/
	private long differenceHrs;

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
		userInput = "";
		results = "";
		differenceHrs = 0;
		differenceMin = 0;
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
	*/
	private void setupData()
	{
		// Split user input into an array
		String[] userInfo = userInput.split(",");

		// set values into the Calender object and trim
		alarmTime.set(Calendar.YEAR, Integer.parseInt(userInfo[0].trim()));
		alarmTime.set(Calendar.MONTH, Integer.parseInt(userInfo[1].trim()) - 1);
		alarmTime.set(Calendar.DATE, Integer.parseInt(userInfo[2].trim()));
		alarmTime.set(Calendar.HOUR, Integer.parseInt(userInfo[3].trim()));
		alarmTime.set(Calendar.MINUTE, Integer.parseInt(userInfo[4].trim()));

		// avoid case issues by enforcing uniformity
		userInfo[5] = userInfo[5].toLowerCase().trim();

		// 0 for AM and 1 for PM
		if (userInfo[5].equals("am"))
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
	* calculates the time until the alarm in hours and minutes
	*/
	private void calculate()
	{
		long alarmTimeMilli = alarmTime.getTimeInMillis();
		long timeNowMilli = timeNow.getTimeInMillis();
		long differenceMilli = alarmTimeMilli - timeNowMilli;
		long differenceSec = differenceMilli / 1000;
		differenceMin = differenceSec / 60;
		differenceHrs = differenceMin / 60;
		differenceMin = differenceMin - (differenceHrs * 60);

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

		results = "Alarm Date:\n" + dateToStr 
			+ "\n\nTime Until Alarm:\nHours: " + differenceHrs
			+ "\n" + "Minutes: " + differenceMin;
	}
}