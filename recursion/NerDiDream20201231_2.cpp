// file name : NerDiDream20201231_1
// made by Ner_Di_Dream
// made at 2020.12.31

#include <iostream>
using namespace std;

int N = 0;


int Fibonacci(int num1, int num2, int n)
{
	if (N <= 2)
		return 1;
	else if (n == N)
		return num1;
	else
		return Fibonacci(num2, num1 + num2, n + 1);
	
}

int main()
{
	while (N <= 0)
	{
		cout << "몇 번째 수를 받을지 입력해주세요" << endl;
		cin >> N;
	}
	cout << Fibonacci(1, 1, 1) << endl;
	return 0;
}