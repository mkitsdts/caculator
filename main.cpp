#include <bits/stdc++.h>
#define ElementType int

std::stack <ElementType> number1;
std::stack <char> signal1;
std::stack <ElementType> number2;
std::stack <char> signal2;
std::string equation;
long long result;

static void
InPut()
{
	std::cin >> equation;
}

static ElementType
StrToData(char* str, int n)
{
	ElementType temp = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		temp += (int)pow(10, n - 1 - i)*(str[i]-'0');
	}
	return temp;
}

static void
Translate()
{
	int n = 0;
	char str[32] = "\0";
	for (int i = 0; equation[i] != '\0'; i++)
	{
		if (equation[i] == '+' || equation[i] == '-' || equation[i] == '*' || equation[i] == '/')
		{
			signal1.push(equation[i]);
			ElementType j = StrToData(str, n);
			number1.push(j);
			strcpy_s(str, "");
			n = 0;
		}
		else if (equation[i] >= '0' && equation[i] <= '9')
		{
			str[n] = equation[i];
			n = n + 1;
		}
		else if (equation[i] == '=')
		{
			ElementType j = StrToData(str, n);
			number1.push(j);
			strcpy_s(str, "");
			n = 0;
		}
	}
}

static void
Calculate()
{
	while (!signal1.empty())
	{
		if (signal1.top() == '+' || signal1.top() == '-')
		{
			signal2.push(signal1.top());
			number2.push(number1.top());
			signal1.pop();
			number1.pop();
		}
		else if (signal1.top() == '*'||signal1.top()=='X')
		{
			ElementType tmp=number1.top();
			number1.pop();
			number2.push(tmp* number1.top());
			number1.pop();
			signal1.pop();
		}
		else if (signal1.top() == '/')
		{
			ElementType tmp = number1.top();
			number1.pop();
			number2.push(tmp / number1.top());
			number1.pop();
			signal1.pop();
		}
	}
	if (!number1.empty())
	{
		result = number1.top();
	}
	else
	{
		result = number2.top();
	}
	number2.pop();
	while (!number2.empty())
	{
		if (!signal2.empty() && signal2.top() == '+')
		{
			result = result + number2.top();
			signal2.pop();
			number2.pop();
		}
		else if (!signal2.empty() && signal2.top() == '-')
		{
			result = result - number2.top();
			signal2.pop();
			number2.pop();
		}
		else if (signal2.empty())
		{
			result = number2.top();
		}
	}
}
static void
OutPut()
{
	std::cout << result << std::endl;
}

int main()
{
	InPut();
	Translate();
	Calculate();
	OutPut();
	return 0;
}