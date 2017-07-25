package chavezp6;

/**
 * Interface provided by instructor to implement in our enigma class
 */
public interface EnigmaInterface
{
    /**
     * Sets the message to be encoded.  Randomly generates and uses a key 1-50.
     * @param message the message to be encoded
     */
    public void setMessage(String message);
    /**
     * Sets the message to be encoded, with the user's specified key.  If the
     * key is outside the range 1-50, uses 1 as a key.
     * @param message the message to be encoded
     * @param key the key to use, must be 1-50 inclusive
     */
    public void setMessage(String message, int key);
    /**
     * Sets the encoded message to be decoded, with the key to be used.
     * @param encodedMessage encoded message
     * @param key key value
     */
    public void setEncodedMessage(String encodedMessage, int key);
    /**
     * Returns the decoded message.
     * @return
     */
    public String getMessage();
    /**
     * Returns the encoded message.
     * @return
     */
    public String getEncodedMessage();
    /**
     * Returns the key value.
     * @return
     */
    public int getKey();
}
