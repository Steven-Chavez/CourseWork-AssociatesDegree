//Author: Steven Chavez
//Email: steven@stevenscode.com
//File: GEnigma.cpp

#include "stdafx.h"
#include "GEnigma.h"
#include <iostream>
#include <string>

using namespace std;


GEnigma::GEnigma()
{
}

void GEnigma::SetMsg(string m)
{
	Enigma::SetMsg(m);
	Encode();
}

void GEnigma::SetMsg(string m, int k)
{
	Enigma::SetMsg(m, k);
	Encode();
}

void GEnigma::SetCodedMsg(string m, int k)
{
	codeMsg = m;
	this->key = k;

	Decode();
	Enigma::Decode();
}

void GEnigma::Encode()
{
	string orgMsg = msg;
	int orgKey = key;
	int chposition = 0;
	string charEnig = "";
	string tempString = codeMsg;
	string gEnigma = "";

//					IMPORTANT
//	Depending on wether your using rand/srand or 
//	<random> you have to make sure you use the same
//	random scheme from computer to computer because
//	the different random generators preduce a 
//	different sequence of numbers using the same
//	seed. 

	e.seed(orgKey);
	//srand(orgKey);

	for(unsigned int i=0; i < tempString.size();i++)
	{
		charEnig = tempString.at(i);

		chposition = i;

		static std::uniform_int_distribution<int> d(1,50);
		key = d(e);
		//key = rand()%50 + 1;

		if(chposition % 2 == 0)
		{
			Enigma::SetMsg(charEnig, key);
			gEnigma += codeMsg;
		}
		else
		{
			Enigma::SetCodedMsg(charEnig, key);
			gEnigma += msg;
		}

	}

	key = orgKey;
	msg = orgMsg;

	//reverse gEnigma string
	reverse(gEnigma.begin(),gEnigma.end());

	//set gEnigma to codeMsg
	codeMsg = gEnigma;

}

void GEnigma::Decode()
{
	//add the the msg that was
	//encoded by GEnigma to gEnigmaMsg
	//to perserve GEnigma's org msg

	//fisrt we need to reverse the the codeMsg
	reverse(codeMsg.begin(),codeMsg.end());

	int orgKey = key;
	int chposition = 0;
	string charEnig = "";
	string tempString = codeMsg;
	string gEnigma = "";


//					IMPORTANT
//	Depending on wether your using rand/srand or 
//	<random> you have to make sure you use the same
//	random scheme from computer to computer because
//	the different random generators preduce a 
//	different sequence of numbers using the same
//	seed. 

	e.seed(orgKey);
	//srand(orgKey);


	for(unsigned int i=0; i < tempString.size();i++)
	{
		charEnig = tempString.at(i);

		chposition = i;

		static std::uniform_int_distribution<int> d(1,50);
		key = d(e);
		//key = rand()%50 + 1;

		if(chposition % 2 == 0)
		{
			Enigma::SetCodedMsg(charEnig, key);
			gEnigma += msg;
			
		}
		else
		{
			Enigma::SetMsg(charEnig, key);
			gEnigma += codeMsg;
		}

	}

	key = orgKey;

	//set gEnigma to codeMsg
	codeMsg = gEnigma;

}