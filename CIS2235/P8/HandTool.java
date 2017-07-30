package data;

/**
 * Builds an object that matches the databases fields so that we can pass
 * the databases information around easily.
 * 
 * @author Steven Chavez <schavez256@yahoo.com>
 * File: HandTool.java
 * ChavezP8: Database Manipulation
 * CIS 2235
 */
public class HandTool 
{
    private int id;
    private String brand;
    private String kind;
    private String size;
    private double cost;
    private String purchaseDate;
    private boolean lifeTimeWarranty;
    
    /**
     * Constructs HandTool and initializes all fields to default values
     */
    public HandTool()
    {
    }
    
    /**
     * Constructs HandTool and initializes all fields to value of parameters
     * 
     * @param id - id of hand tool
     * @param brand - brand of hand tool
     * @param kind - kind of hand tool
     * @param size - size of hand tool
     * @param cost - cost of hand tool
     * @param date - date hand tool was purchased
     * @param warranty - determines if tool has lifetime warranty
     */
    public HandTool(int id, String brand, String kind, String size,
                    double cost, String date, String warranty)
    {
        this.id = id;
        this.brand = brand;
        this.kind = kind;
        this.size = size;
        this.cost = cost;
        
        purchaseDate = date;
        
        lifeTimeWarranty = warranty.equals("1");  
    }
    
    /**
     * Sets the id for hand tool
     * 
     * @param id index of hand tool
     */
    public void setId(int id)
    {
        this.id = id;
    }
    
    /**
     * Gets the id for hand tool
     * 
     * @return identifier for hand tool
     */
    public int getId()
    {
        return id;
    }
    
    /**
     * Sets the brand for the hand tool
     * 
     * @param brand maker of the hand tool
     */
    public void setBrand(String brand)
    {
        this.brand = brand;
    }
    
    /**
     * Gets the brand of the hand tool
     * 
     * @return hand tool brand 
     */
    public String getBrand()
    {
        return brand;
    }
    
    /**
     * Sets the kind of hand tool
     * 
     * @param kind type of hand tool
     */
    public void setKind(String kind)
    {
        this.kind = kind;
    }
    
    /**
     * Gets what kind of hand tool
     * 
     * @return kind of hand tool
     */
    public String getKind()
    {
        return kind;
    }
    
    /**
     * Sets the size of the hand tool
     * 
     * @param size measurement of tool
     */
    public void setSize(String size)
    {
        this.size = size;
    }
    
    /**
     * Gets the size of hand tool
     * 
     * @return size of hand tool
     */
    public String getSize()
    {
        return size;
    }
    
    /**
     * Sets the cost paid for hand tool
     * 
     * @param cost price paid for hand tool
     */
    public void setCost(double cost)
    {
        this.cost = cost;
    }
    
    /**
     * Gets the cost paid for hand tool
     * 
     * @return price paid for hand tool
     */
    public double getCost()
    {
        return cost;
    }
    
    /**
     * Sets the date hand tool was purchased
     * 
     * @param purchaseDate hand tool purchase date
     */
    public void setPurchaseDate(String purchaseDate)
    {
        this.purchaseDate = purchaseDate;
    }
    
    /**
     * Gets the date hand tool was purchased
     * 
     * @return hand tool purchase date
     */
    public String getPurchaseDate()
    {
        return purchaseDate;
    }
    
    /**
     * Sets if the tool has a life time warranty
     * 
     * @param warranty Decides if hand tool has life time warranty
     */
    public void setWarranty(boolean warranty)
    {
        lifeTimeWarranty = warranty;
    }
    
    /**
     * Gets the hand tools life time warranty
     * 
     * @return life time warranty of the hand tool
     */
    public boolean getWarranty()
    {
        return lifeTimeWarranty;
    }
}