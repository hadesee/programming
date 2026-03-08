#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int n, f[100001]={0};

int main(void)
{   
    ios::sync_with_stdio(0),cin.tie(0);
    int m = 0;

    f[0] = 0;
    f[1] = 1;
    f[2] = 2;

    cin >> n;

    for (int i = 3; i <= n; i++)
    {
        int max = (int)sqrt(i);
        int mmax = 10000;
        m=max;
        for (int j = 1; j <= max; j++)
        {
            if (mmax>f[i-(int)pow(j,2)])
            {
                mmax = f[i-(int)pow(j,2)];
                m=j;
            }
        }
        
        f[i] = 1 + f[i-(int)pow(m,2)];
    }

    cout << f[n];

    return 0;
}