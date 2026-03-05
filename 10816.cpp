#include <iostream>
#include <unordered_map>

using namespace std;
int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0);
    unordered_map<int, int> card;
    int n, m, num;

    cin >> n;

    card.reserve(n);

    for (int i = 0; i < n; i++)
    {
        cin >> num;

        if (card.find(num) == card.end())
        {
            card.emplace(num,1);
        }
        else
        {
            card[num] += 1;
        }
    }

    cin >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> num;

        if (card.find(num) != card.end())
        {
            cout << card[num] << ' ';
        }
        else
        {
            cout << 0 << ' ';
        }
    }
    
    return 0;
}