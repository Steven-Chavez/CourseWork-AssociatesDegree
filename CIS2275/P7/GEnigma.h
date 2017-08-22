//Author: Steven Chavez
//Email: steven@stevenscode.com
//File: GEnigma.h

#ifndef _GENIGMA_H
#define _GENIGMA_H

#include <string>
#include "Enigma.h"

using namespace std;

class GEnigma : public Enigma
{
private:
	//inherited key, msg, codeMsg,
	//and e from Enigma

	void Encode();
	void Decode();

public:
	GEnigma::GEnigma();
	void SetMsg(string m);
	void SetMsg(string m, int k);
	void SetCodedMsg(string m, int k); 
};
#endif