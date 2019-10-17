//---------------------------------------------------------------------
// Name:Kishan Patel
// Email: kpp5282@psu.edu
// Class: CMPSC 122, Section 2
// Program 4.2 - Stack include file
//
// Description: Contains List and Stack implementations from
// class notes.
// Links: https://www.geeksforgeeks.org/5-different-methods-find-length-string-c/
//---------------------------------------------------------------------
#include "stack.h"
#include <iomanip>
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;
class Stacks
{
private:
	char *str;
	int z;

public:
	Stacks(int maxNumbers)
	{
		str = new char[maxNumbers];
		z = 0;
	}

	int empty()
	{
		return z == 0;
	}

	void push(char value)
	{
		str[z++] = value;
	}

	char pop()
	{
		return str[--z];
	}
};

char* InfixToPostfix(string expression, int length)
{
	int i, j;
	char *postfix;

	Stacks postfixStack(length);
	postfix = (char*) new char (sizeof(char) * length);
	j = 0;

	for (i = 0; i < length; i++)
	{

		if (expression[i] == ')' || expression[i] == '(')
		{
			postfix[j] = postfixStack.pop();
			j++;
		}


		else if ((expression[i] == '+') || (expression[i] == '*') || (expression[i] == '^') || (expression[i] == '-') || (expression[i] == '/'))
		{
			postfixStack.push(expression[i]);
		}


		else if ((expression[i] >= '0') && (expression[i] <= '9'))
		{
			postfix[j] = expression[i];
			j++;
		}
	}

	while(!postfixStack.empty())
	{
		postfix[j] = postfixStack.pop();
		j++;
	}
	
	postfix[j]='\0';
	return postfix;
}

double evaluatePostFix(char* postfix)
{
	int length = strlen(postfix);
	int a, b;

	Stacks postfixStack(length);

	for (int i = 0; i < length; i++)
	{
		if (postfix[i] == '+' || postfix[i] == '^' || postfix[i] == '-' || postfix[i] == '*')
		{
			a = (postfixStack.pop()) - '0';
			b = (postfixStack.pop()) - '0';

			switch(postfix[i])
			{
				case '+': postfixStack.push((a+b) + '0'); break;
				case '-': postfixStack.push((a-b) + '0'); break;
				case '*': postfixStack.push((a*b) + '0'); break;
				case '/': postfixStack.push((a/b) + '0'); break;
				case '^': postfixStack.push((pow(double(a), double(b))) + '0'); break;
			}
		}


		else if ((postfix[i] >= '0') && (postfix[i] <= '9'))
		{
			postfixStack.push(postfix[i]);
		}
	}

	return (postfixStack.pop()) - '0';
}



int main()
{
	double result;
	int length;
	string expression;
	char* postfix;

	cout<<"Enter an infix expression: ";
	getline (cin, expression);
	length = strlen (expression.c_str());
	postfix = (char*)new char(sizeof(char) * length);
	postfix = InfixToPostfix(expression, length);
	cout<< "The equivalent postfix expression of " << expression << " is: " << postfix << " \n";
	result = evaluatePostFix(postfix);
	cout << "Result: " << result << " \n\n";
	return 0;
}

