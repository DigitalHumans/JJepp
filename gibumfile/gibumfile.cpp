#include <iostream>
#include <string>
using namespace std;
int main(){
    char a[5000];
    char b[5000];
    cout<<"경로를 입력 하시오:";
    cin>>a;
    cout<<"바꿀 이름을 입력하시오";
    cin>>b;
    rename(a,b);
}