/*factorial in CPP
 detail: using recursion fuction

 made by: Ji Woo, Kim
 modified: 01.03,2021
 */
#include <iostream>
using namespace std;
int factorial(int n) {

	if (n < 2) {	//turmination condition
		return n;	//recursive ends.
	}
	else
		return n * factorial(n - 1);	//else,recursive steps
}

int main() {
	int num;
	int value;

	cout<<"type a integer factorial(ex-3!)"<<endl;
	cin>>num;	//get a integer

	value = factorial(num);	//put a factorial value into "value"
	cout<<"\n"<<num<<"! is "<<value<<endl;	//show the value
	return 0;
}