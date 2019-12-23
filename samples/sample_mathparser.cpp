#include "ExpressionParsing.h"
#include <conio.h>

int main() {

	string Expression;
	getline(cin, Expression);
	StringCalc Calculation(Expression);
	try {
		Calculation.CheckExpression();
		double a = Calculation.Answer();
		cout << endl;
		cout << "The answer is " << a;
	}
	catch (int error) {
		if (error == -1) {
			cout << "INCORRECT INPUT (OPERATOR AFTER AN OPENING BRACKET)";
			return -1;
		}
		if (error == -2) {
			cout << "INCORRECT INPUT (OPERATOR AFTER AN OPERATOR)";
			return -2;
		}
		if (error == -3) {
			cout << "INCORRECT INPUT (OPERATOR BEFORE A CLOSING BRACKET)";
			return -3;
		}
		if (error == -4) {
			cout << "INCORRECT INPUT (OPERAND AFTER AN OPERAND (UNKNOWN OPERATION, PROBABLY)";
			return -4;
		}
		if (error == -5) {
			cout << "INCORRECT INPUT (BRACKETS NUMBERS ARE NOT EQUAL)";
			return -5;
		}
		if (error == -6) {
			cout << "INCORRECT INPUT (DIVISION ON ZERO)";
			return -6;
		}
		if (error == -100) {
			cout << "ERROR: POPPING FROM AN EMPTY STACK/QUEUE";
			return -100;
		}
	}
	_getch();

	return 0;
}