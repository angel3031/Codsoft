#include <iostream>
using namespace std;

int main() {
    double num1, num2;
    char op;

    cout << "Welcome to the Simple Calculator!" << endl;
    cout << "You can perform: Addition (+), Subtraction (-), Multiplication (*), and Division (/)" << endl;

    cout << "\nPlease enter the first number: ";
    cin >> num1;

    cout << "Now enter an operator (+, -, *, /): ";
    cin >> op;

    cout << "Great! Now enter the second number: ";
    cin >> num2;

    cout << "\n Calculating your result...\n";

    switch(op) {
        case '+':
            cout << "The result of " << num1 << " + " << num2 << " is: " << (num1 + num2) << endl;
            break;
        case '-':
            cout <<  "The result of " << num1 << " - " << num2 << " is: " << (num1 - num2) << endl;
            break;
        case '*':
            cout << " The result of " << num1 << " * " << num2 << " is: " << (num1 * num2) << endl;
            break;
        case '/':
            if (num2 != 0)
                cout << " The result of " << num1 << " / " << num2 << " is: " << (num1 / num2) << endl;
            else
                cout << " Oops! You can't divide by zero. Please try again with a different number." << endl;
            break;
        default:
            cout << " Invalid operator entered. Please restart the program and choose from (+, -, *, /)." << endl;
    }

    cout << "\n Thank you for using the calculator. Have a great day!" << endl;
    return 0;
}
