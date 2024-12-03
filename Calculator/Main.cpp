#include <iostream>
#include "Calculator.h";
#include <stdexcept>
using std::cout;
using std::cin;

const set<char> validOperators = { '+', '-', '*', '/', '%', 'q' }; // Set of valid operators
char selectedOperator = '+';
double firstNumber = 0;
double secondNumber = 0;

bool isOperatorValid() {
	if (validOperators.find(selectedOperator) == validOperators.end()) {
		cout << "\nInvalid operator. Enter a valid operator: ( +, -, *, /, % or 'q' to quit/end): ";
		return false;
	}
	return true;
}

int main() {
	Calculator calc;
	calc.displayCalculatorOptions();
	while (true)
	{
		try {
			cout << "\nEnter your chosen operation: ";
			

			while (!(cin >> selectedOperator) || !isOperatorValid()) {
				cin.clear();
				cin.ignore(std::numeric_limits<int>::max(), '\n');
			}

			if (selectedOperator == 'q') {
				break;
			}

			cout << "\nEnter your first number: ";
			while (!(cin >> firstNumber)) {
				cout << "Invalid input. Enter a valid number: ";
				cin.clear();
				cin.ignore(std::numeric_limits<int>::max(), '\n');
			}

			cout << "\nEnter your second number: ";
			while (!(cin >> secondNumber)) {
				cout << "Invalid input. Enter a valid number: ";
				cin.clear();
				cin.ignore(std::numeric_limits<int>::max(), '\n');
			}

			double result = calc.calculate(selectedOperator, firstNumber, secondNumber);
			std::cout << "\nResult: " << result << '\n';
		}catch (const std::exception& e) {
			std::cout << "\nError: " << e.what() << '\n';
		}
	}

	std::cout << "\nCalculator closed. Goodbye!\n";
	return 0;
}