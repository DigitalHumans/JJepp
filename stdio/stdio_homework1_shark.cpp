#include <iostream>
#include <string>
using namespace std;
int main()
{
    int a;
    float b;
    char c;
    string d;
    
    cout << "정수를 입력하세요 : ";
    cin >> a;
    cout << "실수를 입력하세요 : ";
    cin >> b;
    cout << "문자를 입력하세요 : ";
    cin >> c;
    cout << "문자열을 입력하세요 : ";
    cin >> d;
    
    cout << "int = " << a << '.' << endl;
    cout << "float = " << b << '.' << endl;
    cout << "char = " << c << '.' << endl;
    cout << "string = " << d << '.' << endl;
    
    return 0;
}