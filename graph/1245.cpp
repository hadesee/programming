#include <iostream>
#include <vector>

using namespace std;

int n, m;
int graph[100][70] = {0};
int check[100][70] = {0};
int out[100][70] = {0};
int outsignal = 0;
int count = 0;
vector<pair<int,int>> vec;

void dfs(int x, int y);

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> graph[i][j];
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (check[i][j]==0)
            {
                check[i][j] = 1;
                dfs(i,j);

                if (outsignal==0)
                {
                    count++;
                }

                outsignal = 0;
            }
            
        }
    }
    
    cout << count;

    return 0;
}

void dfs(int x, int y)
{
    for (int i = x-1; i <=x+1; i++)
    {
        for (int j = y-1; j <= y+1; j++)
        {
            if (i>=0&&(i<n)&&(j>=0)&&(j<m)&&!((i==x)&&(j==y)))
            {
                if (graph[i][j]>graph[x][y])
                {
                    outsignal = 1;
                }
                
                if (graph[i][j]==graph[x][y]&&(check[i][j]==0))
                {
                    check[i][j] = 1;
                    dfs(i,j);
                }
            }
            
        }
        
    }

    return;
}