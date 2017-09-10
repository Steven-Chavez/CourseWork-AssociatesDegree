package chavezp1;

/**
 * Performs tip calculation using the amount of the bill, number of diners,
 * and amount of tip. Produces the results for the total amount of tip, total
 * amount of bill including the tip, and the amount each person owes.
 * 
 * @author Steven Chavez <steven@stevenscode.com>
 * File: TipsterCalc.java
 * Program 1: Java Review
 */
public class TipsterCalc {
    
    //Fields 
    private double billAmount;
    private int amountOfDiners;
    private int tipPercent;
    private double tipAmount;
    private double billTotal;
    private double amountEachDinerOwes;
    
    
    
    /**
     * Constructs TipsterCalc and initializes fields
     */
    public TipsterCalc(){
        
        //Initialize variables
        billAmount = 0.0;
        amountOfDiners = 0;
        tipPercent = 20;
        tipAmount = 0.0;
        billTotal = 0.0;
        amountEachDinerOwes = 0.0;
    }

    /**
     * Gets bill amount before tip
     * 
     * @return bill amount before tip 
     */
    public double getBillAmount() {
        return billAmount;
    }

    /**
     * Gets amount of people eating
     * 
     * @return number of diners 
     */
    public int getAmountOfDiners() {
        return amountOfDiners;
    }

    /**
     * Gets percent of tip
     * 
     * @return tip percent
     */
    public int getTipPercent() {
        return tipPercent;
    }

    /**
     * Gets tip amount
     * 
     * @return tip amount
     */
    public double getTipAmount() {
        return tipAmount;
    }

    /**
     * Gets total bill including tip
     * 
     * @return total bill
     */
    public double getBillTotal() {
        return billTotal;
    }

    /**
     * Gets amount each diner owes
     * 
     * @return amount each diner owes 
     */
    public double getAmountEachDinerOwes() {
        return amountEachDinerOwes;
    }
    
    /**
     * Sets the input data necessary for calculating the results
     * 
     * @param billAmount - amount of bill before tip
     * @param amountOfDiners - amount of people eating
     * @param tipPercent - tip percentage being payed
     */
    public void setInputData(double billAmount, 
            int amountOfDiners, int tipPercent){
        
        //Set param values into fields
        this.billAmount = billAmount;
        this.amountOfDiners = amountOfDiners;
        this.tipPercent = tipPercent;
        
        calculate();
    }
    
    //Calculates amount of tip, total bill, and amount each diner pays
    private void calculate(){
        //amount of tip
        tipAmount = ((double)tipPercent/100) * billAmount;
        
        //total bill
        billTotal = billAmount + tipAmount;
        
        //amount each person pays
        amountEachDinerOwes = billTotal/amountOfDiners;
    }
}
