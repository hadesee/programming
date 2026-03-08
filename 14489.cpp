#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main(void)
{   
    ios::sync_with_stdio(0),cin.tie(0);
    int d, h, t, n, sum=0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> t;
        sum += t;
    }
    
    sum = sum + 8*(n-1);
    
    d = sum/24;
    sum = sum%24;
    h = sum;

    cout << d << ' ' << h;

    return 0;
}