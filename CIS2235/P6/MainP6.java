package chavezp6;

import javax.swing.JFrame;

/**
 * entry point for project ChavezP56
 * 
 * @author Steven Chavez <schavez256@yahoo.com>
 * File: MainP6.java
 * Program 6: Enigma
 * CIS2235
 */
public class MainP6
{
    EnigmaFrame frame;
    
    public static void main(String[] args)
    {
        MainP6 app = new MainP6();
    }
    
    public MainP6()
    {
        frame = new EnigmaFrame();
        frame.setResizable(false);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}
