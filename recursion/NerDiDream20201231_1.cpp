// file name : NerDiDream20201231_1
// made by Ner_Di_Dream
// made at 2020.12.31

#include <iostream>
using namespace std;

int Factorial(int a, int n)
{
	if (n > 1)
		return Factorial(a * n, n - 1);
	else if (n == 1)
		return a;
	else
		return 1;
}

int main()
{
	int N = 0;
	cout << "팩토리얼을 입력해주세요" << endl;
	cin >> N;
	cout << Factorial(1, N) << endl;
	return 0;
}