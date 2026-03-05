#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;
int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    unordered_map<string, int>coop;
    string word, command;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> word >> command;
        if (command=="enter")
        {
            coop.emplace(word,1);
        }
        else
        {
            coop.erase(word);
        }    
    }
    
    vector<string> left_people;
    
    for (const auto& pair : coop) 
    {
        left_people.push_back(pair.first);
    }

    sort(left_people.begin(),left_people.end());

    for (auto i = left_people.rbegin(); i !=left_people.rend(); i++)
    {
        cout << *i << '\n';
    }
    
    

    return 0;
}