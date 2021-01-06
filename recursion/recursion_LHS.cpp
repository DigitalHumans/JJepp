/*file name: recursion_LHS.cpp
 *Created: Sun, Jan, 3rd
 *auther: Lahesol
 */
#include <iostream>

int tmp = 1;

int facto(int a)
{
    if(a == 0)
        return 1;
    else
        return a*facto(a-1);    
}
        

int fibo(int num)
{
    if(num<=2 && num >0)
        return 1;
    else if(num == 0)
        return 0;
    else
        return fibo(num-1) + fibo(num-2);
    
}

int main()
{
    /*
    int in;

    std::cin >> in;

    std::cout<<facto(in);
    */

   std::cout << fibo(0);

}