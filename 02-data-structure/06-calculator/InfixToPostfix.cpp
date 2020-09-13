#include <string>
#include "InfixToPostfix.h"
#include "../06-list-base-stack/ListBaseStack.h"

std::string ConvToRPNExp(const std::string& expression)
{
    ListStack<char> stack;
    std::string convertedExp;
	
    for(char c : expression)
    {
    	if(c == ' ')
    	{
            continue;
    	}
    	
        else if('0' <= c && c <= '9')
        {
            convertedExp += c;
        }

    	else
        {
            switch (c)
            {
            case '(':
                stack.push(c);
                break;

            case ')':
                while("Happy")
                {
                    char popOperator = stack.pop();
                    if(popOperator == '(')
                        break;

                    convertedExp += popOperator;
                }
                break;

            case '+' : case '-':
            case '*' : case '/':
                while(!stack.isEmpty() && WhoPrecOp(stack.peek(), c) >= 0)
                    convertedExp += stack.pop();

                stack.push(c);
                break;
            }
        }
    }

    while (!stack.isEmpty())
        convertedExp += stack.pop();

    return convertedExp;
}

int GetOpPrec(char op)
{
	switch(op)
	{
	case '*':
	case '/':
		return 5;

	case '+':
	case '-':
		return 3;

	case '(':
		return 0;
	}

	return -1;
}

int WhoPrecOp(char op1, char op2)
{
	int op1Prec = GetOpPrec(op1);
	int op2Prec = GetOpPrec(op2);

	if (op1Prec > op2Prec)
		return 1;

	else if (op1Prec < op2Prec)
		return -1;

	else
		return 0;
}

int EvalRPNExp(const std::string& expression)
{
    ListStack<int> stack;
    int result = 0;

	for(char c : expression)
	{
        if('0' <= c && c <= '9')
        {
            stack.push(c - '0');
        }

        else
        {
            int num2 = stack.pop();
            int num1 = stack.pop();
        	
	        switch (c)
	        {
            case '+':
                stack.push(num1 + num2);
                break;

            case '-':
                stack.push(num1 - num2);
                break;
	        	
            case '*':
                stack.push(num1 * num2);
                break;
	        	
            case '/':
                stack.push(num1 / num2);
                break;
	        }
        }
	}
    return stack.pop();
}

int Calculate(const std::string& expression)
{
    return EvalRPNExp(ConvToRPNExp(expression));
}

