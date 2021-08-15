#include <bits/stdc++.h>

using namespace std;
int MOD = 1e9 + 7;
int CoinCombiation2(int n, int coins[], int target) {
    auto dp = vector<vector<int>>(n+1, vector<int>(target + 1, 0));
    for (int i = 0; i < n+1; i ++){
        dp[i][0] = 1;
    } 
    for (int i = 1; i < n+1; i ++){
        for (int j = 1; j <= target; j ++) {
            if(j < coins[i-1]) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = (dp[i-1][j] + dp[i][j-coins[i-1]]) % MOD;
            }
        }
    }
    return dp[n][target] % MOD;
}
int main() {
// solution comes here
    int n, x;
    cin >> n >> x;
    int coins[n];
    for (int i = 0 ; i < n; i ++) {
        cin >> coins[i];
    }

    cout << CoinCombiation2(n, coins, x);
    return 0;
}