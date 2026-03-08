#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;
int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0);
    string word;
    unordered_set<string> diction;

    cin >> word;

    if (word.back()=='\n')
    {
        word.pop_back();
    }
    

    int length = word.length();
    int count = 0;
    for (int i = 1; i <= length; i++)
    {
        for (int j = 0; j+i-1 < length; j++)
        {
            diction.emplace(word.substr(j,i));
        }
        
    }
    
    cout << diction.size();

    return 0;
}