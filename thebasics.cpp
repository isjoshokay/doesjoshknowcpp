#include <iostream> /* header for inputs and outputs (cin/cout) */
using namespace std; /* why use many word when few word do trick? */
#include <ctime>
#include <chrono> // both of these ^ are for time vars
#include <iomanip> // for manipulating outputs (decimals)
int main() {
    cout << "Hello World!\n"; // output to console
    cout << "Is Josh Okay?...Why don't you ask him? ";
    cout << "Most humans have " << 5+5 << " toes." << endl;

    int age = 26;
    cout << "Josh is " << age << " years old at the time of writing! ";
    
    const chrono::system_clock::time_point now = chrono::system_clock::now();
    const time_t t_c = std::chrono::system_clock::to_time_t(now);

    // Converting the time into local time structure using tm
    tm tm_struct = *std::localtime(&t_c);
    double dayOfYear = tm_struct.tm_yday, yearPercentage = (dayOfYear/365.0)*100;
    const int year = tm_struct.tm_year;
    
    int userAge;
    cout << "It is the " << dayOfYear << "th day of the year" << endl;
    cout << "We are " << fixed << setprecision(0)<< yearPercentage << "% through 2025!" << endl;
    cout << "But the way...how old are you? \n";
    cin >> userAge;
    cout << "Oh! Since you're " << userAge << " years old, you must have been born in '" << year - userAge << " (give or take)" << endl;
    return 0;
}
