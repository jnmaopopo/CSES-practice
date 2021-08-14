#include <bits/stdc++.h>

using namespace std;

int getMinimalCoins(int len, int coin[], int target) {
    if (target < 0) {
        return -1;
    }
    auto dp = vector<int>(target+1, target + 1);
    dp[0] = 1;
    for (int i = 1; i <= target; i++) {
        for (int j = 0; j < len; j++) {
            if(coin[j] > i) continue;
            if(coin[j] == i) dp[i] = 1;
            else dp[i] = min(dp[i-coin[j]] + 1, dp[i]);
        }
    }
    if(dp[target] == target + 1) return -1;
    return dp[target];
}

int main() {
// solution comes here
    int n, x;
    cin >> n >> x;
    int coin[n];
    for (int i = 0 ; i < n; i ++) {
        cin >> coin[i];
    }

    cout << getMinimalCoins(n, coin, x);
    return 0;
}