package encrypt;

/**
 * Performs prime shift encryption on message encoded
 * by parent class.
 * 
 * @author Steven Chavez <schavez256@yahoo.com>
 * File: PrimeShift.java
 * Program 9: Enigma Polymorphism
 * CIS2235
 */
public class PrimeShift extends Enigma
{
   final private int[] primeNumbers;
   final private int[] primeNumberKey;
   private int locationIndex;
   
   /**
    * Constructs PrimeShift and initializes fields
    */
   public PrimeShift()
   {
       // initialize fields
       primeNumberKey = new int[]
       {
           2, 3, 5, 7, 11, 13, 17, 
           19, 23, 29, 31, 37, 41, 
           43, 47
       };
                      
       primeNumbers = new int[]
       {
           37, 41, 43, 47, 53, 59,
           61, 67, 71, 73, 79, 83, 
           89, 97, 101, 103, 107, 
           109, 113
       };       
       
       locationIndex = 0;
   }
   
   @Override
   protected void encode()
   {
       super.encode();
       
       String temp = "";
       char msg;
       
       
       for(int i = 0; i < encodedMessage.length(); i++)
       {
           msg = encodedMessage.charAt(i);
           
           // Check to see if char is prime if not prime do nothing
           if(isCharPrime(msg))
           {               
               // if key is prime shift to next prime number
               if(isKeyPrime())
               {
                   msg = primeShiftEncode(1);
               }
               else
               {
                    if(key % 2 == 0)
                    {
                        msg = primeShiftEncode(2);
                    }
                    else
                    {
                        msg= primeShiftEncode(3);    
                    }                   
               }
           }
           
           temp += msg;
       }
       
       encodedMessage = temp;
       
   }
   
   @Override
   protected void decode()
   {
       String temp = "";
       char msg = ' ';
       
       
       for(int i = 0; i < encodedMessage.length(); i++)
       {
           msg = encodedMessage.charAt(i);
           
           // Check to see if char is prime if not prime do nothing
           if(isCharPrime(msg))
           {               
               // if key is prime shift to next prime number
               if(isKeyPrime())
               {
                   msg = primeShiftDecode(1);
               }
               else
               {
                    if(key % 2 == 0)
                    {
                        msg = primeShiftDecode(2);
                    }
                    else
                    {
                        msg= primeShiftDecode(3);    
                    }                   
               }
           }
           
           temp += msg;
       }
       
       encodedMessage = temp;
       
       super.decode();
   }
   
   // checks to see if character is prime
   private boolean isCharPrime(int character)
   {
       boolean prime = false;
       
       for(int i = 0; i < primeNumbers.length; i++)
       {
           if(character == primeNumbers[i])
           {
               locationIndex = i;
               prime = true;
           }
       }
       
       return prime;
   }
   
   // checks to see if key is prime
   private boolean isKeyPrime()
   {
      boolean prime = false;
      
      for(int i = 0; i < primeNumberKey.length; i++)
       {
           if(key == primeNumberKey[i])
           {
               prime = true;
           }
       }
       
       return prime; 
   }
   
   // shifts prime number for encode
   private char primeShiftEncode(int placesToShift)
   {
       int msg;
       int shiftIndex = locationIndex + placesToShift;
       
       if(shiftIndex > (primeNumbers.length -1))
       {
           msg = primeNumbers[shiftIndex - (primeNumbers.length)];
       }
       else
       {
           msg = primeNumbers[shiftIndex];
       }
       
       return (char)msg;
   }
   
   // shifts prime number for decode
   private char primeShiftDecode(int placesToShift)
   {
       int msg;
       int shiftIndex = locationIndex - placesToShift;
       
       if(shiftIndex < 0)
       {
           shiftIndex = 0 - shiftIndex;
           msg = primeNumbers[(primeNumbers.length) - shiftIndex];
       }
       else
       {
           msg = primeNumbers[shiftIndex];
       }
       return (char)msg;
   }
   
   
}
