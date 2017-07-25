package ChavezP5;

import javax.swing.JFrame;

/**
 * entry point for project ChavezP5 
 * 
 * @author Steven Chavez <schavez256@yahoo.com>
 * File: MainP5.java
 * Program 5: NetBeans GUI
 * CIS2235
 */
public class MainP5
{

  ProductFrame frame;

  public static void main(String[] agrs)
  {
    MainP5 app = new MainP5();
  }

  public MainP5()
  {
    frame = new ProductFrame();
    //frame.setTitle("This is ME");
    frame.setSize(536, 670);
    frame.setResizable(false);
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    frame.setVisible(true);
  }

}
