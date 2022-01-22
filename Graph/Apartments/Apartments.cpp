#include <bits/stdc++.h>

#define seea(a,x,y) for(int i=x;i<y;i++){cin>>a[i];}
#define seev(v,n) for(int i=0;i<n;i++){int x; cin>>x; v.push_back(x);}
#define sees(s,n) for(int i=0;i<n;i++){int x; cin>>x; s.insert(x);}

using namespace std;

int main() {
    int n, m, k;
    cin >> n;
    cin >> m;
    cin >> k;
    int arr1[n], arr2[m];
    seea(arr1,0,n);
    seea(arr2,0,m);
    sort(arr1, arr1+n);
    sort(arr2, arr2+m);

    int l = 0, r = 0;
    int res = 0;
    while(l < n && r < m) {
        if(arr2[r] + k < arr1[l]) {
            r += 1;
        }
        else if(arr1[l] >= arr2[r] - k && arr1[l] <= arr2[r] + k) {
            l += 1;
            r += 1;
            res += 1;
        } else {
            l += 1;
        }
    }
    cout << res;
}
