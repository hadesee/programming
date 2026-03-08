#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int matrix[25][25] = {0};
int end_mat[] = {0};
int n;
int house = 0, ccount = 0;
char c;
void dfs(int x, int y);
vector<int> vec;

int main(void)
{
    ios::sync_with_stdio(0),cin.tie(0);
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> c;
            matrix[i][j] = c-'0';
        }
    }

    for (int i = 0; i < n; i++)
    {
        
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j]>0)
            {
                house++;
                ccount++;
                matrix[i][j] = -1;
                dfs(i,j);
                vec.push_back(ccount);
                ccount=0;
            }
        }
    }

    sort(vec.begin(),vec.end());

    cout << house << '\n';

    for (int i = 0; i < house; i++)
    {
        cout << vec[i] << '\n';
    }  

    return 0;
}

void dfs(int x, int y)
{

    if (x + 1 != n && (matrix[x + 1][y] == 1))
    {
        ccount++;
        matrix[x + 1][y] = -1;
        dfs(x + 1, y);
    }

    if (x - 1 != -1 && (matrix[x - 1][y] == 1))
    {
        ccount++;
        matrix[x - 1][y] = -1;
        dfs(x - 1, y);
    }

    if (y + 1 != n && (matrix[x][y + 1] == 1))
    {
        ccount++;
        matrix[x][y + 1] = -1;
        dfs(x, y + 1);
    }

    if (y - 1 != -1 && (matrix[x][y - 1] == 1))
    {
        ccount++;
        matrix[x][y - 1] = -1;
        dfs(x, y - 1);
    }

    return;
}
