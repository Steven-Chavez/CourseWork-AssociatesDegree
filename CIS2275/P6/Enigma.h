//Steven Chavez
//schavez256@cnm.edu
//Enigma.h

#ifndef _ENIGMA_H
#define _ENIGMA_H

#include <string>
#include <random>


using namespace std;

class Enigma
{
private:
	int key;		//key between 1-50
	string msg;		//message entered by user
	string codeMsg;	//Coded message
	

	//does key-shift addition and builds codeMsg
	void Encode();	
	
	//does key-shift subtraction & builds msg
	void Decode();

public:
	Enigma();	//Default constructor

	//passed string to be encoded; when called
	//generates random key between and including
	//1-50; calls Encode();
	void SetMsg(string msg);

	//overloaded; passed string to be encoded
	//and an int value for the key. 1st checks to 
	//see if the key is valid; if not valid key=1
	//Calls Encode()
	void SetMsg(string mg, int ky);

	//passed the msg to be decoded as and key
	//used to decode org msg; calls Decode();
	void SetCodedMsg(string msg, int ky);

	//returns coded msg
	string GetCodedMsg(){return codeMsg;}

	//returns decoded msg
	string GetDecodedMsg(){return msg;}

	//returns key
	int GetKey(){return key;}
};
#endif