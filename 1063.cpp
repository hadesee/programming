#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    char cols[8] = {'A','B','C','D','E','F','G','H'};
    char rows[8] = {'8','7','6','5','4','3','2','1'};

    int n, kx, ky, rx, ry;
    string word;

    cin >> word;

    for (int i = 0; i < 8; i++)
    {
        if (word[0]==cols[i])
        {
            ky = i;
        }
        if (word[1]==rows[i])
        {
            kx = i;
        }
    }

    cin >> word;

    for (int i = 0; i < 8; i++)
    {
        if (word[0]==cols[i])
        {
            ry = i;
        }
        if (word[1]==rows[i])
        {
            rx = i;
        }
    }
    

    cin >> n;
    string command;

    for (int i = 0; i < n; i++)
    {
        cin >> command;
        if (command=="R"&&(ky<7))
        {
            ky ++;
            if ((rx==kx)&&(ry==ky))
            {
                if (ry<7)
                {
                    ry++;
                }
                else
                {
                    ky--;
                }
            }
        }
        else if (command=="L"&&(0<ky))
        {
            ky --;
            if ((rx==kx)&&(ry==ky))
            {
                if (0<ry)
                {
                    ry--;
                }
                else
                {
                    ky++;
                }
            }
        }
        else if (command=="B"&&(kx<7))
        {
            kx ++;
            if ((rx==kx)&&(ry==ky))
            {
                if (rx<7)
                {
                    rx++;
                }
                else
                {
                    kx--;
                }
            }
        }
        else if (command=="T"&&(0<kx))
        {
            kx --;
            if ((rx==kx)&&(ry==ky))
            {
                if (0<rx)
                {
                    rx--;
                }
                else
                {
                    kx++;
                }
            }
        }
        else if (command=="RT"&&((0<kx)&&(ky<7)))
        {
            kx--;
            ky++;
            if ((rx==kx)&&(ry==ky))
            {
                if ((0<rx)&&(ry<7))
                {
                    rx--;
                    ry++;
                }
                else
                {
                    kx++;
                    ky--;
                }
            }
        }
        else if (command=="LT"&&((0<kx)&&(0<ky)))
        {
            kx--;
            ky--;
            if ((rx==kx)&&(ry==ky))
            {
                if ((0<rx)&&(0<ry))
                {
                    rx--;
                    ry--;
                }
                else
                {
                    kx++;
                    ky++;
                }
            }
        }
        else if (command=="RB"&&((kx<7)&&(ky<7)))
        {
            kx++;
            ky++;
            if ((rx==kx)&&(ry==ky))
            {
                if ((rx<7)&&(ry<7))
                {
                    rx++;
                    ry++;
                }
                else
                {
                    kx--;
                    ky--;
                }
            }
        }
        else if (command=="LB"&&((kx<7)&&(0<ky)))
        {
            kx++;
            ky--;
            if ((rx==kx)&&(ry==ky))
            {
                if ((rx<7)&&(0<ry))
                {
                    rx++;
                    ry--;
                }
                else
                {
                    kx--;
                    ky++;
                }
            }
        }
        
    }

    cout << cols[ky] << rows[kx] << '\n'; 
    cout << cols[ry] << rows[rx];

    return 0;
}