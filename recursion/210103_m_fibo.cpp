#include <iostream>
using namespace std;
int fibo(int n){
    if (n==0){ 
        return 0;} //0번째 항 = 0
    else if(n==1){
        return 1; //1번째 항 =1 
    }
    else{
        return fibo(n-1)+fibo(n-2); //2번째 항부터는 fibo(n-1)+fibo(n-2)의 값을 가짐
    }
    
}

int main(){
    int t;
    cout<<"Enter fibo number:";
    cin>>t;
    cout<<"\n"<<"the answer is "<<fibo(t)<<endl;
}