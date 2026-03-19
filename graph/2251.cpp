#include <iostream>
#include <vector>
#include <tuple>
#include <set>
#include <algorithm>

using namespace std;

int aa, bb, cc;

vector<int> vec;
set<tuple<int, int, int>> setting;

void dfs(int a, int b, int c);
int main(void)
{
    cin >> aa >> bb >> cc;

    setting.emplace(0,0,cc);

    dfs(0, 0, cc);


    for (const auto& [first, second, third] : setting) {
        if (first == 0)
        {
            vec.push_back(third);
        }    
    }

    sort(vec.begin(),vec.end());

    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << ' ';
    }

    return 0;
}

void dfs(int a, int b, int c)
{
    if (a>0)
    {
        if (bb!=b&&(bb-b<a))
        {
            if (setting.find({a-(bb-b),bb,c}) == setting.end())
            { 
                setting.emplace(a-(bb-b),bb,c);
                dfs(a-(bb-b), bb, c);
            }  
        }
        else if (bb!=b&&(bb-b>=a))
        {
            if (setting.find({0, b+a, c}) == setting.end())
            {
                setting.emplace(0, b+a, c);
                dfs(0, b+a, c);
            } 
        }
        
        if (cc!=c&&(cc-c<a))
        {
            if (setting.find({a-(cc-c), b, cc}) == setting.end())
            {
                setting.emplace(a-(cc-c), b, cc);
                dfs(a-(cc-c), b, cc);
            } 
        }
        else if (cc!=c&&(cc-c>=a))
        {
            if (setting.find({0, b, a+c}) == setting.end())
            {
                setting.emplace(0, b, a+c);
                dfs(0, b, a+c);
            } 
        }
        
    }

    if (b>0)
    {
        if (aa!=a&&(aa-a<b))
        {
            if (setting.find({aa, b-(aa-a), c}) == setting.end())
            {
                setting.emplace(aa, b-(aa-a), c);
                dfs(aa, b-(aa-a), c);
            } 
        }
        else if (aa!=a&&(aa-a>=b))
        {
            if (setting.find({a+b, 0, c}) == setting.end())
            {
                setting.emplace(a+b, 0, c);
                dfs(a+b, 0, c);
            } 
        }

        if (cc!=c&&(cc-c<b))
        {
            if (setting.find({a, b-(cc-c), cc}) == setting.end())
            {
                setting.emplace(a, b-(cc-c), cc);
                dfs(a, b-(cc-c), cc);
            } 
        }
        else if (cc!=c&&(cc-c>=b))
        {
            if (setting.find({a, 0, c+b}) == setting.end())
            {
                setting.emplace(a, 0, c+b);
                dfs(a, 0, c+b);
            } 
        }
    }

    if (c>0)
    {
        if (bb!=b&&(bb-b<c))
        {
            if (setting.find({a, bb, c-(bb-b)}) == setting.end())
            {
                setting.emplace(a, bb, c-(bb-b));
                dfs(a, bb, c-(bb-b));
            }  
        }
        else if (bb!=b&&(bb-b>=c))
        {
            if (setting.find({a, b+c, 0}) == setting.end())
            {
                setting.emplace(a, b+c, 0);
                dfs(a, b+c, 0);
            } 
        }
        
        if (aa!=a&&(aa-a<c))
        {
            if (setting.find({aa, b, c-(aa-a)}) == setting.end())
            {
                setting.emplace(aa, b, c-(aa-a));
                dfs(aa, b, c-(aa-a));
            } 
        }
        else if (aa!=a&&(aa-a>=c))
        {
            if (setting.find({a+c, b, 0}) == setting.end())
            {
                setting.emplace(a+c, b, 0);
                dfs(a+c, b, 0);
            } 
        }
        
    }
    
    return;
}
