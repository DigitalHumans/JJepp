#include <iostream>

using namespace std;

int* Nuber_of_N = 0;

long Fibonacci_recursion(long N_0, long N_1, int* N)
{
    if(*N != 0)
    {
        *N - 1;
        cout <<Fibonacci_recursion(N_1, N_0+N_1 ,N)<<", ";
    }
    cout<<N_0 + N_1<<endl;
    return N_0 + N_1;
}


int main()
{
    *Nuber_of_N = 5;
    Fibonacci_recursion(1, 1, Nuber_of_N);
}
