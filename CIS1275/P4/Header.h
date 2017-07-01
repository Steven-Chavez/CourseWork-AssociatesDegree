//Steven Chavez
//schavez256@yahoo.com
//Header.h

using namespace std;

//Function Declarations (prototypes)
void WriteHeader();
double AskPitcherDiameter();
double AskPitcherHeight();
double AskPebbleDiameter();
double AskBeakLength();
int CalcPebbles(double diameterPitcher, double heightPitcher, 
				double diameterMarbles, double beakLength);
void ShowResults(double diameterPitcher, double heightPitcher, 
				 double diameterMarbles, double beakLength, 
				 int numPebbles);