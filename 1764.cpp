#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0);
    unordered_set<string> nolisten;
    string word;
    vector<string> nolistensee;

    int n, m, count = 0;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> word;
        nolisten.emplace(word);
    }
    
    for (int i = 0; i < m; i++)
    {
        cin >> word;
        if (nolisten.find(word) != nolisten.end())
        {
            count++;
            nolistensee.push_back(word);
        }
        
    }
    
    sort(nolistensee.begin(), nolistensee.end());

    cout << count << '\n';

    for (int i = 0; i < count; i++)
    {
        cout << nolistensee[i] << '\n';
    }
    

    return 0;
}