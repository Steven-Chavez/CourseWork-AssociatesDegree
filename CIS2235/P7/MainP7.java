package chavezP7;

import javax.swing.JFrame;

/**
 * Main entry point for the program
 * 
 * @author Steven Chavez <schavez256@yahoo.com>
 * File:  MainP7.java
 * Program 7: Polygons
 * CIS 2235
 */
public class MainP7 {
    
    private PolygonFrame frame;
    
    public static void main(String[] args)
    {
        MainP7 app = new MainP7();
    }
    
    public MainP7()
    {
        frame = new PolygonFrame();
        frame.setTitle("ChavezP7: Polygons");
	frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	frame.setSize(400, 700);
	frame.setVisible(true);
    }
}
