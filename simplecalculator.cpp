#include <iostream>
#include <limits>
#include <windows.h>

using namespace std;

int main() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    char continueOperation;

    do {
        cout << "----------------------------------------------------------------------------------------------" << endl;
        cout << "                               SIMPLE CALCULATOR                                              " << endl;
        cout << "----------------------------------------------------------------------------------------------" << endl;
        int a, b;

        cout << "Enter number 1: ";
        while (!(cin >> a)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            SetConsoleTextAttribute(h, 4);
            cout << "Invalid input. Please enter a numeric value for number 1: ";
            SetConsoleTextAttribute(h, 15);
        }

        cout << "Enter number 2: ";
        while (!(cin >> b)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            SetConsoleTextAttribute(h, 4);
            cout << "Invalid input. Please enter a numeric value for number 2: ";
            SetConsoleTextAttribute(h, 15);
        }

        cout << endl;
        int operation;
        cout << "Please select an operation:" << endl;
        cout << "1. Addition (+)" << endl;
        cout << "2. Subtraction (-)" << endl;
        cout << "3. Multiplication (*)" << endl;
        cout << "4. Division (/)" << endl;
        cout << "5. Modulus (%)" << endl;
        cout << "Enter the number corresponding to your choice: ";

        if (!(cin >> operation)) {
            SetConsoleTextAttribute(h, 4);
            cout << "Invalid input. Please enter a valid operation number." << endl;
            SetConsoleTextAttribute(h, 15);
            return 1; // Exit with an error code
        }

        cout << endl;
        SetConsoleTextAttribute(h, 15); // Reset text color

        switch (operation) {
            case 1:
                cout << "Sum = " << a + b << endl;
                break;
            case 2:
                cout << "Difference = " << a - b << endl;
                break;
            case 3:
                cout << "Product = " << a * b << endl;
                break;
            case 4:
                if (b == 0) {
                    SetConsoleTextAttribute(h, 4);
                    cout << "Invalid input: Division by zero." << endl;
                    SetConsoleTextAttribute(h, 15);
                } else {
                    cout << "Division = " << static_cast<double>(a) / b << endl;
                }
                break;
            case 5:
                if (b == 0) {
                    SetConsoleTextAttribute(h, 4);
                    cout << "Invalid input: Modulus by zero." << endl;
                    SetConsoleTextAttribute(h, 15);
                } else {
                    cout << "Modulus = " << a % b << endl;
                }
                break;
            default:
                SetConsoleTextAttribute(h, 4);
                cout << "Invalid input: Unknown operation." << endl;
                SetConsoleTextAttribute(h, 15);
                break;
        }

        cout << "Do you want to perform another operation? (y/n): ";
        cin >> continueOperation;
        cout << endl;

    } while (continueOperation == 'y' || continueOperation == 'Y');

    return 0;
}

