#include <iostream>
#include <vector>
using namespace std;

int r, c;
int alpha[26]={0};
char graph[20][20]={0};
int count = 1, mmax = 1;
void dfs(int x, int y);

int main(void)
{
    

    cin >> r >> c;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> graph[i][j];
        }
    }
    
    alpha[graph[0][0]-'A']++;
    dfs(0,0);

    cout << mmax;

    return 0;
}

void dfs(int x, int y)
{
    if (x+1!=r&&(alpha[graph[x+1][y]-'A']==0))
    {
        count++;
        alpha[graph[x+1][y]-'A']++;
        dfs(x+1,y);
        alpha[graph[x+1][y]-'A']--;
        count--;
    }
    if (y+1!=c&&(alpha[graph[x][y+1]-'A']==0))
    {
        count++;
        alpha[graph[x][y+1]-'A']++;
        dfs(x,y+1);
        alpha[graph[x][y+1]-'A']--;
        count--;
    }
    if (x-1!=-1&&(alpha[graph[x-1][y]-'A']==0))
    {
        count++;
        alpha[graph[x-1][y]-'A']++;
        dfs(x-1,y);
        alpha[graph[x-1][y]-'A']--;
        count--;
    }
    if (y-1!=-1&&(alpha[graph[x][y-1]-'A']==0))
    {
        count++;
        alpha[graph[x][y-1]-'A']++;
        dfs(x,y-1);
        alpha[graph[x][y-1]-'A']--;
        count--;
    }

    if (mmax<count)
    {
        mmax=count;
    }
    
    return;
}