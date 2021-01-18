#include <iostream>
using namespace std;
template<typename T>
class Accumulator
{
    T Acc_value;
public:
    const T& cvalue = Acc_value;
    Accumulator(const T& init):Acc_value(init){}
    const T& add(const T& rhs)
    {
        Acc_value = Acc_value + rhs;
        return cvalue;
    }
    const T& modify(const T& rhs)
    {
        Acc_value = rhs;
        return cvalue;
    }
};
int main()
{
    Accumulator<int> Acc(13);
    cout << Acc.add(3) << Acc.modify(3) << endl;
}
