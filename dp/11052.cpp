#include <iostream>

using namespace std;

int dp[1001] = {0};
int p[1001] = {0};
int main(void)
{
    int n, max = 0;

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }
    dp[1] = p[1];

    for (int i = 2; i <= n; i++)
    {
        max = p[i];
        for (int j = 1; j <= i; j++)
        {
            if (max<dp[j]+dp[i-j])
            {
                max =dp[j]+dp[i-j];
            }  
        }
        dp[i] = max;
    }

    cout << dp[n];

    return 0;
}