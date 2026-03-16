 -10000;
int mmin = 10000;
int n;

int main(void)
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }

    sum = graph[0][0] - '0';

    dfs(0, 0);

    cout << mmax << ' ' << mmin;

    return 0;
}

void dfs(int x, int y)
{
    char pms;
    int num = sum;
    if ((x == n - 1) && (y == n - 1))
    {
        if (sum < mmin)
        {
            mmin = sum;
        }
        if (sum > mmax)
        {
            mmax = sum;
        }
        return;
    }

    if ((x + 1 < n) && (y + 1 < n))
    {
        pms = graph[x + 1][y];
        if (pms == '+')
        {
            sum += graph[x + 1][y + 1] - '0';
            dfs(x + 1, y + 1);
            sum -= graph[x + 1][y + 1] - '0';
        }
        else if (pms == '-')
        {
            sum -= graph[x + 1][y + 1] - '0';
            dfs(x + 1, y + 1);
            sum += graph[x + 1][y + 1] - '0';
        }
        else
        {
            sum *= graph[x + +1][y + 1] - '0';
            dfs(x + 1, y + 1);

            sum = num;
        }

        pms = graph[x][y + 1];

        if (pms == '+')
        {
            sum += graph[x + 1][y + 1] - '0';
            dfs(x + 1, y + 1);
            sum -= graph[x + 1][y + 1] - '0';
        }
        else if (pms == '-')
        {
            sum -= graph[x + 1][y + 1] - '0';
            dfs(x + 1, y + 1);
            sum += graph[x + 1][y + 1] - '0';
        }
        else
        {
            sum *= graph[x + +1][y + 1] - '0';
            dfs(x + 1, y + 1);
            sum = num;
        }
    }

    if ((x + 2 < n))
    {
        pms = graph[x + 1][y];

        if (pms == '+')
        {
            sum += graph[x + 2][y] - '0';
            dfs(x + 2, y);
            sum -= graph[x + 2][y] - '0';
        }
        else if (pms == '-')
        {
            sum -= graph[x + 2][y] - '0';
            dfs(x + 2, y);
            sum += graph[x + 2][y] - '0';
        }
        else
        {
            sum *= graph[x + 2][y] - '0';
            dfs(x + 2, y);
            sum = num;
        }
    }
    if ((y + 2 < n))
    {
        pms = graph[x][y + 1];

        if (pms == '+')
        {
            sum += graph[x][y + 2] - '0';
            dfs(x, y + 2);
            sum -= graph[x][y + 2] - '0';
        }
        else if (pms == '-')
        {
            sum -= graph[x][y + 2] - '0';
            dfs(x, y + 2);
            sum += graph[x][y + 2] - '0';
        }
        else
        {
            sum *= graph[x][y + 2] - '0';
            dfs(x, y + 2);
            sum = num;
        }
    }

    return;
}