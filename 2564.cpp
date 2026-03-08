#include <iostream>
#include <string>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0);
    int l, m, n; // 가로, 세로, 상점 개수
    // 1북 2남 3서 4동
    int blolen, feet = 0;
    cin >> l >> m;
    cin >> n;
    blolen = 2 * l + 2 * m;
    int block[m + 1][l + 1] = {0};
    int row, col;
    int a, b;
    int sum = 0, direct = 0;

    for (int i = 0; i < n + 1; i++)
    {
        cin >> a >> b;
        if (a == 1)
        {
            row = 0;
            col = b;
        }
        else if (a == 2)
        {
            row = m;
            col = b;
        }
        else if (a == 3)
        {
            col = 0;
            row = b;
        }
        else
        {
            col = l;
            row = b;
        }

        block[row][col] = 1;
    }

    direct = a;
    a = row;
    b = col;

    while (1)
    {
        if (direct == 1)
        {
            b++;
        }
        else if (direct == 2)
        {
            b--;
        }
        else if (direct == 3)
        {
            a--;
        }
        else
        {
            a++;
        }

        if (a < 0 || a > m || b < 0 || b > l)
        {
            if (direct == 1)
            {
                direct = 4;
                b--;
            }
            else if (direct == 2)
            {
                direct = 3;
                b++;
            }
            else if (direct == 3)
            {
                direct = 1;
                a++;
            }
            else
            {
                direct = 2;
                a--;
            }

            continue;
        }

        feet++;

        if (block[a][b]==1)
        {
            if (feet<=(blolen-feet))
            {
                sum += feet;
            }
            else
            {
                sum += blolen - feet;
            }
            
            n--;
        }
        
        if (n==0)
        {
            break;
        }
        
    }

    cout << sum;

    return 0;
}