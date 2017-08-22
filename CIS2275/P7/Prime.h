//Author: Steven Chavez
//Email: steven@stevenscode.com
//File: Prime.h

#ifndef _PRIME_H
#define _PRIME_H

#include <string>
#include "Enigma.h"

using namespace std;

class Prime : public Enigma
{
private:
	//inherited key, msg, codeMsg,
	//and e from Enigma

	void Encode();
	void Decode();
public:
	Prime();
	void SetMsg(string msg);
	void SetMsg(string msg, int key);
	void SetCodedMsg(string msg, int key);

};
#endif