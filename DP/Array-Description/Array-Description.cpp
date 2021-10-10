#include <bits/stdc++.h>

using namespace std;
int MOD = 1000000007;


int ArrayDescription(int n, int m, vector<int> x) {
    auto dp = vector<vector<long long>>(n, vector<long long>(m + 1, 0));
    if(x[0] == 0) {
        fill(dp[0].begin(), dp[0].end(), 1);
    } else{
        dp[0][x[0]] = 1;
    }
    for (int i = 1; i< n; i ++) {
        if(x[i] == 0) {
            for(int j = 1; j < m + 1; j ++) {
                for(int k : {j-1, j, j+1}) {
                    if (k >=1 and k <= m) {
                        (dp[i][j] += dp[i-1][k]) %= MOD;
                    }
                }
            }
        } else {
            for(int k : {x[i]-1, x[i], x[i]+1}) {
                if (k >=1 and k <= m) {
                    (dp[i][x[i]] += dp[i-1][k]) %= MOD;
                }
            }
        }
    }
    int res = 0;
    for (int i = 1; i <=m ; i ++) {
        res = (res + dp[n-1][i]) % MOD;
    }
    return res;
}

int main() {
    int n, m;
    cin >> n;
    cin >> m;
    auto x = vector<int>(n, 0);
    int ele;
    for (int i = 0; i < n; i++) {
        cin >> ele;
        if(ele > 0) {
            x[i] = ele;
        }
    }
    cout << ArrayDescription(n,m,x);
}