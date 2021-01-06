/*
file name : fibonacci_jungyoon.cpp
created : 2021.01.04
author : jungyoon Kim
*/

#include <iostream>
using namespace std;

int fibo(int n){
    if(n==1 || n==2) return 1;
    else return fibo(n-2) + fibo(n-1);
}

int main(){
    int n;
    cout << "값을 입력하세요: ";
    cin >> n;
    cout << fibo(n) << endl;
    return 0;
}