#include <iostream>
#include <string>
#include <queue>
using namespace std;
int score[2][100000] = {0},g[100001] = {0}, f[100001]= {0};
int main(void)
{   
    ios::sync_with_stdio(0),cin.tie(0);
    int t, n;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n;  

        for (int j = 0; j < 2; j++)
        {
            for (int o = 0; o < n; o++)
            {
                cin >> score[j][o];
            }
            
        }
        f[1] = score[1][0];
        g[1] = score[0][0];

        for (int j = 2; j <= n; j++)
        {
            g[j] = f[j-1]+score[0][j-1];
            
            if ((f[j-2]+score[0][j-2]) >= g[j-2])
            {
                f[j] = score[1][j-1] + f[j-2]+score[0][j-2];
            }
            else
            {
                f[j] = score[1][j-1] + g[j-2];
            }
    
            
        }
        
        if (f[n]>=g[n])
        {
            cout << f[n] << '\n';
        }
        else
        {
            cout << g[n] << '\n';
        }    
    }
    
    return 0;
}