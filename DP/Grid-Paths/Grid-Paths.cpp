#include <bits/stdc++.h>

using namespace std;
  
int MOD = 1000000007;

int gridPaths(vector<vector<char>> grid) {
    int n = grid.size();
    auto dp = vector<vector<long long>>(n, vector<long long>(n, 0));
    for (int i = n-1; i >= 0; -- i)
    {
        for (int j = n-1; j >=0; -- j)
        {
            if(grid[i][j] == '*') continue;
            if(i == n-1 && j == n-1) dp[i][j] = 1;
            else if(i == n-1) dp[i][j] = (dp[i][j] +  dp[i][j+1]) % MOD;
            else if(j == n-1) dp[i][j] += (dp[i][j] +  dp[i+1][j]) % MOD;
            else {
                dp[i][j] = (dp[i+1][j] + dp[i][j+1]) % MOD;
            }
        }
    }
    return dp[0][0];
}

int main() {
    int n;
    cin >> n;
    auto grid = vector<vector<char>>(n, vector<char>(n, '.'));
    string line;
    for (int i = 0; i < n; i++) {
        cin >> line;
        for (int j = 0; j < n; j ++) {
            if(line[j] == '*') {
                grid[i][j] = '*';
            }
        }
    }
    cout << gridPaths(grid);
}