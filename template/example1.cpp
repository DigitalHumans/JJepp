#include <iostream>
using namespace std;
template<typename T, typename Lamda>
void swap_if(T& lhs, T& rhs, Lamda l)
{
    if (l(lhs, rhs))
    {
        T temp = lhs;
        lhs = rhs;
        rhs = temp;
    }
}
int main()
{
    int a = 3, b = 5;
    swap_if(a, b, [](auto lhs, auto rhs){return lhs < rhs;});
    cout << a << b << endl;
}
