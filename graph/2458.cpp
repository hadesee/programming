#include <iostream>
#include <vector>
using namespace std;

int n, m, result = 0, count =0;
int a,b;
vector<int> graph1[501];
vector<int> graph2[501];

void dfs1(int v, int []);
void dfs2(int v, int []);
int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        
        graph1[a].push_back(b);
        graph2[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        int check[501] = {0};
        count=1;
        dfs1(i,check);
        dfs2(i,check);
        if (n==count)
        {
            result++;
        }
        
    }
 
    cout << result;

    return 0;
}

void dfs1(int v, int check[])
{
    for (int i = 0; i < graph1[v].size(); i++)
    {
        if (check[graph1[v][i]]==0)
        {
            count++;
            check[graph1[v][i]] = 1;
            dfs1(graph1[v][i],check);
        } 
    }

    return;
}

void dfs2(int v, int check[])
{
    for (int i = 0; i < graph2[v].size(); i++)
    {
        if (check[graph2[v][i]]==0)
        {
            count++;
            check[graph2[v][i]] = 1;
            dfs2(graph2[v][i],check);
        } 
    }

    return;
}