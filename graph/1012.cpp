#include <iostream>
#include <queue>
using namespace std;

int matrix[51][51] = {0};
int n, m, total;
int count = 0;
int a, b;
int k;
void dfs(int x, int y);
int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0);
    int t;

    cin >> t;

    for (k = 1; k <= t; k++)
    {
        count =0;
        cin >> m >> n >> total;

        for (int i = 0; i < total; i++)
        {
            cin >> a >> b;
            matrix[a][b] = k;
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == k)
                {
                    matrix[i][j] = -1;
                    count++;
                    dfs(i, j);
                }
            }
        }

        cout << count << '\n';
    }

    return 0;
}

void dfs(int x, int y)
{

    if (x + 1 != m && (matrix[x + 1][y] == k))
    {
        matrix[x + 1][y] = -1;
        dfs(x + 1, y);
    }

    if (x - 1 != -1 && (matrix[x - 1][y] == k))
    {
        matrix[x - 1][y] = -1;
        dfs(x - 1, y);
    }

    if (y + 1 != n && (matrix[x][y + 1] == k))
    {
        matrix[x][y + 1] = -1;
        dfs(x, y + 1);
    }

    if (y - 1 != -1 && (matrix[x][y - 1] == k))
    {
        matrix[x][y - 1] = -1;
        dfs(x, y - 1);
    }

    return;
}