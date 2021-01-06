#include <iostream>
using namespace std;
int fac(int num){
    int res=1;
    for(int i=1; i<=num; ++i){
        res=res*i;
    }
    return res;
}

int main(void){
    int num, res=0;
    cout<<"Enter a number:";
    cin>>num;
    res=fac(num);
    cout<<num<<" facorial is "<<res<<endl;
    return 0;
}