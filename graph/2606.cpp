#include <iostream>
#include <queue>
using namespace std;

int matrix[101][101] = {0};
int end_mat[101] = {0};
int n, m, start=1;
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

        end_mat[a] = -1;
        end_mat[b] = -1;
        matrix[a][b] = 1;
        matrix[b][a] = 1;
    }
    
    end_mat[start] = 1;

    dfs(start);

    cout << count;

    return 0;
}

void dfs(int v)
{
    for (int i = 1; i <= n; i++)
    {
        if (matrix[v][i]==1&&(end_mat[i]==-1)&&(i!=v))
        {
            count++;
            end_mat[i] = 1;
            dfs(i);
        }
    }
    
    return;
}

