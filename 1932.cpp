#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main(void)
{   
    ios::sync_with_stdio(0),cin.tie(0);
    int num[501][502]={0}, n;
    
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= i+1; j++)
        {
            cin >> num[i][j];
        }   
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= i+1; j++)
        {
            if (num[i-1][j-1]>=num[i-1][j])
            {
                num[i][j] = num[i][j] + num[i-1][j-1];
            }
            else
            {
                num[i][j] = num[i][j] + num[i-1][j];
            }
        }   
    }

    int max=0;
    
    for (int i = 1; i <= n; i++)
    {
        if (max < num[n-1][i])
        {
            max = num[n-1][i];
        }
        
    }
    
    cout << max;

    return 0;
}