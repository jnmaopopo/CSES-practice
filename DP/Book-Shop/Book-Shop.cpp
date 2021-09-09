#include <bits/stdc++.h>

using namespace std;

int BookShop(int n, int t, int h[], int s[]) {
    int res = 0;
    auto dp = vector<vector<int>>(n+1, vector<int>(t+1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= t;  j++) {
            dp[i][j] = dp[i-1][j];
            if(j >= h[i-1]) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-h[i-1]] + s[i-1]);
            }
            res = max(dp[i][j] , res);
        }
    }
    return res;
}

int main() {
    int n, t;
    cin >>n;
    cin >>t;
    int h[n] = {};
    for (int i = 0; i< n; i++){
        cin >> h[i];
    }
    int s[n] = {};
    for (int i = 0; i< n; i++){
        cin >> s[i];
    }
    cout << BookShop(n, t, h, s);
    return 0;
}