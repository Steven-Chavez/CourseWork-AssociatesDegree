package ChavezP5;

import javax.swing.JOptionPane;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;  

/**
 * does the calculations and takes the input from the form
 * and displays the results and saves them to a file.
 * 
 * @author Steven Chavez <schavez256@yahoo.com>
 * File: DataControl.java
 * Program 5: NetBeans GUI
 * CIS2235
 */
public class DataControl 
{
    private int midiChlorian;
    private int price;
    private String sum;
    private String type;
    private String name;
    private String engrave;
    private String color;
    private String material;
    private String[] accessories = {""};
    private File file;
    
    /**
     * constructs DataContral and initialize field
     */
    public DataControl()
    {
        midiChlorian = 0;
        sum = "";
        type = "";
        name = "";
        engrave = "";
        color = "";
        material = "";
        price = 0;
        
    }
    
    /**
     * constructs DataContral and initialize field
     * 
     * @param midiChlorian int containing midiChlorian level
     * @param type String containing type of lightsaber
     * @param name String containing lightsaber owner's name
     * @param engrave String containing engraving for lightsaber
     * @param color String containing color of lightsaber blade
     * @param material String containing material of lightsaber
     * @param accessories String[] containing accessories of lightsaber
     */
    public DataControl(int midiChlorian,String type, String name, 
                       String engrave, String color,
                       String material, String[] accessories)
    {
        this.midiChlorian = midiChlorian;
        this.type = type;
        this.name = name;
        this.engrave = engrave;
        this.color = color;
        this.material = material;
        this.accessories = accessories;
    }
    
    /**
     * sets the type of the lightsaber
     * 
     * @param type String containing lightsaber type 
     */
    public void setType(String type)
    {
        this.type = type;
    }
    
    /**
     * sets the name of the lightsaber's owner
     * 
     * @param name String containing 
     */
    public void setName(String name)
    {
        this.name = name;
    }
    
    /**
     * sets the engraving to put on the lightsaber
     * 
     * @param engrave String containing engraving for lightsaber
     */
    public void setEngrave(String engrave)
    {
        this.engrave = engrave;
    }
    
    /**
     * sets the color of the lightsaber blade
     * 
     * @param color String containing color of blade 
     */
    public void setColor(String color)
    {
        this.color = color;
    }
    
    /**
     * sets the material of the lightsaber
     * 
     * @param material String containing the material of lightsaber 
     */
    public void setMaterial(String material)
    {
        this.material = material;
    }
    
    /**
     * sets the accessories of the lightsaber
     * 
     * @param accessories String array containing accessories 
     */
    public void setAccessories(String[] accessories)
    {
        this.accessories = accessories;
    }
    
    /**
     * sets the midi-chlorian level
     * 
     * @param midiChlorian int containing level or mid-chlorian
     */
    public void setMidiChlorian(int midiChlorian)
    {
        this.midiChlorian = midiChlorian;
    }
    
    /**
     * gets the price of order
     * 
     * @return price int containing total price 
     */
    public int getPrice()
    {
        calcPrice();
        return price;
    }
    
    /**
     * sets the file path into file
     * 
     * @param file File containing file path
     */
    public void setFilePath(File file)
    {
        this.file = file;
        writeToFile();
    }
    
    /**
     * calculates the price of the data. Determined by which
     * material was chosen. 
     */
    public void calcPrice()
    {
        String[] tempStr;
        
        //cut unnecessary characters
        tempStr = material.split(" ");
        String materialTrim = tempStr[0].trim();
        
        price = 0;
        
        if(materialTrim.equals("Phrik"))
        {
           price = 100000;
        }
        else if(materialTrim.equals("Beskar"))
        {
           price = 50000; 
        }
        else if(materialTrim.equals("Durasteel"))
        {
           price = 25000; 
        }
        
    }
    
    /**
     * builds the summary of the data from the fields
     */
    private void buildSum()
    {
        sum = "";
        
        sum +=  "LIGHT SABER RECEIPT\r\n"
                + "Name: " + name + "\r\n"
                + "Midi-Chlorian Level: " + midiChlorian + "\r\n\r\n"
                + "LIGHT SABER DETAILS\r\n"
                + "Type: " + type + "\r\n"
                + "Color: " + color + "\r\n"
                + "Material: " + material + "\r\n"
                + "Engraving: \"" + engrave + "\"\r\n\r\n" ;
                
        if(accessories[0] != "")
        {
            sum += "ACCESSORIES\r\n";
            
            for (String element : accessories) 
            {
                if(element != null)
                {
                    sum += element + "\r\n";
                }
            }
        }
        
        
        sum += "\r\nTotal Price: " + price + " crd";
    }
    
    /**
     * overridden toString that summaries the object 
     * 
     * @return String summary of objects current state
     */
    @Override
    public String toString()
    {
        buildSum();
        return sum;
    }
   
    /**
     * writes the summary of the data collected from the form
     * to a file located by the path given to the class. 
     */
    private void writeToFile()
    {
        buildSum();
        try
        {
            FileWriter fstream = new FileWriter(file);
            BufferedWriter out = new BufferedWriter(fstream);
            out.write(sum);
            
            out.close(); 
        }
        catch(Exception e)
        {
            JOptionPane.showMessageDialog(null, "Error:" + e.getMessage());
            return;
        }
    }
    
}
