#include <iostream>
#include <string>
using namespace std;

int main(void)
{   
    ios::sync_with_stdio(0),cin.tie(0);
    int max, n, sum;

    cin >> n;

    int num[n], f[n];

    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    max = num[0];
    f[0] = num[0];

    for (int i = 1; i < n; i++)
    {
        if (f[i-1]>0)
        {
            f[i] = num[i] + f[i-1];
        }
        else
        {
            f[i] = num[i];
        }  

        if (max < f[i])
        {
            max = f[i];
        }
        
    }

    cout << max;
     
    return 0;
}