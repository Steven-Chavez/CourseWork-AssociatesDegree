//Steven Chavez
//schavez256@yahoo.com
//Header.h

using namespace std;

void ObtainTimeOut(int &rCurHour, int &rCurMin, int &rDay,
	int &rMonth, int &rYear);
void AskTimeIn(int &rArivHour, int &rAriveMin);
bool ValidateTimes(int &rCurHour, int &rCurMin,
	int &rArivHour, int &rArivMin);