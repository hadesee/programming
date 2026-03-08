#include <iostream>
#include <string>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

int main(void)
{   
    ios::sync_with_stdio(0),cin.tie(0);
    int a, b;

    cin >> a >> b;

    if (a>b)
    {
        cout << b;
    }
    else
    {
        cout << a;
    }
    
    

    return 0;
}