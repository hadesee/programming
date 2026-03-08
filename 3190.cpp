#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0);
    int leng = 1, n, apple, current_time = 0, directtime = 0;
    char direct = 'R'; // 초기는 1,1에서 시작하고 바라보는 방향을 오른쪽 R..  왼쪽 L 위쪽 U 아래쪽 D
    queue<int> qx, qy; // 뱀의 위치 정보를 저장하는 각각 x y 큐
    qx.push(1);
    qy.push(1);

    cin >> n;
    int field[n + 1][n + 1] = {0}; // 사과의 정보를 저장하는 필드

    cin >> apple;

    for (int i = 0; i < apple; i++)
    {
        int a, b;
        cin >> a >> b;

        field[a][b] = 1;
    }

    cin >> directtime;
    int dc, directchange[101]={0}; // 방향 전환 시간 정확히는 이 시간이후 전환
    char directmode[101]={0};      // 방향 전환 모드 정확히는 왼쪽 오른쪽으로만

    dc = 0;

    for (int i = 0; i < directtime; i++)
    {
        cin >> directchange[i] >> directmode[i];
    }

    while (1)
    {
        current_time++;
        int nx, ny;
        if (direct == 'R')
        {
            nx = qx.back();
            ny = qy.back() + 1;
        }
        else if (direct == 'L')
        {
            nx = qx.back();
            ny = qy.back() - 1;
        }
        else if (direct == 'U')
        {
            nx = qx.back() - 1;
            ny = qy.back();
        }
        else if (direct == 'D')
        {
            nx = qx.back() + 1;
            ny = qy.back();
        }

        if (nx == 0 || ny == 0 || nx == n + 1 || ny == n + 1)
        {
            break;
        }

        int complex = 0;

        for (int i = 0; i < leng; i++)
        {
            if ((nx == qx.front()) && (ny == qy.front()))
            {
                complex = 1;
            }
            qx.push(qx.front());
            qx.pop();
            qy.push(qy.front());
            qy.pop();
        }

        if (complex == 1)
        {
            break;
        }

        if (field[nx][ny] == 1)
        {
            leng++;
            qx.push(nx);
            qy.push(ny);
            field[nx][ny] = 0;
        }
        else
        {
            qx.push(nx);
            qx.pop();
            qy.push(ny);
            qy.pop();
        }

        if (current_time == directchange[dc])
        {
            if (directmode[dc] == 'D')
            {
                if (direct == 'R')
                {
                    direct = 'D';
                }
                else if (direct == 'L')
                {
                    direct = 'U';
                }
                else if (direct == 'U')
                {
                    direct = 'R';
                }
                else if (direct == 'D')
                {
                    direct = 'L';
                }
            }
            else
            {
                if (direct == 'R')
                {
                    direct = 'U';
                }
                else if (direct == 'L')
                {
                    direct = 'D';
                }
                else if (direct == 'U')
                {
                    direct = 'L';
                }
                else if (direct == 'D')
                {
                    direct = 'R';
                }
            }
            dc++;
        }
    }

    cout << current_time;

    return 0;
}