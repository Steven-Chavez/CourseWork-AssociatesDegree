package user;

import javax.swing.JFrame;


/**
 * Main entry point for program
 * 
 * @author Steven Chavez <schavez256@yahoo.com>
 * File: MainP8.java
 * ChavezP8: Database Manipulation
 * CIS 2235
 */
public class MainP8 
{
    private HandToolFrame frame;
    
    public static void main(String[] args)
    {
        MainP8 app = new MainP8();
    }
    
    public MainP8()
    {
        frame = new HandToolFrame();
        frame.setTitle("ChavezP8: Database Manipulation");
	frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	frame.setVisible(true);
    }
    
}
