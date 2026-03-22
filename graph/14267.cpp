#include <iostream>
#include <vector>
using namespace std;

short check[100001] = {0};
int score[100001] = {0};
int n,m;
vector<int> graph[100001];

void dfs(int v, int previus);
int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    int a, b;

    cin >> a;

    for (int i = 2; i <= n; i++)
    {
        cin >> a;
        graph[a].push_back(i);
    }

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;

        score[a] += b;
    }

    dfs(1, 0);    
    
    for (int i = 1; i <= n; i++)
    {
        cout << score[i] << ' ';
    }
    
    return 0;
}

void dfs(int v, int previus)
{
    score[v] += score[previus];
    for (int i = 0; i < graph[v].size(); i++)
    {
        dfs(graph[v][i],v);
    }
    return;
}