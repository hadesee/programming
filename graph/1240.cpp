#include <iostream>

using namespace std;

int graph[1001][1001] = {0};

void dfs(int s, int d);
int a, b, c;

int main()
{
    int n, m;
    

    cin >> n >> m;

    for (int i = 1; i < n; i++)
    {
        cin >> a >> b >> c;
        graph[a][b] = c;
        graph[b][a] = c;
    }
    
    for (int i = 0; i < m; i++)
    {
        c=0;
        cin >> a >> b;
        dfs(a,b);
    }
    
    
}

void dfs(int s, int d)
{
    

}