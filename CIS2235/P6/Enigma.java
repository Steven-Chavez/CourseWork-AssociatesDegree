package chavezp6;

import java.util.Random;

/**
 * Encodes and decodes messages based on key that is given or generated.
 * 
 * @author Steven Chavez <schavez256@yahoo.com>
 * File: Enigma.java
 * Program 6: Enigma
 * CIS2235
 */
public class Enigma implements EnigmaInterface 
{
    /**
     * contains readable message
     */
    private String message;
    /**
     * contains encoded message
     */
    private String encodedMessage;
    /**
     * contains key between 1-50 used to encode or decode messages 
     */
    private int key;
    
    /**
     * Constructs Enigma class and initializes fields
     */
    public Enigma()
    {
       message = "";
       encodedMessage = "";
       key = 1;
    }
   
    /**
     * overridden method that sets the message to be encoded.
     * 
     * @param message - String that contains message to be encoded
     */
    @Override
    public void setMessage(String message) {
        this.message = message;
        
        // creates random key
        Random rand = new Random();
        key = rand.nextInt(50);
        
        encode();
        
    }

    /**
     * overloaded overridden method that sets the message
     * and key to be encoded.
     * 
     * @param message - String that contains message to be encoded
     * @param key - int that contains key to encode message
     */
    @Override
    public void setMessage(String message, int key) {
        this.message = message;
        this.key = key;
        encode();
    }

    /**
     * overridden method that sets the encoded messaged and key to 
     * be decoded
     * 
     * @param encodedMessage - String that contains message to be decoded
     * @param key - int that contains key to decode message
     */
    @Override
    public void setEncodedMessage(String encodedMessage, int key) {
        this.encodedMessage = encodedMessage;
        this.key = key;
        decode();
    }

    /**
     * overridden method that gets message
     * 
     * @return String that contains message 
     */
    @Override
    public String getMessage() {
        return message;
    }

    /**
     * overridden method that gets encoded message
     * 
     * @return String that contains encoded message
     */
    @Override
    public String getEncodedMessage() {
        return encodedMessage;
    }

    /**
     * overridden method that gets key
     * 
     * @return int that is used to decode or encode the message 
     */
    @Override
    public int getKey() {
        return key;
    }
    
    // encodes message using the key
    private void encode()
    {
        encodedMessage = "";
        char msg;
        int msgInt;
        
        for(int i = 0; i < message.length(); i++)
        {
            msg = message.charAt(i);
            msgInt = (int)msg + key;
            
            if(msgInt > 126)
            {
                msgInt = (msgInt - 127) + 32;
            }
            
            encodedMessage += (char)msgInt;
        }
        
    }
    
    // decodes encoded message using the key
    private void decode()
    {
        message = "";
        char msg;
        int msgInt;
        
        for(int i = 0; i < encodedMessage.length(); i++)
        {
            msg = encodedMessage.charAt(i);
            msgInt = (int)msg - key;
            
            if(msgInt < 32)
            {
                msgInt = 126 - (31 - msgInt);
            }
            
            message += (char)msgInt;
        }        
    }    
}
