#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int n, m;
int sig = 0, land = 0, cc = 0, year=0;
int graph[301][301] = {0};
int check[301][301] = {0};
vector<tuple<int, int, int>> ice;
void dfs(int x, int y);
int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> graph[i][j];
            if (graph[i][j] > 0)
            {
                ice.push_back({i, j, graph[i][j]});
            }
        }
    }

    while (1)
    {
        for (auto &[a, b, c] : ice)
        {
            if (graph[a - 1][b] == 0)
            {
                c--;
            }
            if (graph[a + 1][b] == 0)
            {
                c--;
            }
            if (graph[a][b - 1] == 0)
            {
                c--;
            }
            if (graph[a][b + 1] == 0)
            {
                c--;
            }

            if (c <= 0)
            {
                c = 0;
                sig=1;
            }
        }

        for (auto &[a, b, c] : ice)
        {
            graph[a][b] = c;
        }

        ice.erase(remove_if(ice.begin(), ice.end(), [](const auto &t)
                            { return get<2>(t) == 0; }),
                  ice.end());

        if (sig == 1)
        {
            for (auto &[a, b, c] : ice)
            {
                if (check[a][b] == cc)
                {
                    check[a][b]++;
                    dfs(a, b);
                    land++;
                }
            }
            if (land > 1)
            {
                cout << year + 1;
                break;
            }
            else if (land == 0)
            {
                cout << 0;
                break;
            }
            land = 0;
            cc++;
            sig = 0;
        }
        year++;
    }


    return 0;
}

void dfs(int x, int y)
{
    if (graph[x + 1][y] != 0 && check[x + 1][y] == cc)
    {
        check[x + 1][y]++;
        dfs(x + 1, y);
    }
    if (graph[x - 1][y] != 0 && check[x - 1][y] == cc)
    {
        check[x - 1][y]++;
        dfs(x - 1, y);
    }
    if (graph[x][y - 1] != 0 && check[x][y - 1] == cc)
    {
        check[x][y - 1]++;
        dfs(x, y - 1);
    }
    if (graph[x][y + 1] != 0 && check[x][y + 1] == cc)
    {
        check[x][y + 1]++;
        dfs(x, y + 1);
    }

    return;
}