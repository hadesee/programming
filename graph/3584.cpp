#include <iostream>
#include <vector>
using namespace std;

int t, n, root;
int a, b, solve;

vector<int> graph[10001];

void dfs(int v, int []);

int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        solve=0;
        cin >> n;
        int check[10001]={0};

        for (int j = 1; j < n; j++)
        {
            cin >> a >> b;
            graph[a].push_back(b);
            check[b] = -1;
        }

        cin >> a >> b;

        for (int j = 1; j <= n; j++)
        {
            if (check[j]==0)
            {
                root = j;
                check[j] = -1;
                break;
            }
        }

        dfs(root, check);

        cout << solve << '\n';

        for (int j = 1; j <= n; j++)
        {
            graph[j].clear();
        }
    }

    return 0;
}

void dfs(int v, int check[])
{
    if (solve!=0)
    {
        return;
    }
    
    check[v] = 1;

    if (v==a||v==b)
    {
        check[v]++;
    }
    

    if (graph[v].size() == 0)
    {
        return;
    }

    for (int i = 0; i < graph[v].size(); i++)
    {
        if (check[graph[v][i]] == -1)
        {
            dfs(graph[v][i], check);
            check[v] += check[graph[v][i]] - 1;
        }
    }

    if (check[v]==3)
    {
        solve = v;
        check[v] = 1;
    }
    

    return;
}