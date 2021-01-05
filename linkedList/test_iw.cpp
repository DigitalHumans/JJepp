#include <iostream>
#include <malloc.h>
using namespace std;

int main()
{
    int* a = NULL;
    int* b = NULL;
    // int* c = NULL;
    int* temp = new int();
    int* temp_2 = new int();
    int* temp_3 = new int();
    int* temp_4 = new int();
    int* temp_5 = new int();
    int* temp_6 = new int();
    int* temp_7 = new int();
    int* temp_8 = new int();

    a = temp;
    b = temp_3;
    
    *a = 0;
    *b = 3;

    cout<<"address_name  a  : "<<a<<"  : value_name *a  : "<<*a<<endl;
    cout<<"address_name  b  : "<<b<<"  : value_name *b  : "<<*b<<endl;

    b = a;

    cout<<"address_name  a  : "<<a<<"  : value_name *a  : "<<*a<<endl;
    cout<<"address_name  b  : "<<b<<"  : value_name *b  : "<<*b<<endl;
    delete temp;
    delete temp_2;
    delete temp_3;
    delete temp_4;
    delete temp_5;
    delete temp_6;
    delete temp_7;
    delete temp_8;
}