#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> graphpath;
int realcount = 0;
void dfs(int v, bool [], short []);
int graph[100001] = {0};
int main()
{   
    ios::sync_with_stdio(0), cin.tie(0);
    int t, n;
    
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        realcount = 0;
        cin >> n;
        short nod[100001] = {0};
        bool check[100001] = {0};

        for (int j = 1; j <= n; j++)
        {
            cin >> graph[j];
        }

        for (int j = 1; j <= n; j++)
        {
            if (check[j]==0)
            {
                check[j] = 1;
                dfs(j, check, nod);

                for (int o = 0; o < graphpath.size(); o++)
                {
                    if (nod[graphpath[o]]==0)
                    {
                        realcount++;
                        nod[graph[graphpath[o]]]--;
                    }
                    else
                    {
                        break;
                    }
                }
                graphpath.clear();
            }
        }

        cout << realcount << '\n';
    }
    
    
    return 0 ;
}

void dfs(int v, bool check[], short nod[])
{
    graphpath.push_back(v);
    nod[graph[v]]++;
    
    if (check[graph[v]]==0)
    {
        check[graph[v]] = 1;
        dfs(graph[v], check, nod);
    }
    
    return;    
}