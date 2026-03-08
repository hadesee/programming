#include <iostream>
#include <string>

void luckeystring(int alen, char a);
int alpha[26] = {0};
int len;
int count = 0;

using namespace std;
int main(void)
{
    string word;

    cin >> word;

    len = word.length();
    

    for (int i = 0; i < len; i++)
    {
        alpha[word[i]-'a']++;
    }
    
    for (int i = 0; i < 26; i++)
    {
        char b = i + 97;
        if (alpha[i]>0)
        {
            alpha[i]--;
            luckeystring(1,b);
            alpha[i]++;
        }
        
    }
    
    cout << count;

    return 0;
}

void luckeystring(int alen, char a)
{
    if (alen==len)
    {
        count++;
        return;
    }
    
    for (int i = 0; i < 26; i++)
    {
        char b = i + 97;
        if (alpha[i]>0&&(a != b))
        {
            alpha[i]--;
            luckeystring(alen+1,b);
            alpha[i]++;
        }
        
    }

    return;
    
}
