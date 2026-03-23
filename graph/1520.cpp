#include <iostream>
#include <vector>
using namespace std;

int m, n;
int cc=0;
int graph[501][501] = {0};
int score[501][501] = {0};

void dfs(int x, int y);
int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> m >> n;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }
    
    score[0][0] = 1;

    dfs(m-1,n-1);

    cout << score[m-1][n-1] << '\n' << cc;

    return 0;
}

void dfs(int x, int y)
{
    cc++;
    int sum = 0;
    if ((graph[x-1][y]>graph[x][y])&&(x!=-1))
    {
        if (score[x-1][y]==0)
        {
            dfs(x-1,y);
        }
        sum+=score[x-1][y];
    }
    if ((graph[x+1][y]>graph[x][y])&&(x!=m))
    {
        if (score[x+1][y]==0)
        {
            dfs(x+1,y);
        }
        sum+=score[x+1][y];
    }
    if ((graph[x][y-1]>graph[x][y])&&(y!=-1))
    {
        if (score[x][y-1]==0)
        {
            dfs(x,y-1);
        }
        sum+=score[x][y-1];
    }
    if ((graph[x][y+1]>graph[x][y])&&(y!=n))
    {
        if (score[x][y+1]==0)
        {
            dfs(x,y+1);
        }
        sum+=score[x][y+1];
    }

    score[x][y] = sum;

    return;
}