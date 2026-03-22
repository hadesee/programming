#include <iostream>
#include <vector>
using namespace std;

int t, n, m;
vector<int> graph[20001];
int impossible = 0;
void dfs(int v, int []);

int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0);
    int a, b;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        impossible=0;
        cin >> n >> m;
        int check[n+1]={0};

        for (int j = 0; j < m; j++)
        {
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        for (int j = 1; j <= n; j++)
        {
            if (check[j]==0)
            {
                check[j]=1;
                dfs(j,check);
            }
            
        }
        
        if (impossible==1)
        {
            cout << "NO" << '\n';
        }
        else
        {
            cout << "YES" << '\n';
        }
        
        for (int i = 1; i <= n; i++)
        {
            graph[i].clear();
        }
        
        
    }
    
    return 0;
}

void dfs(int v, int check[])
{
    if (impossible==1)
    {
        return;
    }
    

    for (int i = 0; i < graph[v].size(); i++)
    {
        if (check[graph[v][i]]==check[v])
        {
            impossible = 1;
            return;
        }
        else if (check[graph[v][i]] == 0)
        {
            if (check[v]==1)
            {
                check[graph[v][i]] = 2;
            }
            else
            {
                check[graph[v][i]] = 1;
            }
            dfs(graph[v][i],check);
        }   
    }
    return;
}