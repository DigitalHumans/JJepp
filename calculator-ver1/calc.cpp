#include <iostream>
using namespace std;
int main(){
    int a,c;
    char b;
    cin>>a>>b>>c;
    if(b=='+'){
        cout<<a+c<<endl;
    }
    else if(b=='-'){
        cout<<a-c<<endl;
    }
    else if(b=='*'){
        cout<<a*c<<endl;
    }
    else if(b=='/'){
        if(c==0){
            cout<<"can't divide by 0"<<endl;
        }
        else{
            cout<<a/c<<endl;
        }
    }
}