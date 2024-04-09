#pragma GCC optimize("O3,unroll-loops,inline")
#include <bits/stdc++.h>
#define TASK "gapthu"
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define str string
#define nl '\n'
#define sp ' '
#define mask(POS) (1ULL << (POS))
#define all(VAR) (VAR).begin(), (VAR).end()
const int N = 1e6;
const int MOD = 1e9 + 7;

int n, m;
ll t;
vector<ll> p, s;
vector<pii> a;
////////////////////////////////////////
struct sub1 {
    sub1() {
        int res = 0;
        ll sum = 0, cst = 0;
        for (ll i = a[0].fi; i <= a[0].se; i++) {
            sum += i;
            res++;
            if (cst <= s[0]) {
                cst += p[0];
            } else {
                cst += p[1];
            };
            if (sum - cst >= t) break;
        }
        cout << (sum - cst >= t ? res : -1);
    }
};
struct sub12 {
    vector<int> pro;
    
    sub12() {
        pro.resize(a[0].se - a[0].fi + 2);
        ll sum = 0, cst = 0;
        for (int i = 1; i <= a[0].se - a[0].fi + 1; i++) {
            sum += i - 1 + a[0].se;
            if (cst <= s[0]) {
                cst += p[0];
            } else {
                cst += p[1];
            };
            pro[i] = sum - cst;
        }
    }
    
    void solve() {
        int p = lower_bound(all(pro), t) - pro.begin();
        cout << (p == n + 1 ? -1 : p);
    }
};
////////////////////////////////////////
int main() {
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        // freopen(TASK".out", "w", stdout);
    };
    cin.tie(0) -> sync_with_stdio(0);
    ////////////////
    int q;
    cin >> n >> m >> q;
    s.resize(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    p.resize(n + 1);
    for (int i = 0; i <= n; i++) cin >> p[i];
    a.resize(m);
    for (int i = 0; i < m; i++) cin >> a[i].fi >> a[i].se;
    sub12 sub;
    
    while (q--) {
        cin >> t;
        if (q <= 1000) {
            sub1();
        } else {
            sub.solve();
        }
        cout << nl;
    }
    ////////////////
    return 0;
}