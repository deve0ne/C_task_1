#include <iostream>

using namespace std;

double inputNum(const string &messageToUser) {
    cout << messageToUser << endl;

    double num;
    cin >> num;

    return num;
}

char inputOperation() {
    char operation = 0;
    string allowedOperators = "+ - * /";
    bool isOperationCorrect = false;

    while (!isOperationCorrect) {
        cout << "Enter one of this operations (" << allowedOperators << ")" << endl;
        cin >> operation;

        if (allowedOperators.find(operation) == string::npos)
            cout << "You entered incorrect operation. Try again\n" << endl;
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
    double num1 = inputNum("Enter first num:");
    double num2 = inputNum("Enter second num:");
    char operation = inputOperation();


    try {
        double result = calculate(num1, num2, operation);
        cout << num1 << " " << operation <<  " " << num2 << " = " << result << endl;
    } catch (invalid_argument &e) {
        cout << e.what() << endl;
    }

    return 0;
}
