/*
 * file name : sh'sRecursion
 * created : 2021/01/02
 * modified : 2021/01/02
 * author : KSoonhyung
 */

#include <iostream>

using namespace std;

//사용자가 원하는 피보나치 수열의 크기를 받고, 피보나치 배열을 반환하는 함수
int* fibonacci(const int length);

//펙토리얼 num! 계산 후 반환하는 함수
long long factiorial(const int number); 

//배열과 배열의 길이를 받고 순서대로 출력해주는 함수
void printArray(const int* array, const int length); 

int main()
{
    while(true)
    {
        cout << "Factorial와 Fibonacci 중 원하는 연산을 고르세요." << endl;
        cout << "1. Factorial, 2. Fibonacci (1/2)? : ";

        int mod(0); //사용자가 원하는 연산을 구별하기 위한 변수
        cin >> mod;

        switch (mod)
        {
        case 1:
            cout << "팩토리얼 연산을 할 숫자를 입력하세요 : " ;
            int number;
            cin >> number;
            cout << number << "! : " << factiorial(number) << endl;
            break;
        
        case 2:
            cout << "원하는 피보나치 수열의 크기를 입력해 주세요. : ";
            int length;
            cin >> length;
            printArray(fibonacci(length), length);
            break;
        
        default:
            cout << "다시 입력해 주세요!" << endl;
            while(getchar() != '\n'); //잘못된 형식 입력시 입력버퍼 초기화
            cin.clear();
            break;
        }
    }
}


//사용자가 원하는 피보나치 수열의 크기를 받고, 피보나치 배열을 반환하는 함수
int* fibonacci(const int length)
{
    int *fib_array = new int(length); //피보나치 수열을 담을 배열
    fib_array[0] = 1; //피보나치 수열의 1번째 항 1로 초기화
    for(int i=1; i<length; i++)
    {
        if(i == 1) fib_array[i] = 1;
        else       fib_array[i] = fib_array[i-2] + fib_array[i-1];       
    }
    return fib_array;
}

//펙토리얼 num! 계산 후 반환하는 함수
long long factiorial(const int number)
{
    long long factor(1);
    for(int i=1; i < number+1; i++) factor *= i;
    return factor;
}

//배열과 배열의 길이를 받고 순서대로 출력해주는 함수
void printArray(const int* array, const int length)
{
    for(int i=0; i<length; i++) cout << array[i] << ' ';
    cout << endl;
}