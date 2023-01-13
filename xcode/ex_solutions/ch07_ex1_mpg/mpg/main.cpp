#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

double calculate_mpg(double miles, double gallons);

void display_file_data();

int main()
{
	// print name of program
	cout << "Miles Per Gallon\n\n";

	// define variables
	double miles;
	double gallons;
	double mpg;

	// print existing file data
	display_file_data();

	char another_entry = 'y';
	while (tolower(another_entry) == 'y') {

		// get miles driven
		miles = 0;
		while (true) {
			cout << "Enter miles driven:        ";
			cin >> miles;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			if (miles <= 0) {
				cout << "Miles driven must be greater than zero. Please try again.\n";
				continue;
			}
			else {
				break;
			}
		}

		// get gallons of gas used
		gallons = 0;
		while (true) {
			cout << "Enter gallons of gas used: ";
			cin >> gallons;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			if (gallons <= 0) {
				cout << "Gallons used must be greater than zero. Please try again.\n";
				continue;
			}
			else {
				break;
			}
		}

		// calculate and display miles per gallon
		mpg = calculate_mpg(miles, gallons);
		cout << "Miles per gallon:          " << mpg << endl << endl;

		// write entry to file
		ofstream outfile;
		outfile.open("trips.txt", ios::app);
		outfile << fixed << setprecision(1);
		outfile << miles << '\t' << gallons << '\n';
		outfile.close();

		// print file data
		display_file_data();

		// see if the user wants to enter more data
		cout << "Get entries for another trip? (y/n): ";
		cin >> another_entry;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << endl;
	}

	cout << "Bye!\n\n";
}

double calculate_mpg(double miles, double gallons) {
	double mpg = miles / gallons;
	mpg = round(mpg * 100) / 100;
	return mpg;
}

void display_file_data() {
    string filename = "trips.txt";

    ifstream infile;
	infile.open(filename);
	if (infile) {
		double miles;
		double gallons;
		double total_miles = 0;
		double total_gallons = 0;
		cout << setw(8) << "Miles" << setw(12) << "Gallons" << setw(12) << "MPG" << endl;
		while (infile >> miles >> gallons) {
			total_miles += miles;
			total_gallons += gallons;
			double mpg = calculate_mpg(miles, gallons);
			cout << fixed << setprecision(1);
			cout << setw(8) << miles << setw(12) << gallons;
			cout << fixed << setprecision(2);
			cout << setw(12) << mpg << endl;
		}
		infile.close();

		double avg_mpg = total_miles / total_gallons;

		cout << fixed << setprecision(2) << showpoint << endl;
		cout << left << setw(15) << "Total miles:"
			<< right << setw(10) << total_miles << endl;
		cout << left << setw(15) << "Total gallons:"
			<< right << setw(10) << total_gallons << endl;
		cout << left << setw(15) << "Average MPG:"
			<< right << setw(10) << avg_mpg << endl;
		cout << endl;
	}
}
