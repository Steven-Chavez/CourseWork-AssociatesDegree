package chavezP7;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Polygon;

/**
 * Creates and draws the polygon and circumscribed circle graphic
 * 
 * @author Steven Chavez <schavez256@yahoo.com>
 * File: DrawPanel.java
 * Program 7: Polygons
 * CIS 2235
 */
public class DrawPanel extends javax.swing.JPanel {

    // number of sides of this polygon
    private int numSides;
    // raidus of this polygon converted to inches
    private int radius;
    // color of this polygon
    private Color color;
    // boolean deteremining whether or not to diplay the circumscribed circle
    private boolean circleSwitch;
    
    public DrawPanel() 
    {
        initComponents();  
        repaint();
    }
    
    /**
     * Sets the number of side in the polygon
     * 
     * @param numSides - number of sides in this polygon
     */
    public void setNumberOfSides(int numSides)
    {
        this.numSides = numSides;
        repaint();
    }
    
    /**
     * Sets the color of the polygon's lines
     * 
     * @param color - polygon color 
     */
    public void setColor(Color color)
    {
        this.color = color;
        repaint();
    }
    
    /**
     * Sets the radius of the polygon
     * 
     * @param radius - radius of this polygon 
     */
    public void setRadius(int radius)
    {
        this.radius = radius * 12;
        repaint();
    }
    
    /**
     * Sets true or false to display the circumscribed circle
     * 
     * @param circleSwitch - displays the circumscribed circle
     */
    public void setCircleSwitch(boolean circleSwitch)
    {
        this.circleSwitch = circleSwitch;
        repaint();
    }
    
    @Override public void paintComponent(Graphics g)
    {
        super.paintComponent(g);
        this.setForeground(Color.WHITE);
        g.setColor(color);
        
        //find center of the panel
        int yCenter = this.getHeight()/2;
        int xCenter = this.getWidth()/2;
        
        // Angle is always going to be the same because
        // they are going to be equal sides
        double angle = 2 * Math.PI /numSides;
        
        // use polygon class
        Polygon poly = new Polygon();
        
        // Add your strating points to the polygon
        poly.addPoint(xCenter + radius, yCenter);
        
        // Polygon variable for x and y points
        int xPoint, yPoint;
        
        for(int i = 1; i < numSides; i++)
        {
            // math 
            xPoint = (int) Math.round( xCenter + radius *  Math.cos(i * angle));
            yPoint = (int) Math.round( yCenter - radius * Math.sin(i * angle));
	
            poly.addPoint(xPoint, yPoint);
	
            
        }
        
        if(circleSwitch)
        {
            g.drawOval( xCenter - radius, yCenter - radius, radius * 2, radius * 2);
        }
        
        g.drawPolygon(poly);
        
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        setBackground(new java.awt.Color(255, 255, 255));

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(this);
        this.setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 400, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 400, Short.MAX_VALUE)
        );
    }// </editor-fold>//GEN-END:initComponents


    // Variables declaration - do not modify//GEN-BEGIN:variables
    // End of variables declaration//GEN-END:variables
}
