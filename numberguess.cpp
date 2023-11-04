#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

int main() {
	HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    cout << "----------------------------------------------------------------------------------------------" << endl;
    cout << "                           WELCOME TO NUMBER GUESSING GAME                                     " << endl;
    cout << "----------------------------------------------------------------------------------------------" << endl;
    cout << "Starting game in 3 seconds..." << endl;
    
    
    string name;
    //input name
    cout << "Please! Enter your name: ";
    cin >> name;
    char input=' ';
    int variable;
    
    //difer random numbers
    srand(time(0));
    
	cout<<endl;
	cout<<endl;
	
	//greetings
    cout <<"Hello "<< name << "! You have three attempts to guess the number between 1 to 10." << endl;
    cout << endl;
    cout<<"LETS PLAY!"<<endl;
    cout << endl;
    
    int inputuser; 

    do {
        variable = rand() % 10 + 1;
		
		//three attempts will be given
        int attempts; 

        for (attempts = 0; attempts < 3; attempts++) {
        	
        	//input validation
        	 while (true) {
                cout << "Enter your number between 1 to 10: ";
                cin >> inputuser;
                if (inputuser >= 1 && inputuser <= 10) {
                    break; // Exit the loop if valid input is provided
                } else {
                    cout << "Invalid input! Please enter a number between 1 and 10." << endl;
                }
            }
		//user guessed first attempt
        if (attempts == 0) {
            if (inputuser == variable) {
            	SetConsoleTextAttribute(h,9);
                cout << "+++You are extraordinary+++"<<endl;
            }
        }
		//conditions for guessed too low,high or right
        if (inputuser == variable) {
        	SetConsoleTextAttribute(h,9);
            cout << "Congratulations, you guessed right!  :)" << endl;
            SetConsoleTextAttribute(h,15);
            cout << "----------------------------------------------------------------------------------------------" << endl;
            break;
        } else if (inputuser < variable) {
            cout << "Your guess is too low." << endl;
        } else {
            cout << "Your guess is too high." << endl;
        }
		//last attempt condition
        if (attempts == 2) {
            if (inputuser != variable) {
            	SetConsoleTextAttribute(h,4);
            	cout<<"GAME OVER"<<endl;
                cout << "OOPS! You have lost the game!  :(" << endl;
                SetConsoleTextAttribute(h,15);
                cout << "----------------------------------------------------------------------------------------------" << endl;
            }
        }
    }
    cout << endl;
    //correct no
    cout << "The correct number was " << variable << endl;
    
    //again or not 
    cout << "Would you like to try again (Y/N)? ";
    cin >> input;
    } while (input == 'Y' || input == 'y');

	cout << "Goodbye!" << name << endl;

return 0;
}
