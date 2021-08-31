#include <bits/stdc++.h>

using namespace std;
int remove_digits(int n) {
    auto dp = vector<int>(n+1, n);
    dp[0] = 0;
    for (int i = 1; i < n+1; i++) {
        if(i < 10) {
            dp[i] = 1;
            continue;
        }
        int temp = i;
        while (temp > 0) {
            int j = temp % 10;
            dp[i] = min(dp[i], dp[i-j] + 1);
            temp /= 10;
        }
    }
    return dp[n];
}
int main() {
// solution comes here
    int n;
    cin >> n;
    cout << remove_digits(n);
    return 0;
}