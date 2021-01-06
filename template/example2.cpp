#include <iostream>
using namespace std;
template <typename T>
constexpr T add(const T& lhs, const T& rhs)
{
    return lhs + rhs;
}
int main()
{
    int a = 3, b = 5;
    cout << add(a, b) << endl;
    return 0;
}
