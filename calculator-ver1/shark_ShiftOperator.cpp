/*
file name : shark_ShiftOperator
created : 2020.12.31
author : spenshark
*/

#include<iostream>
using namespace std;

int main(){
	int a, b, result;
	
	while(1){
		cout << "\n" << "두 정수를 입력하세요" << endl;
		cin >> a >> b;
		
		cout << a << "<<" << b << '=' << (a<<b) << endl;
		cout << a << ">>" << b << '=' << (a>>b) << endl;
	}
	return 0; 
} 