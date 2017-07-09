//Steven Chavez
//File: AlarmClock.java
//Program 1 The Alarm Clock - Time to Sound an Alarm
//CIS2235

//File: AlarmClock.java

import javax.swing.JOptionPane;
import java.util.*;
import java.text.SimpleDateFormat;

public class AlarmClock
{
	public static void main(String [] args)
	{
		// Display header
		JOptionPane.showMessageDialog(null, "Steven Chavez\n"
		+ "CIS 2235\nProgram 1");
		
		int doAgain;
		
		do
		{
			// Create Calendar object
			Calendar alarmTime = Calendar.getInstance();
			Calendar timeNow = Calendar.getInstance();
			
			// Obtain input from user
			String alarmInput = JOptionPane.showInputDialog(null, "Enter a positive Integer " 
				+"value for the year, month, day, hour, minute,\nand AM or PM separated"
				+" by commas", "Alarm Clock", JOptionPane.QUESTION_MESSAGE);
			
			// Split user input into an array
			String[] alarmSplit = alarmInput.split(",");
			
			// set values into the Calender object and trim
			alarmTime.set(Calendar.YEAR, Integer.parseInt(alarmSplit[0].trim()));
			alarmTime.set(Calendar.MONTH, Integer.parseInt(alarmSplit[1].trim()) - 1);
			alarmTime.set(Calendar.DATE, Integer.parseInt(alarmSplit[2].trim()));
			alarmTime.set(Calendar.HOUR, Integer.parseInt(alarmSplit[3].trim()));
			alarmTime.set(Calendar.MINUTE, Integer.parseInt(alarmSplit[4].trim()));
			
			// avoid case issues by enforcing uniformity
			alarmSplit[5] = alarmSplit[5].toLowerCase().trim();
			
			// 0 for AM and 1 for PM
			if(alarmSplit[5].equals("am"))
			{
				alarmTime.set(Calendar.AM_PM, 0);
			}
			else
			{
				alarmTime.set(Calendar.AM_PM, 1);
			}
			
			// Calculate
			long alarmTimeMilli = alarmTime.getTimeInMillis();
			long timeNowMilli = timeNow.getTimeInMillis();
			long differenceMilli = alarmTimeMilli - timeNowMilli;
			long differenceSec = differenceMilli / 1000;
			long differenceMin = differenceSec / 60;
			long differenceHrs = differenceMin / 60;
			differenceMin = differenceMin - (differenceHrs * 60); 
			
			// Format date for display
			Date alarmDate = new Date(alarmTimeMilli);
			SimpleDateFormat formatDate = new SimpleDateFormat("E, dd MMM yyyy hh:mm a");
			String dateToStr = formatDate.format(alarmDate);
			
			// Display results
			JOptionPane.showMessageDialog(null, "Alarm Date:\n" + dateToStr + 	"\n\nTime Until Alarm:\nHours: " + differenceHrs 
				+ "\n" + "Minutes: " + differenceMin);
			
			doAgain =  JOptionPane.showConfirmDialog( null,
				"Do you want to go again", "Please Confirm", 
				JOptionPane.YES_NO_OPTION, JOptionPane.QUESTION_MESSAGE); 
			
		} while (doAgain == JOptionPane.YES_OPTION);
		
		JOptionPane.showMessageDialog(null, "Thank you, Good-bye!", "Good-bye", 
										JOptionPane.ERROR_MESSAGE);
	}
}
