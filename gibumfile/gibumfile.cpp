#include <iostream>
#include <string>
#include <filesystem>
#include <cstdio>
using namespace std;
namespace fs=std::filesystem;
int main(){
    string target;
    string change;
    cout<<"바꾸려는 파일들에 공통적으로 들어 있는것은?";
    cin>>target;
    cout<<"바꿀 이름은?";
    cin>>change;
    int count=0;
    string path="./";
    for(auto& p: fs:: recursive_directory_iterator(path)){
        string temp=p.path().filename();
        if(temp.find(target)!=-1){          
            int poin=temp.find(".",1);
            temp.erase(0,poin);
            string final=change+"0";
            final+=to_string(count);
            count+=1;
            final+=temp;
            temp=p.path().filename();
            rename(temp.c_str(),final.c_str());
        }
    }
}