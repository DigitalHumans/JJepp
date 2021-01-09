#include <iostream>
#include <malloc.h>
using namespace std;


template <typename T> 
class sample
{
        // struct node temp<T>;
    T value;

    T return_0()
    {
        return value;
    }

};


template <typename T>
struct node
{
    long serial_num;
    struct node* ptr_previous = NULL;
    struct node* ptr_next = NULL;
    class sample<T> data;
};

// template <> struct node <example_data>
// {
//     long serial_num;
//     struct node* ptr_previous = NULL;
//     struct node* ptr_next = NULL;
//     class T data;
// };


int main()
{
    struct node data<int>;
}