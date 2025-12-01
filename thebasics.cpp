#include <iostream> /* header for inputs and outputs */
using namespace std; /* why use many word when few word do trick? */
#include <ctime>
#include <chrono> 
#include <iomanip>
int main() {
    cout << "Hello World!\n"; // output to console
    cout << "Is Josh Okay?\nWhy don't you ask him?\n";
    cout << "Most humans have " << 5+5 << " toes.\n";

    int age = 26;
    // I want to get how many days until I turn 27
    const chrono::system_clock::time_point now = chrono::system_clock::now();
    const time_t t_c = std::chrono::system_clock::to_time_t(now);

    // Converting the time into local time structure using std::tm
    tm tm_struct = *std::localtime(&t_c);
    double dayOfYear = tm_struct.tm_yday;
    double yearPercentage = (dayOfYear/365.0)*100;

    cout << "It is the " << dayOfYear << " day of the year" << endl;
    cout << "We are " << fixed << setprecision(0)<< yearPercentage << "% through 2025!" << endl;
    return 0;
}
