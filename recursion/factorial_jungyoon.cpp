/*
file name : factorial_jungyoon.cpp
created : 2021.01.04
author : jungyoon Kim
*/

#include <iostream>
using namespace std;

int fact(int n){
    int result = 1;
    for(int i = 1; i <= n; i++){
        result *= i;
    }
    cout << result << endl;
}

int main(){
    int n;
    cout << "값을 입력하세요: ";
    cin >> n;
    fact(n);
    return 0;
}