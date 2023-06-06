#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// To stop error code C3861 because I'm a dumbass
string getMonthName(int month);
int getNumberOfDays(int month, int year);

int main() {
    // Get the year from the user
    int year;
    cout << "Enter the year: ";
    cin >> year;

    // Print the calendar for the specified year
    for (int month = 1; month <= 12; month++) {
        // Get the name of the month
        string monthName = getMonthName(month);

        // Get the number of days in the month
        int numberOfDays = getNumberOfDays(month, year);

        // Print the header for the month
        cout << endl << monthName << " " << year << endl;
        cout << " Su Mo Tu We Th Fr Sa" << endl;

        // Print the days of the month
        int day = 0;
        while (day < numberOfDays) {
            cout << setw(3) << ++day;
            if (day % 7 == 0) {
                cout << endl;
            }
        }
    }

    return 0;
}

// Function to get the name of the month
string getMonthName(int month) {
    static const string monthNames[] = { "     January", "     February", "     March", "     April", "     May", "     June", "     July", "     August", "     September", "     October", "     November", "     December" };
    return monthNames[month - 1];
}

// Function to get the number of days in a month
int getNumberOfDays(int month, int year) {
    if (month == 2) {
        return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) ? 29 : 28;
    }
    else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        return 31;
    }
    else {
        return 30;
    }
}
