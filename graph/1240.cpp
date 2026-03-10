#include <iostream>

using namespace std;
/*시간이 많이 소요된 문제 아마도 bfs dfs의 문제라기 보단 갈 수 있는 길을 찾는 과정에서 벌어지는 시간 소요때문으로 추측 즉 배열로 구성했기때문에 */
int graph[1001][1001] = {0};

void dfs(int s, int d, int arr[]);
int a, b, c;
int n, m, token = 0;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;

    for (int i = 1; i < n; i++)
    {
        cin >> a >> b >> c;
        graph[a][b] = c;
        graph[b][a] = c;
    }

    for (int i = 0; i < m; i++)
    {
        int check[1001] = {0};
        c = 0;
        cin >> a >> b;
        check[a] = 1;
        dfs(a, b, check);
        token--;
    }
}

void dfs(int s, int d, int arr[])
{
    for (int i = 1; i <= n; i++)
    {
        if (graph[s][i] != 0 && arr[i] == 0)
        {
            arr[i]++;
            c += graph[s][i];

            if (i == d)
            {
                cout << c << '\n';
                token = 1;
                return;
            }
            

            dfs(i, d, arr);

            if (token == 1)
            {
                return;
            }

            c -= graph[s][i];
        }
    }

    return;
}