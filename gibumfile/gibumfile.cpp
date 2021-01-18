#include <iostream>
#include <string>
#include <filesystem>
using namespace std;
namespace fs=std::filesystem;
int main(){
    char a[5000];
    char b[5000];
    cout<<"바꾸려는 파일의 이름들은?";
    cin>>a;
    cout<<"바꿀 이름은?";
    cin>>b;
    for(auto& p: fs:: recursive_directory_iterator(path)){

    }
}