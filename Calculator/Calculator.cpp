#include <iostream>
#include "Calculator.h"
#include <stdexcept>

using std::cout;

void Calculator::displayCalculatorOptions() {
	cout << "Welcome to Kevin's Basic Calculator ^_^ \n";

	cout << "\nChoose the operation with their corresponding symbol you'd like to use:\n";
	cout << "\t'+' = Addition, '-' = Subtraction, '/' = Division, '*' = Multiplication. \n";
}

double Calculator::add(double num1, double num2) {
	return num1 + num2;
};
double Calculator::substract(double num1, double num2) {
	return num1 - num2;
};
double Calculator::multiply(double num1, double num2) {
	return num1 * num2;
};
double Calculator::divide(double num1, double num2) {
	if (num2 == 0) {
		throw std::runtime_error("Division by zero!");
	}
	return num1 / num2;
};

double Calculator::calculate(char selectedOperator, double firstNumber, double secondNumber) {
	double result = 0.0;

	switch (selectedOperator)
	{
	case '+':
		result = add(firstNumber, secondNumber);
		break;
	case '-':
		result = substract(firstNumber, secondNumber);
		break;
	case '*':
		result = multiply(firstNumber, secondNumber);
		break;
	case '/':
		result = divide(firstNumber, secondNumber);
		break;
	default:
		throw std::invalid_argument("Invalid operation!");
	}
	return result;
}
