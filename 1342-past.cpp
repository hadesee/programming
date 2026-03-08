#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;
int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0);
    string word;
    string tempstr;
    unordered_set<string> set1;
    unordered_set<string> set2;
    vector<char> setalpha;
    int token = 0, alpha[26] = {0};
    cin >> word;

    int len = word.length();

    for (int i = 0; i < len; i++)
    {
        alpha[word[i]-97]++;
        setalpha.push_back(word[i]);
        set1.emplace(string(1, word[i]));
    }
    
    sort(setalpha.begin(), setalpha.end());

    setalpha.erase(unique(setalpha.begin(),setalpha.end()),setalpha.end());
    int setalpha_size = setalpha.size();

    if (len == setalpha_size)
    {
        int sum= 1;

        for (int o = 2; o <= len; o++)
        {
            sum *= o;
        }
        
        cout << sum;

        return 0;
    }
    
    
    for (int i = 1; i < len; i++)
    {
        if (token==0)
        {
            for (const auto& tempword : set1)
            {
                short tempalpha[26] = {0};

                for (int j = 0; j <i; j++)
                {
                    tempalpha[tempword[j]-97]++;
                }
                
                for (int s = 0; s < setalpha_size; s++)
                {
                    if ((setalpha[s]!=tempword[i-1])&&((alpha[setalpha[s]-97] - tempalpha[setalpha[s]-97])>0))
                    {
                        tempstr = tempword + setalpha[s];
                        set2.emplace(tempstr);
                    }       
                }
                
            }
            set1.clear();
            token = 1;
        }
        else
        {
            for (const auto& tempword : set2)
            {
                short tempalpha[26] = {0};

                for (int j = 0; j <i; j++)
                {
                    tempalpha[tempword[j]-97]++;
                }
                
                for (int s = 0; s < setalpha_size; s++)
                {
                    if ((setalpha[s]!=tempword[i-1])&&((alpha[setalpha[s]-97] - tempalpha[setalpha[s]-97])>0))
                    {
                        tempstr = tempword + setalpha[s];
                        set1.emplace(tempstr);
                    }       
                }
                
            }
            set2.clear();
            token = 0;
        }
        
        
    }
    
    if (token==0)
    {
        cout << set1.size();
    }
    else
    {
        cout << set2.size();
    }

    return 0;
}