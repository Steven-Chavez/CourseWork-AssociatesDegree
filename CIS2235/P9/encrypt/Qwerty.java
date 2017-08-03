package encrypt;

/**
 * Encrypts message that has been encoded by the parent. Encrypts using the 
 * QWERTY guidelines where you use the keyboard to shift each letter in the 
 * message.
 * 
 * @author Steven Chavez <schavez256@yahoo.com>
 * File: Qwerty.java
 * Program 9: Enigma Polymorphism
 * CIS2235
 */
public class Qwerty extends Enigma
{
    final private char[][][] keyBoard;
    private int caps;
    private int rowIndex, colIndex;
    
    public Qwerty()
    {
        // keyboard[lower 0 or upper 1] [row 1-3] [colum]
        keyBoard = new char[][][]
        {
            {
                {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'},
                {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'},
                {'z', 'x', 'c', 'v', 'b', 'n', 'm'}                    
            },
            {
                {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P'},
                {'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L'},
                {'Z', 'X', 'C', 'V', 'B', 'N', 'M'}
            }
        };
          
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
            
            // ensure that char is a letter and if it is capitalized or not
            if(withInRange(msg))
            {
                locateChar(msg);
                msg = shiftEncode(msg);
            }
            
            temp += msg;
        }
        encodedMessage = temp;
    }
    
    @Override
    protected void decode()
    {
        String temp = "";
        char msg;
        
        for(int i = 0; i < encodedMessage.length(); i++)
        {
            msg = encodedMessage.charAt(i);
            
            // ensure that char is a letter and if it is capitalized or not
            if(withInRange(msg))
            {
                locateChar(msg);
                msg = shiftDecode(msg);
            }
            
            temp += msg;
        }
        encodedMessage = temp;
        
        super.decode();
    }
    
    // checks to see if char is a letter and if so determines if it is 
    // upper(65-90 ascii range) or lower case(97-122 ascii range)
    private boolean withInRange(int msg)
    {
        boolean range = false;
        
        // check to see if msg is a letter
        if((msg <= 90 && msg >= 65) || (msg <= 122 && msg >=97))
        {
            range = true;
            
            //check to see if capitalized or not
            if(msg <= 90 && msg >= 65)
            {
                caps = 1;
            }
            else
            {
                caps = 0;
            }
        }
        
        return range;
    }
    
    // find the location of char
    private void locateChar(int msg)
    {
        //check through all 3 rows
        for(int i = 0; i < 3; i++)
        {
            // get the length of the row
            int length = keyBoard[caps][i].length;
            
            // check through each colum for match
            for(int j = 0; j < length; j++)
            {
                if(msg == keyBoard[caps][i][j])
                {
                    rowIndex = i;
                    colIndex = j;
                }
            }
        }
    }
    
    // shifts char according to QWERTY guidlines to encode
    private char shiftEncode(char msg)
    {
        char msgShift;
        
        if(msg == 'p' || msg == 'P')
        {
            msgShift = msg;
        }
        else
        {
            if(rowIndex == 2)
            {
                msgShift = keyBoard[caps][0][colIndex];
            }
            else if(rowIndex == 1)
            {
                if(colIndex < 7)
                {
                    msgShift = keyBoard[caps][2][colIndex];
                }
                else
                {
                    msgShift = keyBoard[caps][0][colIndex];
                }
            }
            else
            {
                msgShift = keyBoard[caps][1][colIndex];
            }
        }
        
        return msgShift;
    }
    
    // shifts char according to QWERTY guidlines to decode
    private char shiftDecode(char msg)
    {
        char msgShift;
        
        if(msg == 'p' || msg == 'P')
        {
            msgShift = msg;
        }
        else
        {
            if(rowIndex == 2)
            {
                msgShift = keyBoard[caps][1][colIndex];
            }
            else if(rowIndex == 1)
            {
                msgShift = keyBoard[caps][0][colIndex];
            }
            else
            {
                if(colIndex < 7)
                {
                    msgShift = keyBoard[caps][2][colIndex];
                }
                else
                {
                    msgShift = keyBoard[caps][1][colIndex];
                }
            }
        }
        
        return msgShift;
    }
    
}
