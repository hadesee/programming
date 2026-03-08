#include <iostream>

using namespace std;
int main(void)
{
    int n, m, k, max = 1;

    cin >> n >> m;
    
    char squ[n][m] = {0};

    if (n<=m)
    {
        k = n;
    }
    else
    {
        k = m;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> squ[i][j];
        }
        
    }
    
    for (int l = k; l >= 2; l--)
    {
        for (int i = 0; i <= n-l; i++)
        {
            for (int j = 0; j <= m-l; j++)
            {
                if ((squ[i][j]==squ[i+l-1][j])&&(squ[i][j]==squ[i][j+l-1])&&(squ[i][j]==squ[i+l-1][j+l-1]))
                {
                    max = l;
                }
            }
        }
        if (max != 1)
        {
            break;
        }
        
    }
    
    cout << max*max;

    return 0;
}