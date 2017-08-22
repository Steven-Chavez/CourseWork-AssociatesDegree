//Author: Steven Chavez
//Email: steven@stevenscode.com
//File: ShifyEnigma.h

#ifndef _SHIFTYENIGMA_H
#define _SHIFTYENIGMA_H

#include <string>
#include "Enigma.h"

using namespace std;

class ShiftyEnigma : public Enigma
{
private:
	//inherited key, msg, codeMsg,
	//and e from Enigma
	
	void Encode();
	void Decode();

public:
	ShiftyEnigma();
	void SetMsg(string m);
	void SetMsg(string m, int k);
	void SetCodedMsg(string msg, int key);

};
#endif