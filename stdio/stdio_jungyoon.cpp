#include <iostream>
#include <string>
using namespace std;
int main()
{
    int a;
    float b;
    char c;
    string d;

    cout << "Input an int : ";
    cin >> a;
    cout << "Input an float : ";
    cin >> b;
    cout << "Input an char : ";
    cin >> c;
    cout << "Input an string : ";
    cin >> d;

    cout << "int = " << a << '.' << endl;
    cout << "float = " << b << '.' << endl;
    cout << "char = " << c << '.' << endl;
    cout << "string = " << d << '.' << endl;

    return 0;
}