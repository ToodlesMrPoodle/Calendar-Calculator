#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Function prototypes
string getMonthName(int month);
int getNumberOfDays(int month, int year);
int getStartingDay(int month, int year);

int main() {
	// Get the year from the user
	int year;
	cout << "Enter the year: ";
	cin >> year;

	// Print the calendar for the specified year
	for (int month = 1; month <= 12; month++) {
    	// Get the name of the month
    	string monthName = getMonthName(month);
    	int numberOfDays = getNumberOfDays(month, year);
    	int startDay = getStartingDay(month, year);

    	// Print the header for the month
    	cout << endl << monthName << " " << year << endl;
    	cout << " Su Mo Tu We Th Fr Sa" << endl;

    	// Print leading spaces for alignment
    	cout << string(startDay * 3, ' ');

    	// Print the days of the month
    	int currentDayOfWeek = startDay;
    	for (int day = 1; day <= numberOfDays; day++) {
        	cout << setw(3) << day;
        	currentDayOfWeek++;

        	// Newline at end of week
        	if (currentDayOfWeek == 7) {
            	cout << endl;
            	currentDayOfWeek = 0;
        	}
    	}

    	// Ensure the next month starts on a new line
    	if (currentDayOfWeek != 0) {
        	cout << endl;
    	}
	}

	return 0;
}

// Function to get the starting weekday of the month (0 = Sunday, 1 = Monday, ..., 6 = Saturday)
int getStartingDay(int month, int year) {
	// Adjust January and February to be months 13 and 14 of the previous year
	if (month < 3) {
    	month += 12;
    	year -= 1;
	}

	int q = 1; // Day 1 of the month
	int m = month;
	int K = year % 100; // Year of the century
	int J = year / 100; // Zero-based century

	// Zeller's Congruence calculation
	int h = (q + (13 * (m + 1)) / 5 + K + K / 4 + J / 4 + 5 * J) % 7;

	// Convert result to 0 = Sunday, 1 = Monday, ..., 6 = Saturday
	int startDay = (h - 1 + 7) % 7;
	return startDay;
}

// Function to get the name of the month (centered formatting)
string getMonthName(int month) {
	static const string monthNames[] = { " 	January", " 	February", " 	March", " 	April",
                                   	"   	May", "  	June", "  	July", " 	August",
                                   	"  September", "	October", "   November", "   December" };
	return monthNames[month - 1];
}

// Function to get the number of days in a month
int getNumberOfDays(int month, int year) {
	if (month == 2) {
    	return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) ? 29 : 28;
	} else if (month == 4 || month == 6 || month == 9 || month == 11) {
    	return 30;
	} else {
    	return 31;
	}
}
