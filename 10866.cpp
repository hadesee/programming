#include <iostream>
#include <string>
#include <cmath>
#include <list>
using namespace std;

int main(void)
{   
    ios::sync_with_stdio(0),cin.tie(0);
    int n, num;
    list<int> deq;
    string command;
    
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        num=0;
        cin >> command;

        if (command=="push_front")
        {
            cin >> num;
            deq.push_front(num);
        }
        else if (command=="push_back")
        {
            cin >> num;
            deq.push_back(num);
        }
        else if (command=="pop_front")
        {
            if (deq.empty()==1)
            {
                cout << -1 << '\n';
            }
            else
            {
                cout << deq.front() << '\n';
                deq.pop_front();
            }
        }
        else if (command=="pop_back")
        {
            if (deq.empty()==1)
            {
                cout << -1 << '\n';
            }
            else
            {
                cout << deq.back() << '\n';
                deq.pop_back();
            }
        }
        else if (command=="size")
        {
            cout << deq.size() << '\n';
        }
        else if (command=="empty")
        {
            cout << deq.empty() << '\n';    
        }
        else if (command=="front")
        {
            if (deq.empty()==1)
            {
                cout << -1 << '\n';
            }
            else
            {
                cout << deq.front() << '\n';
            }
        }
        else if (command=="back")
        {
            if (deq.empty()==1)
            {
                cout << -1 << '\n';
            }
            else
            {
                cout << deq.back() << '\n';
            }
        }
        
    }
    
    
    return 0;
}