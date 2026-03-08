#include <iostream>
#include <string>
#include <cmath>
using namespace std;
long long f[10][101] = {0};
int main(void)
{   
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    long long div = 1000000000 ,sum = 0;

    cin >> n;

    f[0][1] = 0;
    f[1][1] = 1;
    f[2][1] = 1;
    f[3][1] = 1;
    f[4][1] = 1;
    f[5][1] = 1;
    f[6][1] = 1;
    f[7][1] = 1;
    f[8][1] = 1;
    f[9][1] = 1;
    
    for (int i = 2; i <= n; i++)
    {
        f[0][i] = (f[1][i-1])%div;
        f[1][i] = (f[0][i-1] + f[2][i-1])%div;
        f[2][i] = (f[1][i-1] + f[3][i-1])%div;
        f[3][i] = (f[2][i-1] + f[4][i-1])%div;
        f[4][i] = (f[3][i-1] + f[5][i-1])%div;
        f[5][i] = (f[4][i-1] + f[6][i-1])%div;
        f[6][i] = (f[5][i-1] + f[7][i-1])%div;
        f[7][i] = (f[6][i-1] + f[8][i-1])%div;
        f[8][i] = (f[7][i-1] + f[9][i-1])%div;
        f[9][i] = (f[8][i-1])%div;
    }
    
    sum = f[0][n] + f[1][n] + f[2][n] + f[3][n] + f[4][n] + f[5][n] + f[6][n] + f[7][n] + f[8][n] + f[9][n];
    sum = sum%div;
    cout << sum;
    
    return 0;
}