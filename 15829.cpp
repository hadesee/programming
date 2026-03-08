#include <iostream>
#include <string>

long long mod(int num, long long a);
long long r, ms=1234567891, sum=0;

using namespace std;
int main(void)
{
    ios::sync_with_stdio(0),cin.tie(0);
    
    int n;
    string word;

    cin >> n;
    cin >> word;

    for (int i = 0; i < n; i++)
    {
        sum += (word[i]-'a'+1)*mod(i,31);
    }
    
    sum = sum%ms;

    cout << sum;

    return 0;
}

long long mod(int num, long long a)
{
    if (num==0)
    {
        return 1;
    }
    
    return (a*mod(num-1,a))%ms;
}
