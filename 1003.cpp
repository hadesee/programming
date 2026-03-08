#include <iostream>
#include <string>
using namespace std;

int main(void)
{   
    ios::sync_with_stdio(0),cin.tie(0);
    int fib1[41]={0}, fib0[41] = {0};
    int t, max=0;

    cin >> t;
    
    int n[t]={0};

    for (int i = 0; i < t; i++)
    {
        cin >> n[i];
        if (max<n[i])
        {
            max = n[i];
        }
        
    }
    
    fib1[0] = 0;
    fib0[0] = 1;
    fib1[1] = 1;
    fib0[1] = 0;

    for (int i = 2; i <= max; i++)
    {
        fib1[i] = fib1[i-1] + fib1[i-2];
        fib0[i] = fib0[i-1] + fib0[i-2];
    }
    
    for (int i = 0; i < t; i++)
    {
        cout << fib0[n[i]] << ' ' << fib1[n[i]] << '\n';
    }

    return 0;
}