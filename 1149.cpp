#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main(void)
{   
    ios::sync_with_stdio(0),cin.tie(0);
    int n, r[1000] = {0}, g[1000] = {0}, b[1000] = {0}, fr[1000] = {0}, fg[1000] = {0}, fb[1000] = {0};

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> r[i] >> g[i] >> b[i];
    }

    fr[0] = r[0];
    fg[0] = g[0];
    fb[0] = b[0];
    
    for (int i = 1; i < n; i++)
    {
        if (fg[i-1]>=fb[i-1])
        {
            fr[i] = fb[i-1] + r[i];
        }
        else
        {
            fr[i] = fg[i-1] + r[i];
        }
        
        if (fb[i-1]>=fr[i-1])
        {
            fg[i] = fr[i-1] + g[i];
        }
        else
        {
            fg[i] = fb[i-1] + g[i];
        }

        if (fg[i-1]>=fr[i-1])
        {
            fb[i] = fr[i-1] + b[i];
        }
        else
        {
            fb[i] = fg[i-1] + b[i];
        }
    }
    
    if (fr[n-1]<=fg[n-1]&&fr[n-1]<=fb[n-1])
    {
        cout << fr[n-1];
    }
    else if (fb[n-1]<=fg[n-1]&&fb[n-1]<=fr[n-1])
    {
        cout << fb[n-1];
    }
    else
    {
        cout << fg[n-1];
    }
    
    
    
    return 0;
}