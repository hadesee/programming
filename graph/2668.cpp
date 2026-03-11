#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
이 문제의 경우 매우 복잡해보이지만 단순한 풀이로 풀 수 있음 즉 첫번째 줄은 1..2...3 이런 식으로 n까지 구성
두번째 줄은 1~n이 랜덤으로 구성되며 중복이 있을 수 있음 첫번째 두번째 줄에서 각 열을 뽑았을때 서로의 집합이 동일해야함
근데 생각해보면 첫번째 줄은 고정이기에 즉 4열 == 4이기에 두번째 줄에 달렸음 만약 1행 4열이 4인데 2행 4열도 4라면 그자체로 하나의 집합이 완성된것임 즉 1행 4열과 2행 4열이 같다면 
그자체로 하나의 집합이 완성된것임
즉 어떤 노드를 고르고 짝이 맞도록 추적해나아갈때 다시 자기 자신으로 돌아온다면 그 노드와 지나온 노드 모두가 하나의 집합이 되는것임
*/
int ccount = 0;
void numsearch(int v, int d);
int check[101] = {0}, graph[2][101] = {0};
vector<int> vec;
int main()
{   
    int n;
    int a;
    
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        graph[2][i] = a;
        graph[1][i] = i;
        if (a == i)
        {
            check[i] = 1;
            ccount++;
        }    
    }

    for (int i = 1; i <= n; i++)
    {
        if (check[i]==0)
        {
            vec.push_back(i);
            numsearch(graph[2][i],i);
            vec.clear();
        }
    }
    
    cout << ccount << '\n';

    for (int i = 1; i <= n; i++)
    {
        if (check[i]==1)
        {
            cout << i << '\n';
        }
        
    }
    
    return 0 ;
}

void numsearch(int v, int d)
{
    cout << v << ' ' << d << " start" << '\n';
    bool numbool = binary_search(vec.begin(),vec.end(), v);
    if (numbool==0&&(check[v]==0))
    {
        vec.push_back(v);
        if (graph[2][v]==d)
        {
            for (int i = 0; i < vec.size(); i++)
            {
                check[vec[i]] = 1;
                ccount++;
            }
            return;
        }
        
        numsearch(graph[2][v],d);
    }
    
    return;    
}