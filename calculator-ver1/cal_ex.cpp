/*
file name : homework_calculation
created : 2020.12.29
author : kimminju
*/

#include <iostream>
#include <cmath>

using namespace std;
double calculator(int a, int b, char op);
int main(){
    int a, b;
    double c;
    char op;
    cout<<"두 정수와 연산자를 입력하세요(ex:6+5):";
    cin>>a>>op>>b;
    c=calculator(a, b, op);
    cout<<a<<op<<b<<"="<<c<<endl;

}

double calculator(int a, int b, char op){
    double res=0;
    if (op=='+'){
        res=a+b;
    }
    else if(op=='-'){
        res=a-b;
    }
    else if(op=='*'){
        res=a*b;
    }
    else if(op=='/'){
        if (b!=0){
            res=(double)a/(double)b;

        }
        else{
            cout<<"계산할 수 없음"<<endl;
        }
    }
    else if(op=='%'){
        if(b!=0){
            res=a%b;
        }
        else{
            cout<<"계산할 수 없음"<<endl;
        }
    }
    else if(op=='^'){
        res=pow(a,b);
    }
    
    return res;
}