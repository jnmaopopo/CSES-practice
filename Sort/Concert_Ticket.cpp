#include <bits/stdc++.h>

using namespace std;
//----------TEMPLATES----------
template<typename... T>
void see(T&... args) { ((cin >> args), ...);}
template<typename... T>
void put(T&&... args) { ((cout << args << " "), ...);}
template<typename... T>
void putl(T&&... args) { ((cout << args << " "), ...); cout<<'\n';}
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {cerr << *it << "=" << a << ", "; err(++it, args...);}
//----------MACROS----------
#define seea(a,x,y) for(int i=x;i<y;i++){cin>>a[i];}
#define seev(v,n) for(int i=0;i<n;i++){int x; cin>>x; v.push_back(x);}
#define sees(s,n) for(int i=0;i<n;i++){int x; cin>>x; s.insert(x);}
#define all(x) x.begin(),x.end()
#define rep(i,a,b) for (int i=a; i<b; ++i)
#define rev(i,a,b) for (int i=a; i>b; --i)
#define print(a) cout << a << endl;
#define pii pair<int,int>


int main() {
    int n, m;
    cin >> n;
    cin >> m;
    auto res = vector<int>(n, -1);
    set<pii> s;
    rep(i,0,n) {
        int t; cin >> t;
        s.insert({-t, i});
    }

    rep(i,0,m) {
        int t; cin >> t;
        auto y = s.lower_bound({-t, -1});
        if (y==s.end()) putl(-1);
        else {
            putl(-(y->first));
            s.erase(y);
        }
    }
}
