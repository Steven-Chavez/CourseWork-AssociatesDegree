//Author: Steven Chavez
//Email: steven@stevenscode.com
//File: Enigma.h

#ifndef _ENIGMA_H
#define _ENIGMA_H

#include <string>
#include <random> 

using namespace std;

class Enigma
{
protected:			//protected for inheritance
	int key;		//key between 1-50
	string msg;		//message entered by user
	string codeMsg;	 //Coded message
	default_random_engine e;

	//does key-shift addition and builds codeMsg
	void Encode();	
	
	//does key-shift subtraction & builds msg
	void Decode();

public:
	Enigma();	//Default constructor

	//passed string to be encoded; when called
	//generates random key between and including
	//1-50; calls Encode();
	virtual void SetMsg(string msg);

	//overloaded; passed string to be encoded
	//and an int value for the key. 1st checks to 
	//see if the key is valid; if not valid key=1
	//Calls Encode()
	virtual void SetMsg(string msg, int ky);

	//passed the msg to be decoded as and key
	//used to decode org msg; calls Decode();
	virtual void SetCodedMsg(string msg, int ky);

	//returns coded msg
	string GetCodedMsg(){return codeMsg;}

	//returns decoded msg
	string GetDecodedMsg(){return msg;}

	//returns key
	int GetKey(){return key;}
};
#endif