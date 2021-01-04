/*
file name : shark_Fibonacci
created : 2021.01.03
author : spenshark
*/

#include<iostream>
using namespace std;

int fibo(int n){
	if(n==1){
		return 1;
	}
	else if(n==2){
		return 1;
	}
	else{
		return (fibo(n-2)+fibo(n-1));
	}
}

int main(){
	int a;
	cout << "피보나치 값을 알고싶은 항을 입력하세요 : ";
	cin >> a;
	cout << "\n" << "구하고자 하는 피보나치 값은 " << fibo(a) << "입니다." << endl;
}