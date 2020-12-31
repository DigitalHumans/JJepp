// file name : NerDiDream20201228_1
// made by Ner_Di_Dream
// made at 2020.12.28

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int a = 0;
	int b = 0;
	int result = 0;
	char sign;
	cout << "Put First Integer" << endl;
	cin >> a;
	cout << "Put Second Integer" << endl;
	cin >> b;
	cout << "Put Sign (+ - * / % ^)" << endl;
	cin >> sign;

	while (sign == '/' && b == 0)
	{
		cout << "Second Number should not be 0. Put Another Integer." << endl;
		cin >> b;
	}

	switch (sign)
	{
	case '+':
		result = a + b;
		break;
	case '-':
		result = a - b;
		break;
	case '*':
		result = a * b;
		break;
	case '/':
		result = a / b;
		break;
	case '%':
		result = a % b;
		break;
	case '^':
		result = pow(a, b);
		break;
	}

	cout << a << " " << sign << " " << b << " = " << result << endl;
}