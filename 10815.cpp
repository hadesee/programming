#include <iostream>
#include <unordered_set>

using namespace std;
int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0);
    unordered_set<int> card;
    int n, m, num;

    cin >> n;

    card.reserve(n);

    for (int i = 0; i < n; i++)
    {
        cin >> num;
        card.emplace(num);
    }

    cin >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> num;

        if (card.find(num) != card.end())
        {
            cout << 1 << ' ';
        }
        else
        {
            cout << 0 << ' ';
        }
    }
    
    return 0;
}