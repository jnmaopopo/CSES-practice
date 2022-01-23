#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x;
    cin >> n;
    auto seen = set<int>();
    for (int i = 0; i < n; i ++) {
        cin >> x;
        seen.insert(x);
    }
    cout << seen.size();
}
