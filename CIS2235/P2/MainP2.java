/**
 * Steven Chavez
 * schavez256@cnm.edu
 * File: MainP2.java
 * Program 2: Alarm Calculator Class
 * CIS2235
 **/
 
 import javax.swing.JOptionPane;
 
 public class MainP2
 { 
	private AlarmUI ui;
	
	public static void main(String[] args)
	{
		MainP2 app = new MainP2();
		System.exit(0);
	}
	
	MainP2()
	{
		// Display Header
		JOptionPane.showMessageDialog(null, "Steven Chavez" 
			+ "\nProgram 2" + "\nCIS 2235", "Loan Calculator",
			JOptionPane.INFORMATION_MESSAGE);
		
		ui = new AlarmUI();
		ui.run();	
	}
 }