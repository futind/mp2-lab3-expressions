#pragma once
#include <iostream>
#include <string>
#include "stack.h"
#include "queue.h"

using namespace std;

class StringCalc {
	string Exp;
	int Length;
	Queue<string> TempL;
	Queue<string> Lexems;
	Stack<double> Operands;
	Stack<char> Operations;

	int getPriority(char op);
	bool isOperation();
	void Operate();
public:
	StringCalc(string s);
	void CheckExpression();
	double Answer();
};