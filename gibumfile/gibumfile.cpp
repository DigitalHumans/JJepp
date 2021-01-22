#include <iostream>
#include <string>
#include <filesystem>
#include <algorithm>
using namespace std;
namespace fs=std::filesystem;
int pre(string m);
int main(){
    int c;
    string target;
    string change;
    string temp;
    string isdir;
    while(1){
    char choose;
    cout<<"다음중 선택세요\n(1.파일명 일괄 변경/2.앞자리 n번째 까지 지우기)\n% 3.특정 문자열 추가/4.특정 문자열 제거:";
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
        isdir=p.path().parent_path();
        temp=p.path();
        if(temp.find(target)!=-1||target.empty()){        
             if(temp.find("a.out")!=-1||temp.find("gibumfile.cpp")!=-1||fs::is_directory(p)||(isdir.find(target)!=-1&&choose=='2')){
                    continue;
                }  
            c=pre(temp);
            temp.replace(c,temp.find(".",1)-c,change+"0"+to_string(count));
            count++;
            rename(p,temp.c_str());
        }
    }
    }
    else if(choose=='2'){
        int delposit;
        int first;
        cout<<"어느 번째 짜리부터 지우실지 입력해주세요:";
        cin>>first;
        first--;
        cout<<"앞에서부터 몇자리까지 지우실지를 입력해주세요:";
        cin>>delposit;
        cout<<"모든파일에 적용하시겠습니까?특정 문자열이 들어가 있을 경우 적용하시겠습니까?(1/2):";
        cin>>choose;
        if(choose=='2'){
            cout<<"특정 문자열을 입력하여 주십시요:";
            cin>>change;
        }
        change.shrink_to_fit();
        for(auto& p: fs:: recursive_directory_iterator("./")){
             temp=p.path();
              isdir=p.path().parent_path();
            if(change.empty()||temp.find(change)!=-1){
                if(temp.find(target)!=-1||target.empty()){        
             if(temp.find("a.out")!=-1||temp.find("gibumfile.cpp")!=-1||fs::is_directory(p)||(isdir.find(change)!=-1&&choose=='2')){
                    continue;
                }  
            c=pre(temp);
            temp.erase(c+first,delposit);
            cout<<temp<<endl;
            rename(p,temp.c_str());
            }
        }
    }
    }
    else if(choose=='3'){
        int d=-1;
        cout<<"문자열을 넣을 위치를 골라주십시오(1.맨앞/2.맨뒤/3.특정 문자열 앞):";
        cin>>choose;
        if(choose=='3'){
            cout<<"특정 문자열을 입력해주십시요:";
            cin>>target;
        }
        cout<<"삽입할 문자열을 입력해주십시오:";
        cin>>change;
        for(auto &p: fs:: recursive_directory_iterator("./")){
            string isdir=p.path().parent_path();
            temp=p.path();
             if(temp.find("a.out")!=-1||temp.find("gibumfile.cpp")!=-1||fs::is_directory(p)||(isdir.find(target)!=-1&&choose=='3')){
                    continue;
                }  
            if(choose=='1'){
                d=pre(temp);
            }
            else if(choose=='2'){
                d=temp.find(".",1)-1;
            }
            else if(choose=='3'){
                d=temp.find(target);
            }
            string final=temp.substr(0,d);
            final+=change;
            final+=temp.substr(d,temp.length());
            rename(p,final.c_str());
        }
                  if(d==-1){
                continue;
            }
    }
    else if(choose=='4'){

    }
    cout<<"초기 화면으로 돌아가시겠습니까?(yes(3)/no(4)):";
    cin>>choose;
    if(choose=='4'){
        break;
    }
    }
}
int pre(string m){
    int n;
    reverse(m.begin(),m.end());
            n=m.find("/");
            n=m.length()-n;
            return n;
}