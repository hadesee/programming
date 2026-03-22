#include <iostream>
#include <vector>
using namespace std;

int n, r, q;
int a, b;

vector<int> graph[100001];
int check[100001] = {0};

void dfs(int v);

int main(void)
{
    ios::sync_with_stdio(0),cin.tie(0);
    cin >> n >> r >> q;

    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(r);

    for (int i = 0; i < q; i++)
    {
        cin >> a;
        cout << check[a] << '\n';
    }  

    return 0;
}

void dfs(int v)
{
    check[v] = 1;

    if (graph[v].size()==0)
    {
        return;
    }

    for (int i = 0; i < graph[v].size(); i++)
    {
        if (check[graph[v][i]]==0)
        {
            dfs(graph[v][i]);
            check[v] += check[graph[v][i]];
        }
    }

    return;
}