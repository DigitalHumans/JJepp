/*
file name : shark_Factorial
created : 2021.01.03
author : spenshark
*/

#include<iostream>
using namespace std;

int fact(int n){
	if(n==0||n==1){
		return 1;
	}
	else{
		return (n*fact(n-1));
	}
}

int main(){
	int a;
	cout << "팩토리얼 값을 알고싶은 수를 입력하세요 : ";
	cin >> a;
	cout << "\n" << "팩토리얼 값은 " << fact(a) << "입니다." << endl;
}