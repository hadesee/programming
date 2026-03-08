#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main(void)
{   
    ios::sync_with_stdio(0),cin.tie(0);
    int pear, director, d[5]={0};
    queue<int> m, direct;

    cin >> pear;

    for (int i = 0; i < 6; i++)
    {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        direct.push(temp1);
        m.push(temp2);
        d[temp1]++;
    }
    
    if ((d[2]==1)&&(d[3]==1))
    {
        director =2;
    }
    else if ((d[2]==1)&&(d[4]==1))
    {
        director =4;
    }
    else if ((d[1]==1)&&(d[3]==1))
    {
        director =3;
    }
    else if ((d[1]==1)&&(d[4]==1))
    {
        director =1;
    }

    while (1)
    {
        if (director == direct.front())
        {
            break;
        }
        else
        {
            direct.push(direct.front());
            direct.pop();
            m.push(m.front());
            m.pop();
        }
    }
    
    int M, X, n, y, sum;

    M = m.front();
    m.pop();
    
    X = m.front();
    m.pop();
    m.pop();

    n = m.front();
    m.pop();

    y = m.front();
    m.pop();

    sum = (M * X) - (n * y);
    sum *= pear;

    cout << sum;

    return 0;
}