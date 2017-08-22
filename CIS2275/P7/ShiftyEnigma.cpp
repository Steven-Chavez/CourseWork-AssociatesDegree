//Author: Steven Chavez
//Email: steven@stevenscode.com
//File: ShifyEnigma.cpp


#include "stdafx.h"
#include "ShiftyEnigma.h"
#include <iostream>
#include <string>

using namespace std;

//					SUMMARY
//	Each Character in the message (after it
//	has been key-shifted) is converted to its 
//	ASCII value. The Value is is subtracted 
//	from 1000, resulting in a triplet of numbers
//	Each digit of the triplet is then converted
//	to the symbolic value on the keyboard above
//	the numbers 1-0. The string of symbols is the
//	encoded message.

//					EXAMPLE
//	If the character's value is 37, it is subtracted
//	from 1000, resulting in a triplet of 963. the 
//	corresponding keyboard characters are (^#.

ShiftyEnigma::ShiftyEnigma()
{
}

void ShiftyEnigma::SetMsg(string msg)
{
	Enigma::SetMsg(msg);
	Encode();
}

void ShiftyEnigma::SetMsg(string msg, int key)
{
	Enigma::SetMsg(msg, key);
	Encode();
}

void ShiftyEnigma::SetCodedMsg(string msg, int key)
{
	codeMsg = msg;
	this->key = key;

	Decode();
	Enigma::Decode();
}


void ShiftyEnigma::Encode()
{

	//make an array of symbolic symbols of 1-0 
	//on the keyboard
	char symb[10] = { ')', '!', '@', '#', '$',
					'%', '^', '&', '*', '('};

	string shift = "";

	for(unsigned int i = 0; i < codeMsg.size(); i++)
	{
		int cnv = 0;
		int symbIndex = 0;

		cnv = 1000 - codeMsg.at(i);

		//catches fist number of triplet
		symbIndex = cnv/100;

		//puts first number symbolic symbol
		//into shift string
		shift += symb[symbIndex];

		//subtract the first of the three
		// * 100 to get rid of the fist
		//number.
		cnv -= (symbIndex*100);

		//catches second number
		symbIndex = cnv/10;

		//adds second numbers symbolic symbol
		//to string.
		shift += symb[symbIndex];
		
		cnv -= (symbIndex*10);

		//adds third  numbers symbolic symbol 
		//to string.
		shift += symb[cnv];


	}

	//replaces old codeMsg with the shifty scheme
	//coded msg.
	codeMsg = shift;
}

void ShiftyEnigma::Decode()
{
	//make an array of symbolic symbols of 1-0 
	//on the keyboard
	char symb[10] = { ')', '!', '@', '#', '$',
					'%', '^', '&', '*', '('};

	string shift = "";

	for(unsigned int i = 0; i < codeMsg.size(); i++)
	{
		int cnv = 0;
		int index = 0;

		//we have to match the symbol with
		//the array's index to get the number.
		for(int n = 0; n < 10; n++)
		{
			if(codeMsg.at(i) == symb[n])
			{
				index = n;
			}
		}
		//getting the fist of the triplet
		//with is in the hundreths place.
		cnv = (index * 100);
		
		//increment i to get the second 
		//number of the triplet.
		i++;

		//match second symbol to array's index
		for(int n = 0; n < 10; n++)
		{
			if(codeMsg.at(i) == symb[n])
			{
				index = n;
			}
		}

		//times it by ten because its
		//in the tenths place.
		cnv += (index *10);

		//increment to get last number 
		//of the triplet
		i++;

		//match second symbol to array's index
		for(int n = 0; n < 10; n++)
		{
			if(codeMsg.at(i) == symb[n])
			{
				index = n;
			}
		}

		//adds last number to the triplet
		cnv += index;

		//to get the ASCII number subtract 
		//1000 by cnv
		cnv = 1000 - cnv;

		shift += cnv;

	}

	codeMsg = shift;

}