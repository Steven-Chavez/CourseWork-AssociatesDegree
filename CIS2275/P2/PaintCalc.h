//Steven Chavez
//schavez256@yahoo.com	
//PaintCalc.h

//file PaintCalc.h
//define the class, PaintCalc

#ifndef _PAINTCALC_H
#define _PAINTCALC_H

#include <string>
using namespace std;

class PaintCalc
{
private:
		double rmH, rmL, rmW, rmR;	//dimensions are in feet
		double exactP;			//exact # of gallons required
		int gallons, paintCov;	//paintCov in gal/sq. ft.
		int numCoats;	//number of coats of paint
		string bCeiling;		//true if painting ceiling
		string desc;		//answer in a sentence
		string name;		//customer name
		string filename;    //report filename
		int type;		//1 = rectangle  2 = circle
		int percentNoPaint;
		bool bFileOk;

		void Calculate();	
		void BuildDesc();	
		void WriteReport();
public:
	   PaintCalc();		//default constructor

	   void SetType(int t);
	   void SetName(string n);
	   void SetRoomDim(double l, double w, double h, int pnp);
	   void SetRoomDim(double rad, double h, int pnp);
	   void SetPaintInfo(int pCov, int coats, string bCeil);

	   double GetExactPaint(){return exactP;}
	   int GetGallons(){return gallons;}
	   string GetDescription(){return desc;}	   
	   string GetFilename(){WriteReport(); return filename;}
	   string WriteHeader();
	   bool IsFileOk(){return bFileOk;}
}; 
#endif
