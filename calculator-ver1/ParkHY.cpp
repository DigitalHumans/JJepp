#include <iostream>
/*run this program using the console pauser or add own getch, system("pause") or input Loot*/
using namespace std;

int a;
int b;
char op;
double calculator()
{
    double result;

    if (op=='+'){
        result=a+b;
    }
    else if (op=='-'){
        result=a-b; 
    }
    else if (op=='*'){
        result=a*b;
    }
    else if (op=='/'){
        if (b !=0)
        {
            result=a/b;
        } 
        else {
            cout<<"error"<<endl;
        }
    }
    return result;
}
int main()
{
    cout<<"정수와 연산자를 차례대로 입력하시오.";
    cin>>a>>b>>op;

    double c= calculator();
    cout<<c<<endl; 

    return 0;
}
