#include <iostream>
#include <string>
using namespace std;

int main(void)
{   
    ios::sync_with_stdio(0),cin.tie(0);
    int n, k;
    cin >> n >> k;
    int w[k+1], v[101];
    int wv[101][k+1]={0};
    
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i] >> v[i];
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (j<w[i])
            {
                wv[i][j] = wv[i-1][j];
            }
            else 
            {
                if(wv[i-1][j]<(wv[i-1][j-w[i]]+v[i]))
                {
                    wv[i][j] = wv[i-1][j-w[i]]+v[i];
                }
                else
                {
                    wv[i][j] = wv[i-1][j];
                }
            }    
        }   
    }

    cout << wv[n][k];

    return 0;
}