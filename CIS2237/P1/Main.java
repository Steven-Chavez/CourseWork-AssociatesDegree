package chavezp1;

import javax.swing.JFrame;

/**
 * entry point for project ChavezP1
 * 
 * @author Steven Chavez <steven@stevenscode.com>
 * File: Main.java
 * Program 1: Java Review
 */
public class Main {
    TipsterFrame frame;
    
    public static void main(String[] args)
    {
        Main app = new Main();
    }
    
    public Main()
    {
        frame = new TipsterFrame();
        frame.setTitle("Steven Chavez: Tipster");
        frame.setSize(300, 400);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); 
        frame.setVisible(true);
    }
}
