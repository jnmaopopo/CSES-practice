#include <bits/stdc++.h>

using namespace std;

int main() {
// solution comes here
    string s, t;
    cin >> s;
    cin >> t;
    int n= s.length();
    int m= t.length();
    int max = n + m;
    auto dp = vector<vector<int>>(n+1, vector<int>(m+1, max));
    for (int i = 0; i <= n; i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= m; j++) {
        dp[0][j] = j;
    }
    for (int i = 1; i <= n; i++ ) {
        for (int j = 1; j <= m; j++) {
            if(s[i-1] == t[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = min(min(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1]) + 1;
            }
        }
    }
    cout << dp[n][m];
}