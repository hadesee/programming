#include <iostream>
#include <queue>
using namespace std;

int matrix[1001][1001] = {0};
int end_mat[1001] = {0};
int n, m;
int count = 0;
int a,b;
void dfs(int v);

int main(void)
{
    ios::sync_with_stdio(0),cin.tie(0);
    cin >> n;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        matrix[a][b] = 1;
        matrix[b][a] = 1;
    }
    
    for (int i = 1; i <= n; i++)
    {
        if (end_mat[i]==0)
        {
            count++;
            end_mat[i] = 1;
            dfs(i);
        }
    }

    cout << count;

    return 0;
}

void dfs(int v)
{
    for (int i = 1; i <= n; i++)
    {
        if (matrix[v][i]==1&&(end_mat[i]==0)&&(i!=v))
        {
            end_mat[i] = 1;
            dfs(i);
        }
    }
    
    return;
}
