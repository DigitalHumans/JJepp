/*fibonacci sequence
 detail: using recursion

 made by: Ji Woo, Kim
 modified: 01.03, 2021
 */
#include <iostream>
using namespace std;
int fibo(int n) {

	while (1) {
		if (n <0)
			return -1;	//defensive coding
		if (n < 2)		//termination 
			return n;
		else
			return fibo(n - 1) + fibo(n - 2);	//recursive steps
	}
}
int main() {
	int num;

	cout<<"Enter the What Fibonacci sequence do you want to see:\t"<<endl;
	cin>>num;
	fibo(num);
	cout<<num<<"th fibonacci sequence is  "<<fibo(num)<<endl; //print the result

}