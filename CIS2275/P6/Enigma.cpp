//Steven Chavez
//schavez256@cnm.edu
//Enigma.cpp

#include "stdafx.h"
#include "Enigma.h"
#include <iostream>
#include <string>
#include <random>
#include <ctime>


using namespace std;

Enigma::Enigma()
{
	key = 1;
	msg = "";
	codeMsg = "";
}

void Enigma::SetMsg(string msg)
{
	this->msg = msg;

	//Generate Random number
	static std::default_random_engine e(time(0));
	static std::uniform_int_distribution<int> d(1,50);
	key = d(e);

	//calls encode
	Encode();
}

void Enigma::SetMsg(string mg, int ky)
{
	msg = mg;
	key = ky;
	
	//checks to make sure key includes
	// and is between 1-50
	if(key >= 1 && key <= 50)
	{
		Encode();
	}
	else
	{
		key = 1;
		Encode();
	}
}

void Enigma::SetCodedMsg(string msg, int ky)
{
	codeMsg = msg;
	key = ky;
	msg = "";

	Decode();
}

void Enigma::Encode()
{
	codeMsg = "";

	for(unsigned int i = 0; i < msg.size(); i++)
	{
		//to catch each letter and convert it 
		//to its numerical value
		int conv = 0;
		int ky = key;
		

		conv = msg.at(i);
		
		if(ky + conv > 126)
		{
			conv = 126 - conv;
			ky -= conv;
			conv = ky + 32;

		}
		else 
		{
			conv += ky;
		}

		codeMsg += conv;
	}
}

void Enigma::Decode()
{
	msg = "";

	for(unsigned  int i = 0; i < codeMsg.size(); i++)
	{
		int conv = 0; 
		int ky = key;
		
		
		conv = codeMsg.at(i);

		if(conv - ky < 32)
		{
			conv = conv - 32;
			ky -= conv;
			conv = 126 - ky;
		}
		else
		{
			conv -= ky;
		}

		msg += conv;

	}
}