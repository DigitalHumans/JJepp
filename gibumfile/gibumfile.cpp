#include <iostream>
#include <string>
#include <filesystem>
#include <algorithm>
using namespace std;
namespace fs=std::filesystem;
int main(){
    string target;
    string change;
    string temp;
    while(1){
    char choose;
    cout<<"다음중 선택세요(1.파일명 일괄 변경/2.특정 문자 지우기):";
    cin>>choose;
    if( choose=='1'){
    cout<<"모든파일에 적용하시겠습니까?특정 문자열이 들어가 있을 경우 적용하시겠습니까?(1/2):";
    cin>>choose;
    if(choose=='2'){
    cout<<"바꾸려는 파일들에 공통적으로 들어 있는것은?";
    cin>>target;
    }
    cout<<"바꿀 이름은?";
    cin>>change;
    int count=0;
    target.shrink_to_fit();
    change.shrink_to_fit();
    for(auto& p: fs:: recursive_directory_iterator("./")){
        temp=p.path();
        if(temp.find(target)!=-1||target.empty()){        
             if(temp.find("a.out")!=-1||temp.find("gibumfile.cpp")!=-1||fs::is_directory(p)){
                    continue;
                }  
            reverse(temp.begin(),temp.end());
            int c=temp.find("/");
            reverse(temp.begin(),temp.end());
            c=temp.length()-c;
            temp.replace(c,temp.find(".",1)-c,change+"0"+to_string(count));
            count++;
            rename(p,temp.c_str());
        }
    }
    }
    else if(choose=='2'){
        int delposit;
        cout<<"앞에서부터 몇자리까지 지우실지를 입력해주세요:";
        cin>>delposit;
        cout<<"모든파일에 적용하시겠습니까?특정 문자열이 들어가 있을 경우 적용하시겠습니까?(1/2):";
        cin>>choose;
        if(choose=='2'){
            cout<<"특정 문자열을 입력하여 주십시요:";
            cin>>change;
        }
        change.shrink_to_fit();
        for(auto& p: fs:: directory_iterator("./")){
             temp=p.path().filename();
            if(change.empty()||temp.find(change)!=-1){
                if(temp.find("a.out")!=-1||temp.find("gibumfile.cpp")!=-1){
                    continue;
                }
                temp.erase(0,delposit);
                rename(p,temp.c_str());
            }
        }
    }
    cout<<"초기 화면으로 돌아가시겠습니까?(yes(3)/no(4)):";
    cin>>choose;
    if(choose=='4'){
        break;
    }
    }
}