#include <iostream>

using namespace std;


long Factorial_recursion(int N)
{
    if (N == 0)
    {
        return 1;
    }
    return (N*Factorial_recursion(N-1));
}

int main()
{
    while (1)
    {
        int Nuber_of_N = 0;   
        cout<<"type length of serial"<<endl;
        cin>>Nuber_of_N;//문자 입력 시 에러처리 안되어 있음
        cout<<"------<result>------"<<endl;
        while(Nuber_of_N >= 0)
        {
            cout << Nuber_of_N << " :   ";
            cout << Factorial_recursion(Nuber_of_N) << endl;
            Nuber_of_N = Nuber_of_N - 1;
        }
        cout<<"type n to quit OR type anykey to excutate this again"<<endl;
        char end_value = 0;
        cin >> end_value;
        if (end_value == 'n' || end_value == 'N')
        {
            break;
        }
    }
}