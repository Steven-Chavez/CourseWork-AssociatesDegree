//Steven Chavez
//schavez256@yahoo.com
//Functions.h

using namespace std;

void WriteHeader();

void AskFishShower(vector<string> &rType, int *pIndex);

void CalcPondVol(int *pGal);

void WriteInfo(string showerType, int gallons);

//overloaded function
void WriteInfo(string showerType, vector<string> &rType,
			vector<int> &rRecommendations, int gallons);

void FillVectors(vector<string> &rType, vector<int> 
				 &rMinGal, vector<int> &rMaxGal);

bool VallidateFishShower(int index, double pondVol,
			vector<int> &rMinGal, vector<int>
			&rMaxGal, vector<int> &rRecommendations);
