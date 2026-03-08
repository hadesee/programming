#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int nm[1001][1001] = {0};

int main(void)
{   
    ios::sync_with_stdio(0),cin.tie(0);
    int n, arr[1000] = {0}, f[1000] = {0};
    int answer = 0, max = 0, index = 0;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    for (int i = 0; i < n; i++)
    {
        max = -1;
        index = -1;
        for (int j = 0; j < i; j++)
        {
            if (arr[j]<arr[i]&&(max<f[j]))
            {
                max = f[j];
                index = j;
            }  
        }
        if (index==-1)
        {
            f[i] = arr[i];
        }
        else
        {
            f[i] = arr[i] + f[index];
        }
        
        if (answer<f[i])
        {
            answer = f[i];
        }
        
    }
    
    cout << answer;
    
    return 0;
}