#include <iostream>

int num[10001]={0};

using namespace std;
int main(void)
{
    ios::sync_with_stdio(0),cin.tie(0);
    int n, temp, max=0;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        num[temp]++;
        if (max<temp)
        {
            max = temp;
        }
        
    }
    
    for (int i = 1; i <= max; i++)
    {
        if (num[i]>0)
        {
            for (int j = 0; j < num[i]; j++)
            {
                cout << i << '\n';
            }
            
        }
        
    }
    

    return 0;
}