#include <iostream>
#include <cmath>

using namespace std;

int main() {
    cout << "The Future Value Calculator\n\n";

    char choice = 'y';
    while (choice == 'y' || choice == 'Y') {
        double monthly_investment;
        cout << "Enter monthly investment:   ";
        cin >> monthly_investment;

        double yearly_rate;
        cout << "Enter yearly interest rate: ";
        cin >> yearly_rate;

        int years;
        cout << "Enter number of years:      ";
        cin >> years;

		// calculate monthly interest rate
		double monthly_rate = pow(
			(1 + yearly_rate / 100),
			(1.0 / 12.0));
		monthly_rate = round(monthly_rate * 10000) / 10000;

		// convert years to months
		int months = years * 12;

		// calculate future value
        double future_value = 0;
        for (int i = 1; i <= months; i++) {
            future_value = (future_value + monthly_investment) 
				* monthly_rate;
        }

        // round to 2 decimal places and display
        future_value = round(future_value * 100) / 100;
        cout << "Future value:               " << future_value << "\n\n";

        // see if the user wants to continue
        cout << "Continue? (y/n): ";
        cin >> choice;
        cout << endl;
    }
    cout << "Bye! ";
}