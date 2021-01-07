#include<iostream>
using namespace std;
int facto(int x);

int main(){
	int num;
	cout<<"몇 팩토리얼을 출력할까요?"<<endl;
	cin>>num;
	cout<<num<<"팩토리얼은"<<facto(num)<<"입니다"<<endl;
}



int facto(int x){
	if(x <= 1)
		return 1;
	else
		return x * facto(x - 1);
}
