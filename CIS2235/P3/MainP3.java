import javax.swing.JFrame;

/**
 * Entry point for ChavezP3 program allowing access to AlarmFram class.
 *
 * @author Steven Chavez <schavez256@cnm.edu>
 * File: MainP3.java
 * Program 2: Alarm Calculator Classes GUI
 * CIS2235
 **/ 
 public class MainP3
 {
	 /** 
	  * frame contains AlarmFrame object 
	  **/
	 private AlarmFrame frame;

	 public static void main(String[] args)
	 {
		 MainP3 app = new MainP3();
	 }
	 
	/**
	 * Constructs MainP3 and initializes fields.
	 **/
	 public MainP3()
	 {
		 frame = new AlarmFrame();
		 frame.setTitle("ChavezP3: Alarm GUI");
		 frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		 frame.setSize(400,300);
		 frame.setVisible(true);
	 }
 }