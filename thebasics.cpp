#include <iostream> /* header for inputs and outputs (cin/cout) */
using namespace std; /* why use many word when few word do trick? */
#include <ctime>
#include <chrono> // both of these ^ are for time vars
#include <iomanip> // for manipulating outputs (decimals)
#include <string>
#include <limits>

int define_ordinal(int dayOfYr) {
    string rt_val = to_string(dayOfYr);
    // I want the last digit, which will always be 2 in index
    rt_val = rt_val[2];
    cout << rt_val << " << rt val\n";
    return stoi(rt_val);
}
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
    int dayOfYear = tm_struct.tm_yday;
    double yearPercentage = ((double)dayOfYear/365.0)*100;
    const int year = tm_struct.tm_year + 1900;
    
    int userAge;
    bool validInput = false;
    string cronString;
    int ordinal = define_ordinal(dayOfYear);
    // change the ordinal nomenclature appended to day number depending on the ending value
    if (ordinal > 3 || ordinal == 0){
        cronString = "th";
    } else if (ordinal == 1) {
        cronString = "st";
    } else if (ordinal == 2) {
        cronString = "nd";
    } else if (ordinal == 3) {
        cronString = "rd";
    }

    // define_ordinal(dayOfYear);
    cout << "It is the " << dayOfYear << cronString << " day of the year" << endl;
    cout << "We are " << fixed << setprecision(0)<< yearPercentage << "% through " << year <<"!" << endl;
    cout << "But the way...how old are you? \n";
    
    while (!validInput) {
    if (!(cin >> userAge)) {
        // Input was not a number
        cin.clear(); // clear error flags
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // throw away bad input
        cout << "uh...can you enter a real number...please?\n";
        continue;
    }

    if (userAge <= 0 || userAge >= 150) {
        cout << "You are not real. Let's be serious here.\n";
    } else {
        validInput = true;
    }
}
    cout << "Oh! Since you're " << userAge << " years old, you must have been born in " << year - userAge << " approximately" << endl;
    // of course I know to increment before giving the goods to the output! 
    cout << "Soon you'll be " << ++userAge << ". Exciting!" << endl;
    string userName;
    validInput = false;

    while (!validInput){
        cout << "What's your name by the way?\n";
        cin >> userName; // alternatively use getline(cin, userName) to get the full line including spaces...but I want first names only
        bool lettersOnly = true;
        for (char c : userName) {
            if (!isalpha(c) && c != ' ' && c != '-') {
                lettersOnly = false;
                break;
            }
        }
        if (!lettersOnly) {
            cout << "uh...that doesn't look like a real name. ";
        } else {
            validInput = true;
        }
    }
    
    cout << "Well, nice to meet you, " << userName << endl;
    if (userName.length() > 1) {
        cout << "Your name is " << userName.length() << " characters long. Interesting." << endl;
        cout << "The second letter of your name is " << userName[1] << endl;
    }
    

    return 0;
}
