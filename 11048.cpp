#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int nm[1001][1001] = {0};

int main(void)
{   
    ios::sync_with_stdio(0),cin.tie(0);
    int n, m;
    

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> nm[i][j];
        }
        
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (nm[i-1][j]>=nm[i][j-1])
            {
                nm[i][j] = nm[i][j] + nm[i-1][j];
            }
            else
            {
                nm[i][j] = nm[i][j] + nm[i][j-1];
            }
            
        }
        
    }
    
    cout << nm[n][m];

    return 0;
}