package encrypt;

/**
 * Alternates even and odd index characters of a string encoded by 
 * parent classes encode method.
 * 
 * @author Steven Chavez <schavez256@yahoo.com>
 * File: Alternate.java
 * Program 9: Enigma Polymorphism
 * CIS2235
 */
public class Alternate extends Enigma
{
    String even, odd;
    
    public Alternate()
    {
        even = "";
        odd = "";
    }
    
    @Override
    protected void encode()
    {
        super.encode();
        
        String temp = "";
        char msg;
        
        separateEvensAndOdds();
        
        if(key % 2 == 0)
        {
            encodedMessage = even;
            encodedMessage += odd;
        }
        else
        {
            encodedMessage = odd;
            encodedMessage += even;
        }
    }
    
    @Override 
    protected void decode()
    {
        String temp = "";
        char msg;
        
        if(key % 2 == 0)
        {
            seperateWithEvenKey();
            temp = combineEvenAndOdd();
  
        }
        else
        {
            seperateWithOddKey();
            temp = combineEvenAndOdd();
        }
        
        encodedMessage = temp;
        
        super.decode();
    }

    // seperates string into the Strings even or odd depending if the 
    // char index of string is even or odd.
    private void separateEvensAndOdds()
    {       
        even = "";
        odd = "";
        
        for(int i = 0; i < encodedMessage.length(); i ++)
        {
            if(i == 0)
            {
                even += encodedMessage.charAt(i);
            }
            else if(i % 2 == 0)
            {
                even += encodedMessage.charAt(i);
            }
            else
            {
                odd += encodedMessage.charAt(i);
            }
        }
    }

    // seperates encodedMessage when using an even key
    private void seperateWithEvenKey() 
    {
        even = "";
        odd = "";
 
        int length = encodedMessage.length();
        float halfEven = length * (float)0.5;
        int halfOdd;
        
        if(length % 2 == 0)
        {
            for(int i = 0; i < length; i++)
            {
                if(i < halfEven)
                {
                    even += encodedMessage.charAt(i);
                }
                else
                {
                    odd += encodedMessage.charAt(i);
                }
            }
        }
        else
        {
            halfOdd = Math.round(halfEven);
            
            for(int i = 0; i < length; i++)
            {
                if(i < halfOdd)
                {
                    even += encodedMessage.charAt(i);
                }
                else
                {
                    odd += encodedMessage.charAt(i);
                }
            }
        }
    }
    
    // seperates encodedMessage when using an odd key
    public void seperateWithOddKey()
    {
        even = "";
        odd = "";
 
        int length = encodedMessage.length();
        float halfEven = length * (float)0.5;
        int halfOdd;
        
        if(length % 2 == 0)
        {
            for(int i = 0; i < length; i++)
            {
                if(i < halfEven)
                {
                    odd += encodedMessage.charAt(i);
                }
                else
                {
                    even += encodedMessage.charAt(i);
                }
            }
        }
        else
        {
            halfOdd = Math.round(halfEven);
            
            for(int i = 0; i < length; i++)
            {
                if(i < halfOdd - 1)
                {
                    odd += encodedMessage.charAt(i);
                }
                else
                {
                    even += encodedMessage.charAt(i);
                }
            }
        }
    }

    // splice even and odd string back it's original form 
    private String combineEvenAndOdd() 
    {
        String temp = "";
        int length = encodedMessage.length();
        int half;
        
        if(length % 2 == 0)
        {
            half = length / 2;
            
            for(int i = 0; i < half; i++)
            {
                temp += even.charAt(i);
                temp += odd.charAt(i);
            }
        }
        else
        {
            half = Math.round(length * (float)0.5);
            
            for(int i = 0; i < half; i++)
            {
                if(i < (half -1))
                {
                    temp += even.charAt(i);
                    temp += odd.charAt(i);
                }
                else
                {
                    temp += even.charAt(i);
                }   
            }   
        }
        return temp;
    }
}
