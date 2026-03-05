#include <iostream>
#include <string>
#include <unordered_map>

/*1620 포켓몬 마스터 이다솜
point 3가지
[1] unordered_map 해시 맵 사용 
[2] 시간초과 해결
[3] 키가 여러 개면 여러 맵 사용
시간 초과가 났던 이유는 무엇인가? 
insert({}) 보다 emplace()가 더 효율적임
또한 데이터가 많이 들어오면 자체적으로 unordered_map이 확장하는데 reserve() 함수를 통해 미리 확장 해줄 수 있음 
또한 ios::sync_with_stdio(0), cin.tie(0);를 통해 입출력 시간 소모를 줄임
*/


using namespace std;
int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0);
    unordered_map<string, int>pokemon_name;
    unordered_map<int, string>pokemon_num;

    int n, m, count;
    string word;

    cin >> n >> m;

    pokemon_name.reserve(n);
    pokemon_num.reserve(n);

    for (int i = 1; i <= n; i++)
    {
        cin >> word;
        pokemon_name.emplace(word, i);
        pokemon_num.emplace(i,word);
    }

    for (int i = 0; i < m; i++)
    {
        cin >> word;

        if ('0'<=word[0]&&word[0]<='9')
        {
            int num = stoi(word);
            cout << pokemon_num[num] << '\n';

        }
        else
        {
            cout << pokemon_name[word] << '\n';
        }
    }
    
    
}