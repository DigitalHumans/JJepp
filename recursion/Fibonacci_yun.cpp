#include<iostream>
using namespace std;
int fibo(int x);

int main(){
	int num;
	cout<<"몇번째 피보나치 수열까지 출력할까요?"<<endl;
	cin>>num;
	for(int range = 0; range <= num; range++)
		cout<<fibo(range)<<endl;
}



int fibo(int x){
	if(x <= 2)
		return 1;
	else
		return fibo(x - 1) + fibo(x - 2);
}
