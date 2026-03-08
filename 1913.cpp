#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;
int main(void)
{   
    ios::sync_with_stdio(0),cin.tie(0);
    int n=0;
    int x, y;
    int aim;
    int aimx, aimy;

    cin >> n;
    cin >> aim;
    int nn = n*n;

    std::vector<std::vector<int>> arr(n, std::vector<int>(n));
    

    x = n / 2;
    y = n / 2;

    aimx = x;
    aimy = y;
    arr[x][y] = 1;

    int distance = 2;
    int num=1;
    

    while (num<nn)
    {
        x -= 1;
        for (int i = 0; i < distance; i++)
        {
            num++;
            arr[x][y] = num;
            if (num==aim)
            {
                aimx=x;
                aimy=y;
            }
             
            y++;
        }
        y--;
        for (int i = 0; i < distance; i++)
        {
            x++;
            num++;
            arr[x][y] = num; 
            if (num==aim)
            {
                aimx=x;
                aimy=y;
            } 
        }
        for (int i = 0; i < distance; i++)
        {
            y--;
            num++;
            arr[x][y] = num;
            if (num==aim)
            {
                aimx=x;
                aimy=y;
            } 
        }
        for (int i = 0; i < distance; i++)
        {
            x--;
            num++;
            arr[x][y] = num;
            if (num==aim)
            {
                aimx=x;
                aimy=y;
            }  
        }

        distance +=2;
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }

    cout << aimx + 1 << ' ';
    cout << aimy + 1;

    return 0;
}