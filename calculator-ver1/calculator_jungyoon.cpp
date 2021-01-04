/*
file name : calculator_jungyoon.cpp
created : 2020.12.31
author : jungyoon Kim
*/

#include <iostream>
using namespace std;

int main() {
    float num1, num2, result;   //입력받을 숫자 2개와 출력할 결과
    char op;    //연산자

    std::cout << "숫자를 입력하세요: ";
    std::cin >> num1;
    result = num1;

    while(1){
        std:: cout << "연산자를 입력하세요(ex. +, -, *, /): ";
        std::cin >> op;
        if(op == '=') break;

        std::cout << "숫자를 입력하세요: ";
        std::cin >> num2;

        switch(op){
            case '+':
            result += num2;
            break;

            case '-':
            result -= num2;
            break;

            case '*':
            result *= num2;
            break;

            case '/':
            if(num2 == 0) std::cout << "0으로 나눌 수 없습니다." << endl;
            else result /= num2;
            break;
        }
    }
    std::cout << "최종 결과는" << result << "입니다.\n" << endl;
    return 0;
}