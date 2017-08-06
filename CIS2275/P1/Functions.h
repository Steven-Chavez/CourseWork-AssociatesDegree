//Steven Chavez
//schavez256@yahoo.com
//Functions.h

using namespace std;


void CourseHeader();

void AskForNameAndShape(string &rName, int &rShape);

void AskForPaintInfo(int &rCoats, int &rCovarage, 
					 string &rCeiling);

//Asks for Rectangle dimensions
void AskForDimensions(double *pW, double *pL, double *pH, 
					  int *pPercent);

//Asks for Circular dimensions
void AskForDimensions(double *pR, double *pH, int *pPercent);

//Calculates dimensions for circle
int HowManyGallons(double r, double h, string ceiling, int coats, 
				   int covarage, int percent, double *pWallArea,
				   double *pCeilArea, double *pAmount, 
				   double *pTotal);

//Calculates dimesndions for rectangle
int HowManyGallons(double w, double l, double h, 
				   string ceiling, 
				   int coats, int covarage, int percent, 
				   double *pWallArea, double *pCeilArea,
				   double *pAmount, double *pTotal);

//Made a function for display because I didn't want to
//crowd up main
void DisplayToUser(double r, double w, double l, double h, string ceiling, 
				   int coats, int covarage, int percent, 
				   double wallArea, double ceilArea, string name,
				   double amount, int shape, int numGal, double total);

//WriteReport
bool WriteReport(double r, double w, double l, double h, string ceiling, 
				   int coats, int covarage, int percent, 
				   double wallArea, double ceilArea, string name,
				   double amount, int shape, int numGal, double total,
				   string &rFileName);