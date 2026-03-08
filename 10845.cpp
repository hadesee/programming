#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main(void)
{   
    ios::sync_with_stdio(0),cin.tie(0);
    int n, num = 0;
    string command;
    queue<int> que;


    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> command;
        
        if (command=="push")
        {
            cin >> num;

            que.push(num);
        }
        else if (command=="pop")
        {
            if (que.empty())
            {
                cout << -1 << '\n';
            }
            else 
            {
                cout << que.front() << '\n';
                que.pop();
            }    
        }
        else if (command=="size")
        {
            cout << que.size() << '\n';
        }
        else if (command=="empty")
        {
            cout << que.empty() << '\n';    
        }
        else if (command=="front")
        {
            if (que.empty())
            {
                cout << -1 << '\n';
            }
            else
            {
                cout << que.front() << '\n';
            }
        }
        else if (command=="back")
        {
            if (que.empty())
            {
                cout << -1 << '\n';
            }
            else
            {
                cout << que.back() << '\n';
            }     
        }   
        
    }

    return 0;
}