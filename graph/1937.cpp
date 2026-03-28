#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int graph[501][501] = {0};
int check[501][501] = {0};
int n;
int graph_max = 0;

void dfs(int x, int y);
int main()
{   
    ios::sync_with_stdio(0), cin.tie(0);
    
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
        
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (check[i][j]==0)
            {
                dfs(i,j);
            }
        } 
    }

    cout << graph_max;
    
    return 0 ;
}

void dfs(int x, int y)
{
    check[x][y] = 1;
    int temp=0;
    if (x+1!=n&&(graph[x+1][y]<graph[x][y]))
    {
        if (check[x+1][y]==0)
        {
            dfs(x+1,y);
        }
        
        if (temp < check[x+1][y])
        {
            temp = check[x+1][y];
        }
        
    }
    if (x-1!=-1&&(graph[x-1][y]<graph[x][y]))
    {
        if (check[x-1][y]==0)
        {
            dfs(x-1,y);
        }
        
        if (temp < check[x-1][y])
        {
            temp = check[x-1][y];
        }
    }
    if (y+1!=n&&(graph[x][y+1]<graph[x][y]))
    {
        if (check[x][y+1]==0)
        {
            dfs(x,y+1);
        }
        
        if (temp < check[x][y+1])
        {
            temp = check[x][y+1];
        }
    }
    if (y-1!=-1&&(graph[x][y-1]<graph[x][y]))
    {
        if (check[x][y-1]==0)
        {
            dfs(x,y-1);
        }
        
        if (temp < check[x][y-1])
        {
            temp = check[x][y-1];
        }
    }

    check[x][y] += temp;
    if (graph_max<check[x][y])
    {
        graph_max = check[x][y];
    }
    return;
}