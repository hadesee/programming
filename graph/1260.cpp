#include <iostream>
#include <queue>
using namespace std;

int matrix[1001][1001] = {0};
int end_mat[1001] = {0};
int n, m, start;
int a,b;
void dfs(int v);

queue<int> q;
int main(void)
{
    ios::sync_with_stdio(0),cin.tie(0);
    cin >> n >> m >> start;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;

        end_mat[a] = -1;
        end_mat[b] = -1;
        matrix[a][b] = 1;
        matrix[b][a] = 1;
    }
    
    end_mat[start] = 1;

    cout << start << ' ';
    dfs(start);

    cout << '\n';
    end_mat[start] = -1;

    cout << start << ' ';

    q.push(start);
    while (q.size()>0)
    {
        int current = q.front();
        q.pop();

        for (int i = 1; i <= n; i++)
        {
            if (matrix[current][i]==1&&(end_mat[i]==1)&&(i!=current))
            {
                end_mat[i] = -1;
                cout << i << ' ';
                q.push(i);
            }
        }
        
    }
      
    return 0;
}

void dfs(int v)
{
    for (int i = 1; i <= n; i++)
    {
        if (matrix[v][i]==1&&(end_mat[i]==-1)&&(i!=v))
        {
            end_mat[i] = 1;
            cout << i << ' ';
            dfs(i);
        }
    }
    
    return;
}

