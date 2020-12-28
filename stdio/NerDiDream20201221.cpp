#include <iostream>
#include <string>
using namespace std;
int main()
{
    int a;
    float b;
    char c;
    string d;
    cout << "Input an integer : ";
    cin >> a;
    cout << "Input an float : ";
    cin >> b;
    cout << "Input an character : ";
    cin >> c;
    cout << "Input an string : ";
    cin >> d;
    cout << "Your integer is " << a << '.' << endl;
    cout << "Your float is " << b << '.' << endl;
    cout << "Your character is " << c << '.' << endl;
    cout << "Your string is " << d << '.' << endl;
    return 0;
}