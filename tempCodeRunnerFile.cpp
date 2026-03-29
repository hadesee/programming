#include <bits/stdc++.h>

using namespace std;

int n;
long long dp[100001][2];// 0 왼쪽or오른쪽 호랑이 1 없음

/*
dp[i][0]=dp[i-1][0]+dp[i-1][1]*2
dp[i][1]=dp[i-1][0]+dp[i-1][1]
*/

int main(){
    cin >> n;
    dp[0][0]=2;
    dp[0][1]=1;

    for(int i=1;i<n;i++){
        dp[i][0]=(dp[i-1][0]+dp[i-1][1]*2)%9901;
        dp[i][1]=(dp[i-1][0]+dp[i-1][1])%9901;
    }
    cout << (dp[n-1][0]+dp[n-1][1])%9901;
}
