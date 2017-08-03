package chavezp6;

import javax.swing.JFrame;

/**
 * entry point for project ChavezP56
 * 
 * @author Steven Chavez <schavez256@yahoo.com>
 File: MainP9.java
 Program 9: Enigma Polymorphism
 CIS2235
 */
public class MainP9
{
    EnigmaFrame frame;
    
    public static void main(String[] args)
    {
        MainP9 app = new MainP9();
    }
    
    public MainP9()
    {
        frame = new EnigmaFrame();
        frame.setResizable(false);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}
