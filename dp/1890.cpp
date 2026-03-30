#include <iostream>

using namespace std;

long long board[100][100]={0};
long long check[100][100]={0};
int n;
void dp(int x, int y);
int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0);
    
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }
    
    check[0][0] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (check[i][j]!=0&&board[i][j]!=0)
            {
                dp(i,j);
            }
            
        }
    }

    cout << check[n-1][n-1];

    return 0;
}

void dp(int x, int y)
{   
    int temp = board[x][y];

    if (x+temp<n)
    {
        check[x+temp][y] += check[x][y];
    }
    
    if (y+temp<n)
    {
        check[x][y+temp] += check[x][y];
    }

    return;
}