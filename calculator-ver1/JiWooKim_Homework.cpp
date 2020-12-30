/*
file name:simpe calculator
author:Ji Woo Kim
modified date:12.31,2020
*/
#include <iostream>
using namespace std;
int main()
{   int n,m,result;
    char Operator;
    
    cout << "식을 입력하세요(덧셈,뺄셈,곱셈,나눗셈,나머지)" << endl;
    cout << "ex) 5+3" << endl;
  
    cin >> n >> Operator >> m;  //정수 연산자 정수 순으로 식을 받는다.

    if(Operator=='/'&&m==0) //만약 피연산자가 0이면서 연산자가 나누기인 경우에, 에러입니라를 출력
        cout << "에러입니다(0으로 나눌 수 없습니다.)" <<endl;

    else    //아닌경우를 모두 swich로 묶는다.
    {
        switch (Operator)
        {
         case '+': result=n+m;
             break;
         case '-': result=n-m;
             break;
         case '*': result=n*m;
             break;
         case '/': result=n/m;
             break;
         case '%': result=n%m;
             break;
        }
    cout << n << Operator << m << "=" << result <<endl; //else 문에 한하여 계산결과를 출력해서 보여준다.
    }

    return 0;
}