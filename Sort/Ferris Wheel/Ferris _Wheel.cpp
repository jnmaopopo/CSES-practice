#include <bits/stdc++.h>

#define seea(a,x,y) for(int i=x;i<y;i++){cin>>a[i];}
#define seev(v,n) for(int i=0;i<n;i++){int x; cin>>x; v.push_back(x);}
#define sees(s,n) for(int i=0;i<n;i++){int x; cin>>x; s.insert(x);}
#define print(a) cout << a << endl;
using namespace std;

int main() {
    int n, m;
    cin >> n;
    cin >> m;
    int arr1[n];
    seea(arr1,0,n);
    sort(arr1, arr1+n);

    int l = 0, r = n-1;
    int res = 0;
    while(l < r) {
        if(arr1[l] + arr1[r] > m) {
            res += 1;
            r -= 1;
        } else {
            l += 1;
            r -= 1;
            res += 1;
        }
    }
    if(l == r) {
        res += 1;
    }
    cout << res;
}
