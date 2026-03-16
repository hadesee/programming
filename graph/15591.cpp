#include <iostream>
#include <vector>
using namespace std;

vector<pair<int,int>> graph[5001];
int cunt=0;

void dfs(int d, int v, int []);
int main(void)
{
    int n, q;
    int a, b, c;

    cin >> n >> q;

    for (int i = 1; i < n; i++)
    {
        cin >> a >> b >> c;

        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    
    for (int i = 0; i < q; i++)
    {
        int check[5001] = {0};
        cunt = 0;
        cin >> a >> b;

        check[b]=1;
        dfs(a,b,check);
        cout << cunt << '\n';
    }
    
    return 0;
}

void dfs(int d, int v, int check[])
{
    for (int i = 0; i < graph[v].size(); i++)
    {
        if (graph[v][i].second>=d&&(check[graph[v][i].first]==0))
        {
            cunt++;
            check[graph[v][i].first]=1;
            dfs(d, graph[v][i].first, check);
        }
        
    }

    return;
}