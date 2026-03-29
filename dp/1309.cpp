#include <iostream>

using namespace std;

int main(void)
{
    int n;
    int f, g, pf, pg;
    int nanu = 9901;

    cin >> n;

    f = 3;
    g = 1;
    pf = f;
    pg  = g;

    for (int i = 2; i <= n; i++)
    {
        g = (pf - pg)%nanu;

        f = (pf + g * 2)%nanu;

        if (f<0)
        {
            f += 9901;
        }

        pf = f;
        pg = g;
    }

    cout << f;
    
    return 0;
}