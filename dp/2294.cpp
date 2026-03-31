#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k, a;
int dp[100][10001]={0};
vector<int> coin;
int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0);
    
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> a;
        coin.push_back(a);
    }

    sort(coin.begin(), coin.end());

    coin.erase(unique(coin.begin(), coin.end()), coin.end());

    a = coin[0];
    for (int i = 1; i <= k; i++)
    {
        if (i%a == 0)
        {
            dp[0][i] = i/a;
        }
    }
    
    
    for (int i = 1; i < coin.size(); i++)
    {
        a = coin[i];
        for (int j = 1; j <= k; j++)
        {
            if (j%a == 0)
            {
                if (dp[i-1][j]==0)
                {
                    dp[i][j] = j/a;
                }
                else if (dp[i-1][j]>j/a)
                {
                    dp[i][j] = j/a;
                }  
            }
            else
            {
                if (dp[i-1][j%a]!=0)
                {
                    if ((dp[i-1][j%a]+j/a)<dp[i-1][j])
                    {
                        dp[i][j] = dp[i-1][j%a]+j/a;
                    }
                    else
                    {
                        dp[i][j] = dp[i-1][j];
                    }
                    
                }
                else
                {
                    dp[i][j] = 0;
                }
     
            }
            
        }
    }
    
    if (dp[coin.size()-1][k]==0)
    {
        cout << -1;
    }
    else
    {
        cout << dp[coin.size()-1][k];
    }
    
    return 0;
}

