/*Saleh Almata
C++ Fall 2019
Date:10,5,2019
Lab dessricptio: Program to output a Temperature for 24 hour
*/

#include <iostream>;
#include <math.h>
#include<fstream>
#include<iomanip>
using namespace std;

void printPlusTemp(int starCount, float Tempvalue)//function for positive stars
{
	int i;
	cout << setw(5) << Tempvalue << setw(20) << "|";//this code will do 5 spaces then will output the tempvlue then will do 20 space and will outpun the |
	for (i = 0; i < starCount; i++) {//loob to print the positive stars
		cout << "*";
	}
	cout << endl;
}

void printMinusTemp(int starCount, float Tempvalue)//function to print stars for Negative value
{
	int i;
	cout << setw(5) << Tempvalue << setw(20 + (starCount));/* The total number of spaces i have is 20. for Negative Temp i subtract the number of
														   stars from the number of spaces. for example, if have 3 stars to print i will print 17 spaces then 3 stars then the bar
														   */
	for (i = 0; i > starCount; i--) {//loob to print the Negative stars
		cout << "*";
	}
	cout << "|" << endl;
}

int main()
{
	//variable declaration
	string inputFileName = "TempFile.dat";
	ifstream inFile;
	float Tempvalue;
	int starCount, counter, i;

	inFile.open(inputFileName);

	if (!inFile)  // a call to see if the file will be open
	{
		cout << "invalid file";
		return 1;
	}
	cout << "Temperatures for 24 hour:" << endl;
	cout << "         -30            0           60           90            120          " << endl;

	for (counter = 0; counter < 24; counter++) {// a for loob to read 24 number from a file

		inFile >> Tempvalue;

		if ((Tempvalue < -30) || (Tempvalue > 120)) {// if statement to make sure that the data is in the range 
			cout << "invalid range" << endl;
			continue;// This will make the the program to go back and do the same steps for each data
		}

		starCount = round((Tempvalue / 3));//Stars equation

		if (starCount > 0) {
			printPlusTemp(starCount, Tempvalue);//function call
		}
		else
		{
			printMinusTemp(starCount, Tempvalue);//function call
		}

	}
}