#include <iostream>
using namespace std;

void t(int r, int b, int e)
{
    int c; 
    if (((b == 1) && (e == 2)) || ((b == 1) && (e == 2)))
        c = 3;
    if (((b == 2) && (e == 3)) || ((b == 3) && (e == 2)))
        c = 1;
    if (((b == 1) && (e == 3)) || ((b == 3) && (e == 1)))
        c = 2;    
    if (r > 1)
    {
        t(r-1, b, c);
        cout << b << " -> " << e << endl;
        t(r-1, c, e);
    }
    else
        cout << b << " -> " << e << endl;
}

int main(void)
{
    t(4, 1, 2);
    
    return 0;
}