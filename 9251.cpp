#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int f[1001][1001] = {0};
int main(void)
{   
    ios::sync_with_stdio(0),cin.tie(0);
    string s1, s2;
    
    int n, m;

    cin >> s1 >> s2;

    n = s1.length();
    m = s2.length();

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[j-1]==s2[i-1])
            {
                f[i][j] = 1 + f[i-1][j-1];
            }
            else
            {
                if (f[i-1][j]>=f[i][j-1])
                {
                    f[i][j] = f[i-1][j];
                }
                else
                {
                    f[i][j] = f[i][j-1];
                }
                
            }
        }
        
    }   
    
    cout << f[m][n];
    
    return 0;
}