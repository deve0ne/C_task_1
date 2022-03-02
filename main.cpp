#include <iostream>

using namespace std;

double readNum(const string &messageToUser) {
    string userInput;
    double num;
    bool correctInput = false;

    while (!correctInput) {
        try {
            cout << messageToUser << endl;

            cin >> userInput;
            cin.clear();
            cin.ignore(10000,'\n');

            num = stod(userInput);

            correctInput = true;
        } catch (invalid_argument &) {
            cout << "You entered incorrect operation. Try again" << endl;
        }
    }

    return num;
}

char readOperation() {
    char operation = 0;
    string allowedOperators = "+ - * /";
    bool isOperationCorrect = false;

    while (!isOperationCorrect) {
        cout << "Enter one of this operations (" << allowedOperators << ")" << endl;
        cin >> operation;

        if (allowedOperators.find(operation) == string::npos)
            cout << "You entered incorrect operation. Try again" << endl;
        else
            isOperationCorrect = true;
    }

    return operation;
}

double calculate(double num1, double num2, char operation) {
    switch (operation) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            if (num2 == 0)
                throw invalid_argument("Division by zero exception");

            return num1 / num2;
        default:
            return 0;
    }
}

int main() {
    double num1 = readNum("Enter first num:");
    double num2 = readNum("Enter second num:");
    char operation = readOperation();

    try {
        double result = calculate(num1, num2, operation);
        cout << num1 << " " << operation << " " << num2 << " = " << result << endl;
    } catch (invalid_argument &e) {
        cout << e.what() << endl;
    }

    return 0;
}
