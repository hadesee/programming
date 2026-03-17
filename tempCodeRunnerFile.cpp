#include <iostream>


using namespace std;
int main(void)
{
    int n, a;
    string word;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> word >> a;

        if (a==2026)
        {
            cout << word;
        }
        
    }

    return 0;
}