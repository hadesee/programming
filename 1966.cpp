#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main(void)
{   
    ios::sync_with_stdio(0),cin.tie(0);
    int t, n, m;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int qty[100] = {0}; //id개별의 퀄리티저장
        int qual[10] = {0}; //id각각의 퀄리티총갯수
        int a=0;
        queue<int> q;
        cin >> n >> m;

        for (int j = 0; j < n; j++)
        {   
            cin >> qty[j];
            if (m==j)
            {
                a=qty[j];
            }
            qual[qty[j]]++;
            q.push(j);
        }
        
        for (int j = a+1; j <= 9; j++)
        {
            if (qual[j]>0)
            {
                a = j;
            }
        }

        n=0;
        
        while (1)
        {
            if (qty[q.front()]==a&&(q.front()==m))
            {
                q.pop();
                n++;
                cout << n << '\n';
                break;
            }
            else if (qty[q.front()]==a)
            {
                q.pop();
                n++;
                qual[a]--;
                while (1)
                {
                    if (qual[a]<=0)
                    {
                        a--;
                    }
                    else if (qual[a]>0)
                    {
                        break;
                    }
                        
                }            
            }
            else
            {
                q.push(q.front());
                q.pop();
            }  
        }
    }
    
    return 0;
}