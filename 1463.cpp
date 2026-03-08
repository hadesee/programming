#include <iostream>
#include <string>
#include <queue>
using namespace std;
int num[1000001];

int main(void)
{   
    ios::sync_with_stdio(0),cin.tie(0);
    int n, mini=0;

    cin >> n;
    num[1] = 0;
    num[2] = 1;
    num[3] = 1;

    for (int i = 4; i <= n; i++)
    {
        mini = num[i-1];
        if (i%3==0&&(mini>num[i/3]))
        {
            mini = num[i/3];
        }
        if (i%2==0&&(mini>num[i/2]))
        {
            mini = num[i/2];
        }  
        num[i] = mini + 1;
    }
    
    cout << num[n];

    return 0;
}