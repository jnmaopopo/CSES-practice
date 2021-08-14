#include <bits/stdc++.h>

using namespace std;

int CountDiceCombination(int n) {
    int MOD = 1e9 + 7;
    auto dp = vector<int>(n+1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= n; i ++) {
        for(int j = 1; j <= min(i,6); j++ ) {
            dp[i] =  (dp[i] + dp[i-j]) % MOD;
        }
    }
    return dp[n] % MOD;
}

int main() {
// solution comes here
    int n;
    cin >> n;
    cout << CountDiceCombination(n);
    return 0;
}