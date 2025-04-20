# **Calendar Calculator**
Inspired by Unix ```cal``` utility

This Calendar Calculator is a simple (to use not make) C++ program that prints the calendar for a specified year. The program displays each month of the year with the correct number of days and the appropriate formatting for the days of the week.
## **Features**

* Prints the full calendar for any given year.

* Displays each month with the correct number of days.

* Accounts for leap years in February.

* Nicely formatted output for easy readability.
## **Getting Started**
### **Prerequisites**
* Any C++ compiler (eg., [GCC](gcc.gnu.org), [Clang](clang.llvm.org), or [MSVS](visualstudio.microsoft.com))
### **Installation**
1. Use the following command in your terminal or command prompt:

```bash
git clone https://github.com/ToodlesMrPoodle/Calendar-Calculator.git
cd calendar-calculator
```
2. Compile the program:
```bash
g++ -o calendar main.cpp -std=c++17
```

### **Usage**
Run the executable and enter the year when prompted:
```
./calendar
Enter the year: 2025
```
**Example Output:**
```
 	January 2025
 Su Mo Tu We Th Fr Sa
           1  2  3  4
  5  6  7  8  9 10 11
 12 13 14 15 16 17 18
 19 20 21 22 23 24 25
 26 27 28 29 30 31

 	February 2025
 Su Mo Tu We Th Fr Sa
                    1
  2  3  4  5  6  7  8
  9 10 11 12 13 14 15
 16 17 18 19 20 21 22
 23 24 25 26 27 28
```

### **How It Works**
The program uses:
* **Zeller's Congruence:** To calculate the starting weekday of each month
* **Leap Year Logic:** ```(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)``` (code line 86)
## **Contributing**
If you find any issues or have suggestions for improvements, feel free to open an issue or submit a pull request.
