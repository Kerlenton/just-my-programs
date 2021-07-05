#include <iostream>
#include "big_numbers.h"
using namespace std;

int main()
{
    BigNumber x(20);
    BigNumber y(5);
    auto z = x * y;
    
    for (auto i = z.data_.rbegin(); i != z.data_.rend(); i++)
        cout << *i  << ' ';
    
    return 0;
}