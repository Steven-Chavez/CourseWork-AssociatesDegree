//Author: Steven Chavez
//Email: steven@stevenscode.com
//File: Prime.cpp

#include "stdafx.h"
#include "Prime.h"
#include "iostream"
#include "string"

using namespace std;

Prime::Prime()
{
}

void Prime::SetMsg(string msg)
{
	Enigma::SetMsg(msg);
	Encode();
}

void Prime::SetMsg(string msg, int key)
{
	Enigma::SetMsg(msg, key);
	Encode();
}

void Prime::SetCodedMsg(string msg, int key)
{
	codeMsg = msg;
	this->key = key;

	Decode();
	Enigma::Decode();
}

void Prime::Encode()
{

	//make an array of prime numbers
	//within 32-126
	int prime[19]={37, 41, 43, 47,
				  53, 59, 61, 67,
				  71, 73, 79, 83,
				  89, 97, 101, 103,
				  107, 109, 113};

	int pKy[15] ={2, 3, 5, 7, 11,
				  13, 17, 19, 23, 29,
				  31, 37, 41, 43, 47};
		          
	
	for(unsigned int i = 0; i < codeMsg.size(); i++)
	{
		int index = 0;
		string conv = "";
		bool bPrime = false;
		bool bkyPr = false;		//true if key prime
		bool bkyEv = false;   //true if key even
		int stringPlace = i;

		//Checks to see if it is a prime 
		//number 
		for(int n = 0; n < 19; n++)
		{
			if(codeMsg.at(i) == prime[n])
			{
				index = n;
				bPrime = true;
				continue;
			}

		}

		//If ascii value is prime perform
		//Prime Shift Encoding Scheme
		//if not do nothing to number.
		if(bPrime)
		{
			//check to see if key is prime
			for(int i = 0; i < 15; i++)
			{
				if(key == pKy[i])
				{
					bkyPr = true;
				}

			}

			//check to see if key even
			if(key % 2 == 0)
			{
				bkyEv = true;
			}
			else
			{
				bkyEv = false;
			}

			//if key is prime shift index up 1
			if(bkyPr == true)
			{
				if(index == 18)
				{
					index = 0;
				}
				else 
				{
					index ++;
				}
			}
			//if key is even shift index up 2
			else if(bkyEv == true)
			{
				if(index + 2 > 18)
				{
					index += 2;
					index -= 19;
				}
				else 
				{
					index += 2;
				}
			}
			//else shift index up 3
			else 
			{
				if(index + 3 > 18)
				{
					index +=3;
					index -=19;
				}
				else
				{
					index +=3;
				}
			}
			conv = prime[index];
			codeMsg.replace(stringPlace, 1, conv);
		}
	}
}

void Prime::Decode()
{
	//make an array of prime numbers
	//within 32-126
	int prime[19]={37, 41, 43, 47,
				  53, 59, 61, 67,
				  71, 73, 79, 83,
				  89, 97, 101, 103,
				  107, 109, 113};

	int pKy[15] ={2, 3, 5, 7, 11,
				  13, 17, 19, 23, 29,
				  31, 37, 41, 43, 47};
		          
	
	for(unsigned int i = 0; i < codeMsg.size(); i++)
	{
		int index = 0;
		string conv = "";
		bool bPrime = false;
		bool bkyPr = false;		//true if key prime
		bool bkyEv = false;   //true if key even
		int stringPlace = i;

		//Checks to see if it is a prime 
		//number 
		for(int n = 0; n < 19; n++)
		{
			if(codeMsg.at(i) == prime[n])
			{
				index = n;
				bPrime = true;
				continue;
			}
		}

		if(bPrime)
		{
			//check to see if key is prime
			for(int i = 0; i < 15; i++)
			{
				if(key == pKy[i])
				{
					bkyPr = true;
					continue;
				}

			}

			//check to see if key even
			if(key % 2 == 0)
			{
				bkyEv = true;
			}
			else
			{
				bkyEv = false;
			}
			//if key is prime shift index dwn 1
			if(bkyPr == true)
			{
				if(index == 0)
				{
					index = 18;
				}
				else 
				{
					index--;
				}
			}
			//if key is even shift index up 2
			else if(bkyEv == true)
			{
				if(index -2 < 0)
				{
					index += 19;
					index -=2;
				}
				else 
				{
					index -=2;
				}
			}
			//else shift index up 3
			else 
			{
				if(index -3 < 0)
				{
					index += 19;
					index -=3;
				}
				else
				{
					index -=3;
				}
			}
			conv = prime[index];
			codeMsg.replace(stringPlace, 1, conv);
		}

	}

}