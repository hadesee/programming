#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main(void)
{   
    ios::sync_with_stdio(0),cin.tie(0);
    int n, result=0;
    int consult[16]={0}, money[16]={0}, time[16]={0};
    cin >> n;
    

    for (int i = 1; i <= n; i++)
    {
        cin >> time[i] >> money[i];
    }
    
    if (time[1] <= n)
    {
        consult[1] = money[1];
    }
    else
    {
        consult[1] = 0;
    }
    
    

    for (int i = 2; i <= n; i++)
    {
        int max = 0;
        for (int j = 1; j < i; j++)
        {
            if (consult[j]>max&&(i>=time[j]+j))
            {
                max = consult[j];
            }
        }
        
        if (time[i]+i<=(n+1))
        {
            consult[i] = max + money[i];
        }
        
    }
    
    for (int i = 1; i <= n; i++)
    {
        if (result<consult[i])
        {
            result = consult[i];
        }
        
    }
    
    cout << result;

    return 0;
}