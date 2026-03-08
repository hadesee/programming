#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;
int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0);
    unordered_set<int> a;
    unordered_set<int> b;
    int n, m;
    int num, count=0;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> num;
        a.emplace(num);
    }
    
    for (int i = 0; i < m; i++)
    {
        cin >> num;

        if (a.find(num) != a.end())
        {
            count++;
        }
        
    }
    
    cout << n+m-2*count;

    return 0;
}