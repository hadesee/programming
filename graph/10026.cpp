#include <iostream>
#include <vector>
using namespace std;

int matrix[100][100] = {0};
char charmat[100][100] = {0};
int end_mat[] = {0};
int n, cc=0;
int house = 0;
char c;
void dfs(int x, int y, char s);
void dfsrg(int x, int y);

int main(void)
{
    ios::sync_with_stdio(0),cin.tie(0);
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> c;
            charmat[i][j] = c;
        }
    }

    for (int i = 0; i < n; i++)
    {
        
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j]==0)
            {
                house++;
                matrix[i][j] = 1;
                dfs(i,j,charmat[i][j]);
            }
        }
    }

    cout << house << '\n';

    house = 0;
    cc=1;

    for (int i = 0; i < n; i++)
    {
        
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j]==1)
            {
                house++;
                matrix[i][j] = cc+1;
                if (charmat[i][j]=='B')
                {
                    dfs(i,j,charmat[i][j]);
                }
                else
                {
                    dfsrg(i,j);
                }
            }
        }
    }

    cout << house << '\n';

    return 0;
}

void dfs(int x, int y, char s)
{

    if (x + 1 != n && (matrix[x + 1][y] == cc)&&(charmat[x+1][y]==s))
    {
        matrix[x + 1][y] = cc+1;
        dfs(x + 1, y, s);
    }

    if (x - 1 != -1 && (matrix[x - 1][y] == cc)&&(charmat[x-1][y]==s))
    {
        matrix[x - 1][y] = cc+1;
        dfs(x - 1, y, s);
    }

    if (y + 1 != n && (matrix[x][y + 1] == cc)&&(charmat[x][y+1]==s))
    {
        matrix[x][y + 1] = cc+1;
        dfs(x, y + 1, s);
    }

    if (y - 1 != -1 && (matrix[x][y - 1] == cc)&&(charmat[x][y-1]==s))
    {
        matrix[x][y - 1] = cc+1;
        dfs(x, y - 1, s);
    }

    return;
}


void dfsrg(int x, int y)
{
    if (x + 1 != n && (matrix[x + 1][y] == cc)&&((charmat[x+1][y]=='R')||(charmat[x+1][y]=='G')))
    {
        matrix[x + 1][y] = cc+1;
        dfsrg(x + 1, y);
    }

    if (x - 1 != -1 && (matrix[x - 1][y] == cc)&&((charmat[x-1][y]=='R')||(charmat[x-1][y]=='G')))
    {
        matrix[x - 1][y] = cc+1;
        dfsrg(x - 1, y);
    }

    if (y + 1 != n && (matrix[x][y + 1] == cc)&&((charmat[x][y+1]=='R')||(charmat[x][y+1]=='G')))
    {
        matrix[x][y + 1] = cc+1;
        dfsrg(x, y + 1);
    }

    if (y - 1 != -1 && (matrix[x][y - 1] == cc)&&((charmat[x][y-1]=='R')||(charmat[x][y-1]=='G')))
    {
        matrix[x][y - 1] = cc+1;
        dfsrg(x, y - 1);
    }

    return;
    
}