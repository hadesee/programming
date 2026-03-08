#include <iostream>

using namespace std;
int main(void)
{
    int n, a, b;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;

        if (a>=b)
        {
            cout << "MMM BRAINS" << endl;
        }
        else 
        {
            cout << "NO BRAINS" << endl;
        }
    }
    


    return 0;
}