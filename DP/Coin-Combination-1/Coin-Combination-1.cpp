#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int MOD = 1000000007;
 
  int n;
  int x;
  cin >> n >> x;
 
  int coins[n];
  for (int i = 0; i < n; i++) {
    int c;
    cin >> c;
    coins[i] = c;
  }
 
  int dp[x + 1] = { 0 };
  dp[0] = 1;
  for (int i = 0; i <= x; i++) {
    if (dp[i] == 0) { continue; }
    for (int j = 0; j < n; j++) {
      int coin = coins[j];
      if ((i + coin) <= x) {
        dp[i + coin] = (dp[i + coin] + dp[i]) % MOD;
      }
    }
  }
 
  cout << dp[x] << endl;
  return 0;
}