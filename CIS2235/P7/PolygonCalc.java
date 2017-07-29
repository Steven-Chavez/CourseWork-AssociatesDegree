package chavezP7;

/**
 * Calculates the perimeter and area values of a regular polygon,
 * and circumference and area values for the circumscribed circle.
 * 
 * @author Steven Chavez <schavez256@yahoo.com>
 * File: PolygonCalc.java
 * Program 7: Polygons
 * CIS 2235
 */
public class PolygonCalc 
{
    
    // contains the number of sides in a regular polygon
    private int numSides;
    // contains the radius of a regular polygon
    private int radius;
    // contains the lengths of the sides of a regular polygon
    private double sideLength;
    // contains the perimeter of a regular polygon
    private double perimeter;
    // contains the area of a regular polygon
    private double polygonArea;
    // contains the circumference of the circumscribed circle
    private double circumference;
    // contains the area of the circumscribed circle
    private double circleArea;
    
    /**
     * constructs PolygonCalc and initializes fields to default values
     */
    public PolygonCalc()
    {   
        // default values
        numSides = 3;
        radius = 1;   
        calcAll();
    }
    
    /**
     * Constructs and initializes a PolygonCalc from the specified parameters
     * 
     * @param numSides - number of sides 
     * @param radius - radius of polygon
     */
    public PolygonCalc(int numSides, int radius)
    {
        this.numSides = numSides;
        this.radius = radius; 
        calcAll();
    }
    
    /**
     * Sets the number of sides 
     * 
     * @param numSides - number of sides 
     */
    public void setNumberSides(int numSides)
    {
        this.numSides = numSides;
        calcAll();
    }
    
    /**
     * Sets the radius
     * 
     * @param radius - radius of polygon
     */
    public void setRadius(int radius)
    {
        this.radius = radius;
        calcAll();
    }
    
    /**
     * Gets perimeter of polygon
     * 
     * @return the perimeter of this polygon
     */
    public double getPerimeter()
    {
        return perimeter;
    }
    
    /**
     * Gets area of polygon
     * 
     * @return the area of this polygon
     */
    public double getPolygonArea()
    {
        return polygonArea;
    }
    
    /**
     * Gets the circumference 
     * 
     * @return the circumference of this circumscribed circle
     */
    public double getCircumference()
    {
        return circumference;
    }
    
    /**
     * Gets the area of the circle
     * 
     * @return the area of this circumscribed circle
     */
    public double getCircleArea()
    {
        calcCircleArea();
        return circleArea;
    }
    
    private void calcAll()
    {
        calcSideLength();
        calcPerimeter();
        calcPolygonArea();
        calcCircumference();
        calcCircleArea();                
    }
    
    // calculates the side lenght
    private void calcSideLength()
    {
        double sine = calcSineInDegrees(180);
        
        sideLength = 2 * radius * sine;
    }
    
    // calculates the perimeter of a regular polygon
    private void calcPerimeter()
    {
        perimeter = numSides * sideLength;
    }
    
    // calculate the area of a regular polygon
    private void calcPolygonArea()
    {
        double sine = calcSineInDegrees(360);
        
        polygonArea = (Math.pow(radius, 2) * numSides * sine)/2;
    }
    
    // calculates the circumference of the circumscribed circle
    private void  calcCircumference()
    {
        circumference = Math.PI * (2 * radius);
    }
    
    // calculates the area of the circumscribed circle
    private void calcCircleArea()
    {
        circleArea = Math.PI * (Math.pow(radius, 2));
    }
    
    // calculates sine in degrees
    private double calcSineInDegrees(int degrees)
    {
        double angle = (double)degrees/numSides;
        angle = angle * (Math.PI/180);
        double sine = Math.sin(angle);
        
        return sine;
    }
    
    // returns summary of object
    @Override public String toString()
    {
        return  "Perimeter: " + perimeter + "\n" +
                "Polygon Area: " + polygonArea + "\n" +
                "Circumference: " + circumference + "\n" +
                "Circle Area: " + circleArea + "\n";
    }          
}