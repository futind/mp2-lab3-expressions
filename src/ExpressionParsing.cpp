#include "ExpressionParsing.h"

StringCalc::StringCalc(string s)
{
	Exp = s;
	Length = Exp.length();
	string temp;
	for (int i = 0; i < Length; i++) {
		if ((Exp[i] == '(') || (Exp[i] == ')') || (Exp[i] == '*') || (Exp[i] == '+') || (Exp[i] == '-') || (Exp[i] == '/')) {
			temp.clear();
			temp.push_back(Exp[i]);
			Lexems.Push(temp);
			TempL.Push(temp);
			continue;
		}

		if ((Exp[i] < '0') || (Exp[i] > '9')) continue;

		int j = 0;
		if (((Exp[i + j] >= '0') && (Exp[i + j] <= '9')) || (Exp[i + j] == '.')) {
			temp.clear();
			while (((Exp[i + j] >= '0') && (Exp[i + j] <= '9')) || (Exp[i + j] == '.')) {
				temp.push_back(Exp[i + j]);
				j++;
			}
			Lexems.Push(temp);
			TempL.Push(temp);
		}
		i += j-1;
	}
}

void StringCalc::CheckExpression()
{
	//Queue<string> TempL(Lexems);
	int OpenBracket = 0;
	int CloseBracket = 0;
	for (int i = 0; i < Length; i++) {
		if (Exp[i] == '(') OpenBracket++;
		if (Exp[i] == ')') CloseBracket++;
	}
	if (OpenBracket != CloseBracket) throw -5;

	while (!TempL.isEmpty()) {
		string A = TempL.Pop();
		if (!TempL.isEmpty()) {
			if ((A == "(") && ((TempL.Top() == "+") || (TempL.Top() == "-") || (TempL.Top() == "*") || (TempL.Top() == "/")))
			{
				throw - 1;
			}
			if (((A == "+") || (A == "-") || (A == "*") || (A == "/")) && ((TempL.Top() == "+") || (TempL.Top() == "-") || (TempL.Top() == "*") || (TempL.Top() == "/")))
			{
				throw - 2;
			}
			if (((A == "+") || (A == "-") || (A == "*") || (A == "/")) && (TempL.Top() == ")"))
			{
				throw - 3;
			}
			if (((A[0] >= '0') && (A[0] <= '9')) && ((TempL.Top()[0] >= '0') && (TempL.Top()[0] <= '9')))
			{
				throw - 4;
			}
		}
	}
}

int StringCalc::getPriority(char op)
{
	if ((op == '+') || (op == '-')) return 1;
	if ((op == '*') || (op == '/')) return 2;
	return 0;
}

void StringCalc::Operate()
{
	char op = Operations.Pop();
	double Right = Operands.Pop();
	double Left = Operands.Pop();
	switch (op) {
	case '+':
		Operands.Push(Left + Right);
		break;
	case '-':
		Operands.Push(Left - Right);
		break;
	case '*':
		Operands.Push(Left * Right);
		break;
	case '/':
		if (Right == 0) throw -6;
		Operands.Push(Left / Right);
		break;
	default:
		break;
	}
}

double StringCalc::Answer() 
{
	//Lexems.Show();
	while (!(Lexems.isEmpty())) {
		if (Lexems.Top() == "(") { Operations.Push(Lexems.Pop()[0]); }
		if ((Lexems.Top()[0] == '+') || (Lexems.Top()[0] == '-') || (Lexems.Top()[0] == '*') || (Lexems.Top()[0] == '/')) {
			if (Operations.isEmpty()) { Operations.Push(Lexems.Pop()[0]); }
			else if (getPriority(Lexems.Top()[0]) > getPriority(Operations.Top())) { Operations.Push(Lexems.Pop()[0]); }
			else
			{
					while (((!Operations.isEmpty()) && (!Lexems.isEmpty())) && (getPriority(Operations.Top()) >= getPriority(Lexems.Top()[0]))) {
						Operate();
						//Operations.Push(Lexems.Pop()[0]);
					}
			}
		}
		if (Lexems.Top()[0] == ')') {
			Lexems.Pop();
			while (Operations.Top() != '(') {
				//while (getPriority(Operations.Top()) >= getPriority(Lexems.Top()[0])) {
				Operate();
				//}
			}
			Operations.Pop();
		}
		else {
			if ((Lexems.Top()[0] >= '0') && (Lexems.Top()[0] <= '9')) {
				Operands.Push(atof(Lexems.Pop().c_str()));
			}
		}
	}
	while (!Operations.isEmpty()) {
		Operate();
	}
	return Operands.Pop();
}

