import javax.swing.JFrame;

/**
 * Entry point for ChavezP4 program 
 *
 * @author Steven Chavez <schavez256@yahoo.com>
 * File: MainP4.java
 * Program 4: Color Builder Frame
 * CIS2235
 **/ 
 public class MainP4
 { 
	 private ColorFrame frame;
	 
	public static void main(String[] args)
	{
		MainP4 app = new MainP4();
	}
	
	MainP4()
	{
		 frame = new ColorFrame();
		 frame.setTitle("ChavezP2: Color Builder");
		 frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		 frame.setSize(400,600);
		 frame.setVisible(true);
	}
 }