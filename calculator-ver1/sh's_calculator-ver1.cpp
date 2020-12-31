/*file name: sh's_calculator-ver1.cpp
created: 2020-12-28
modified: 2020-12-31
author: Kwon  Soonhyung
*/

#include <iostream>

using namespace std;

void prtIntro(); //introduce how to use this program

//parameter로 1,2번째 피연산자, 연산자를 받아 해당하는 연산 수행후 결과를 result에 저장, 나눗셈 두번째 피연산자가 0이면 false반환
bool operateCalc(double a, double b, char oprt, double *result); 

class Calc //사칙연산이 함수가 저장된 클래스
{
    public:
        double add(double a,double b)
        {
            return a+b;
        }
        double sub(double a,double b)
        {
            return a-b;
        }
        double mul(double a,double b)
        {
            return a*b;
        }
        double div(double a,double b)
        {
            return a/b;
        }
};

int main()
{
    prtIntro(); //introduce how to use this program
    double a=0, b=0, result=0; //a:첫번째 피연산자, b:두번째 피연산자, result:결과
    char oprt; //연산자 저장할 변수

    while(true)
    {
        cout << "첫번째 피연산자 : ";
        cin >> a;
        cout << "연산자 : ";
        cin >> oprt;
        cout << "두번째 피연산자 : ";
        cin >> b;
        
        if(operateCalc(a, b, oprt, &result) == false)
        {
            cout << "0으로 나눌 수 없습니다." << endl << endl;
        }
        else
        {
            cout << "결과 : " << result << endl << endl;
        }
    } 
}

void prtIntro()//introduce how to use this program
{
    cout << "계산기 ver.1 입니다." << endl;
    cout << "사칙연산 사용이 가능합니다." << endl;
}

//parameter로 1,2번째 피연산자, 연산자를 받아 해당하는 연산 수행후 결과를 result에 저장, 나눗셈 두번째 피연산자가 0이면 false반환
bool operateCalc(double a, double b, char oprt,  double *result)
{
    Calc calc;
    switch(oprt)
    {
        case '+': *result = calc.add(a,b); return true; break;
        case '-': *result = calc.sub(a,b); return true; break;
        case '*': *result = calc.mul(a,b); return true; break;
        case '/': 
            if(b == 0) 
            {
                return false; 
                break;
            }
            else
            {
                *result = calc.div(a,b); 
                return true; 
                break;
            }                        
    }
}