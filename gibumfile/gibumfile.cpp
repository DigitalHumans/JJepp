#include <iostream>
#include <string>
#include <filesystem>
#include <cstdio>
using namespace std;
namespace fs=std::filesystem;
int main(){
    char a[5000];
    char b[5000];
    cout<<"바꾸려는 파일의 이름들은?";
    cin>>a;
    cout<<"바꿀 이름은?";
    cin>>b;
    string path="./";
    for(auto& p: fs:: recursive_directory_iterator(path)){
        string tp1=p.path().filename();
        string t2=p.path().filename();
        if(tp1.find(a)!=-1){          
            int poin=tp1.find(".",1);
            tp1.erase(0,poin);
            char new[1000]=strcat(b+tp1.c_str());
            rename(t2.c_str(),);
        }
    }
}