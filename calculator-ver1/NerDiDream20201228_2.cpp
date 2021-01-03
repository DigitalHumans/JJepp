// file name : NerDiDream20201228_2
// made by Ner_Di_Dream
// made at 2020.12.28

#include <iostream>
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
	cout << "Put Sign (^ & |)" << endl;
	cin >> sign;

	switch (sign)
	{
	case '^':
		result = a ^ b;
		break;
	case '&':
		result = a & b;
		break;
	case '|':
		result = a | b;
		break;
	}

	cout << a << " " << sign << " " << b << " = " << result << endl;
}