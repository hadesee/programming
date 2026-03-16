#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    string word;

    cin >> n;

    for (int j = 0; j < n; j++)
    {
        cin >> word;

        for (int i = 0; i < word.length(); i++)
        {
            word[i] = tolower(word[i]);
        }

        cout << word << '\n';
    }

    return 0;
}