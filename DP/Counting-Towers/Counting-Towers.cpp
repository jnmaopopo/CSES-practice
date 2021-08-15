#include <bits/stdc++.h>
#define ll long long
int MOD = 1e9+7;
int mxN = 1e6+6;

using namespace std;
int main() {
// solution comes here
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    auto dp = vector<vector<ll>>(mxN, vector<ll>(3, 0));
    dp[1][1] = dp[1][2] = 1;
    for (int i = 2; i < mxN; i++) {
        dp[i][1] = (dp[i-1][1]*4 % MOD  + dp[i-1][2] ) % MOD ;
        dp[i][2] = (dp[i-1][1]  + dp[i-1][2]*2 % MOD ) % MOD ;
    }
    int input[n];
    for(int i = 0; i < n; i ++) {
        cin>>input[i];
    }
    for(int i = 0; i < n; i ++) {
        cout << (dp[input[i]][1] + dp[input[i]][2]) % MOD << '\n';
    }
}