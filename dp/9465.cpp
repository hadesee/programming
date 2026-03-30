#include <iostream>

using namespace std;
int sticker[2][100001] = {0};
int dp[2][100001] = {0};

int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0);
    int t, n, max=0;

    cin >> t;

    for (int j = 0; j < t; j++)
    {
        cin >> n;

        max = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> sticker[0][i];
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> sticker[1][i];
        }

        dp[0][1] = sticker[0][1];
        dp[1][1] = sticker[1][1];
        max = dp[0][1];
        if (max < dp[1][1])
        {
            max = dp[1][1];
        }
        if (n==1)
        {
            cout << max << '\n';
            continue;
        }
        
        

        dp[0][2] = sticker[0][2] + dp[1][1];
        dp[1][2] = sticker[1][2] + dp[0][1];
        
        if (dp[0][2]<dp[1][2])
        {
            max = dp[1][2];
        }
        else
        {
            max = dp[0][2];
        }

        for (int i = 3; i <= n; i++)
        {
            if (dp[1][i - 1] > dp[1][i - 2])
            {
                dp[0][i] = sticker[0][i] + dp[1][i - 1];
            }
            else
            {
                dp[0][i] = sticker[0][i] + dp[1][i - 2];
            }

            if (dp[0][i-1] > dp[0][i-2])
            {
                dp[1][i] = sticker[1][i] + dp[0][i-1];
            }
            else
            {
                dp[1][i] = sticker[1][i] + dp[0][i-2];
            }
        
            if (max < dp[1][i])
            {
                max = dp[1][i];
            }
            if (max < dp[0][i])
            {
                max = dp[0][i];
            }
            
        }

        cout << max << '\n';
    }

    return 0;
}