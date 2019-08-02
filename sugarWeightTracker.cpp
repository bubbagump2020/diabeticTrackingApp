#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

void showDate();
void nDate();
void oDate();

int main()
{

	const int NDATE = 1,
			CONT = 2,
			QUIT = 3;

	int choice;
	
	do
	{

		showDate();
		cin >> choice;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << endl;

		while (choice < NDATE || choice > QUIT)
		{
			cout << "Don't fat finger the numbers, try again\n";
			cin >> choice;
		}
		if (choice != QUIT)
		{
			switch (choice)
			{
			case NDATE:
				nDate();
				break;

			case CONT:
				oDate();
				break;
			}
		}
	} 
	while (choice != QUIT);	
	system("pause");
	return 0;
}
void showDate()
{

	cout << "This is a program to track your diabetty vitals.\n";
	cout << endl;

	cout << "Please select an option below: \n"
			"\t1. New Date\n"
			"\t2. Continuation\n"
			"\t3. Terminate Program\n";

}
void nDate()
{
	
	ifstream inFile;
	ofstream outFile;

	string cDate, nTime, sugars, bpress, weight;
	char cTime;

	inFile.open("Sugars & Weight.txt");
	outFile.open("Sugars & Weight.out", ios::app);
	
	cout << "Enter Date: ";
	getline(cin, cDate);

	inFile >> cDate;

	cout << "Do you have the time when the measurements were taken? (y/n) \n";
	cin >> cTime;

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	if (cTime == 'y')
	{

		cout << "At what time where the measurements taken? \n";
		getline(cin, nTime);

		cout << "Enter your sugars: \n";
		cin >> sugars;
		cout << "Enter your blood pressure: \n";
		cin >> bpress;
		cout << "Enter your weight. Don't be shy!: \n";
		cin >> weight;

		cout << endl;

		inFile >> nTime;
		inFile >> sugars >> weight >> bpress;
		outFile << setw(10) << "Date" << setw(25) << "Time" << setw(35) << "B. Press."
			<< setw(30) << "Sugars" << setw(30) << "Weight\n";
		outFile << setw(10) << cDate << setw(25) << nTime << setw(35) << bpress
			<< setw(30) << sugars << setw(28) << weight << endl;

		inFile.close();
		outFile.close();
	}
	else if (cTime == 'n')
	{

		cout << "Enter your sugars: \n";
		cin >> sugars;
		cout << "Enter your blood pressure: \n";
		cin >> bpress;
		cout << "Enter your weight. Don't be shy!: \n";
		cin >> weight;

		cout << endl;

		inFile >> sugars >> weight >> bpress;

		outFile << setw(10) << "Date"<< setw(25) << "Time" << setw(35) << "B. Press."
			<< setw(30) << "Sugars" << setw(30) << "Weight\n";
		outFile << setw(10) << cDate << setw(25) << "   " << setw(35) << bpress
			<< setw(30) << sugars << setw(28) << weight << endl;

		inFile.close();
		outFile.close();
	}
	else
		cout << "Invalid response, try again\n\n";

}
void oDate()
{

	ifstream inFile;
	ofstream outFile;

	string time, sugars, weight, bpress;

	char tChoice;

	inFile.open("Sugars & Weight.txt");
	outFile.open("Sugars & Weight.out", ios::app);

	cout << "Enter the time when taken: \n";
	getline(cin, time);

	cout << "Enter sugars: \n";
	cin >> sugars;
	cout << "Enter blood pressure: \n";
	cin >> bpress;
	cout << "Enter weight (Don't be shy!): \n";
	cin >> weight;

	cout << endl;

	inFile >> time;
	inFile >> sugars >> bpress >> weight;

	outFile << setw(10) << "  " << setw(25) << time << setw(35) << bpress
		<< setw(30) << sugars << setw(28) << weight << endl;

	outFile << endl;

	inFile.close();
	outFile.close();

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

}