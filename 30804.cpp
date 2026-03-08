#include <iostream>
#include <string>
#include <queue>
#include <list>
using namespace std;

int main(void)
{   
    ios::sync_with_stdio(0),cin.tie(0);
    int n, temp, num, count, max=-1;
    list<int> numlist, muchlist;
    count = 1;
    cin >> n;
    cin >> num;

    for (int i = 1; i < n; i++)
    {
        cin >> temp;
        if (temp == num)
        {
            count++;
        }
        else
        {
            muchlist.push_back(count);
            numlist.push_back(num);
            num = temp;
            count = 1;
        }          
    }
    
    muchlist.push_back(count);
    numlist.push_back(num);
    
    int num1=-1, num2=-1, kind=0, result=0;
    int lastnum, lastmuch;

    while (1)
    {
        if (numlist.empty())
        {
            if (max<result)
            {
                max = result;
            }
            break;
        }
        else if (kind==0)
        {
            num1=numlist.front();
            result = muchlist.front();
            kind++;
            muchlist.pop_front();
            numlist.pop_front();
        }
        else if (kind==1)
        {
            num2=numlist.front();
            result += muchlist.front();
            kind++;
            lastmuch = muchlist.front();
            lastnum = numlist.front();
            muchlist.pop_front();
            numlist.pop_front();
        }
        else if (kind==2&&((num1==numlist.front())||(num2==numlist.front())))
        {
            result += muchlist.front();
            lastmuch = muchlist.front();
            lastnum = numlist.front();
            muchlist.pop_front();
            numlist.pop_front();
        }
        else if(kind==2&&((num1!=numlist.front())&&(num2!=numlist.front())))
        {
            if (max<=result)
            {
                max = result;
            }
            result=0;
            muchlist.push_front(lastmuch);
            numlist.push_front(lastnum);
            kind=0;
        }
          
    }
    
    cout << max;

    return 0;
}