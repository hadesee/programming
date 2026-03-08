#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main(void)
{   
    ios::sync_with_stdio(0),cin.tie(0);
    int sum = 0, n, temp = 0;
    int stair[10003] = {0};
    int fstair[10003] = {0};
    int max=0;
    string command;
    queue<int> que;


    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> stair[i];
    }
    
    fstair[0] = 0;
    fstair[1] = stair[1];
    fstair[2] = stair[2] + stair[1];
    fstair[3] = -1;
    for (int i = 3; i <= n; i++)
    {
        if (fstair[i]==-1)
        {
            if (fstair[i-2]>=fstair[i-3]+stair[i-1])
            {
                fstair[i] = fstair[i-2]+stair[i];
            }
            else
            {
                fstair[i] = fstair[i-3]+stair[i-1]+stair[i];
                fstair[i+1] = -1;
            }  
        }
        else
        {
            if (fstair[i-2]>=fstair[i-1])
            {
                fstair[i] = fstair[i-2]+stair[i];
            }
            else
            {
                fstair[i] = fstair[i-1]+stair[i];
                fstair[i+1] = -1;
            }
        }
        
        if (max<fstair[i])
        {
            max = fstair[i];
        }
        
    }
    
    cout << max;

    return 0;
}