#pragma once
#include <set>
using namespace std;

class Calculator {
public:
	void displayCalculatorOptions();
	double calculate(char selectedOperator, double firstNumber, double secondNumber);
	double add(double num1, double num2);
	double substract(double num1, double num2);
	double multiply(double num1, double num2);
	double divide(double num1, double num2);

};