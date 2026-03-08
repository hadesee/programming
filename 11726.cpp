#include <iostream>
#include <string>
using namespace std;

int main(void)
{   
    ios::sync_with_stdio(0),cin.tie(0);
    long long n, f[1001]={0};

    f[1] = 1;
    f[2] = 2;

    cin >> n;

    for (int i = 3; i <= n; i++)
    {
        f[i] = (f[i-1] +f[i-2])%10007;
    }
    
    cout << f[n];
     
    return 0;
}