#include <iostream>
#include <string>
#include <filesystem>
using namespace std;
namespace fs=std::filesystem;
int main(){
    int a;
    cout<<"다음중 선택세요(1.파일명 일괄 변경/2.특정 문자 지우기):";
    cin>>a;
    if( a==1){
    string target;
    string change;
    cout<<"바꾸려는 파일들에 공통적으로 들어 있는것은?";
    cin>>target;
    cout<<"바꿀 이름은?";
    cin>>change;
    int count=0;
    target.shrink_to_fit();
    change.shrink_to_fit();
    for(auto& p: fs:: recursive_directory_iterator("./")){
        string temp=p.path().filename();
        if(temp.find(target)!=-1){          
            temp.erase(0,temp.find(".",1));
            temp.shrink_to_fit();
            string final=change+"0";
            final+=to_string(count);
            count+=1;
            final+=temp;
            temp=p.path().filename();
            final.shrink_to_fit();
            temp.shrink_to_fit();
            rename(temp.c_str(),final.c_str());
        }
    }
    }
    else if(a==2){
        int b;
        cout<<"앞에서부터 몇자리까지 지우실지를 입력해주세요:";
        cin>>b;
        cout<<"모든파일에 적용하시겠습니까?특정 문자열이 들어가 있을 경우 적용하시겠습니까?(1/2):";
        cin>>a;
        string c;
        if(a==2){
            cout<<"특정 문자열을 입력하여 주십시요:";
            cin>>c;
        }
        c.shrink_to_fit();
        for(auto& p: fs:: recursive_directory_iterator("./")){
            string t1=p.path().filename();
            if(c.capacity()==0){
                
            }
        }
    }
}