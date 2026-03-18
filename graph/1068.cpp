#include <iostream>
#include <vector>
using namespace std;

int n, aim, count =0;
int graph[50]={0};
vector<int> graphnode[50];

void dfs(int v);
int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> graph[i];

        if (graph[i]>=0)
        {
            graphnode[graph[i]].push_back(i);
        }
        
    }

    cin >> aim;

    if (graph[aim]>=0)
    {
        for (int i = 0; i < graphnode[graph[aim]].size(); i++)
        {
            if (graphnode[graph[aim]][i]==aim)
            {
                graphnode[graph[aim]].erase(graphnode[graph[aim]].begin()+i);   
            }
            
        }
        
    }
    

    dfs(aim); 
    
    for (int i = 0; i < n; i++)
    {
        if (graph[i]>-2&&(graphnode[i].size()==0))
        {
            count++;
        }
        
    }
    
    cout << count;

    return 0;
}

void dfs(int v)
{
    graph[v] = -2;

    for (int i = 0; i < graphnode[v].size(); i++)
    {
        dfs(graphnode[v][i]);
    }

    return;
}
