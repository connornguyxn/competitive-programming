#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #pragma GCC optimize("O3,unroll-loops")
    #pragma GCC target("sse4.2")
    #include <bits/stdc++.h>
    #define TASK "qua"
#endif
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
#define all(VAR) (VAR).begin(), (VAR).end()
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define Repd(i, n) for (int i = (n); i--; )
#define For(i, l, r) for (int i = (l), _r = (r); i < _r; i++)
#define Ford(i, r, l) for (int i = (r), _l = (l); --i >= _l; )
#define Fore(i, l, r) for (int i = (l), _r = (r); i <= _r; i++)
#define Forde(i, r, l) for (int i = (r), _l = (l); i >= _l; i++)
#define Forin(it, var) for (auto it : var)
#define bmask(i) (1ULL << (i))
#define bget(mask, i) ((mask >> (i)) & 1)
#define blog2(n) (__builtin_clzll(1) - __builtin_clzll(n))
const int N = 5e5;
const ll MOD = 1e9 + 7;
const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
const int dx[8] = {0, -1, 0, 1, -1, -1, 1, 1};
const int dy[8] = {-1, 0, 1, 0, -1, 1, 1, -1};

// qua
// <tags>

int n;
vector<ll> st(N * 4);

void st_update(int p, ll val, int tl = 0, int tr = N - 1, int v = 1) {
    if (tr < p || tl > p) return;
    if (tl == tr && tl == p) {
        st[v] = max(st[v], val);
    } else {
        int tm = (tl + tr) / 2;
        st_update(p, val, tl, tm, v * 2);
        st_update(p, val, tm + 1, tr, v * 2 + 1);
        st[v] = max(st[v * 2], st[v * 2 + 1]);
    }
}

ll st_get(int l, int r, int tl = 0, int tr = N - 1, int v = 1) {
    if (r < tl || tr < l) return -INFLL;
    if (l <= tl && tr <= r) {
        return st[v];
    } else {
        int tm = (tl + tr) / 2;
        ll lq = st_get(l, r, tl, tm, v * 2);
        ll rq = st_get(l, r, tm + 1, tr, v * 2 + 1);
        return max(lq, rq);
    }
}
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(0);
    ////////////////
    cin >> n;
    
    vector<int> a(n + 1);
    vector<ll> w(n + 1);
    vector<pii> zip(n + 1);
    zip[0] = {-INF, 0};
    
    Fore(i, 1, n) {
        cin >> a[i];
        cin >> w[i];
        zip[i] = {a[i], i};
    }
    sort(all(zip));
    // db(zip);
    
    Fore(i, 1, n) {
        a[zip[i].se] = a[zip[i - 1].se] + (zip[i].fi != zip[i - 1].fi);
    }
    // db(a);
    
    ll ans = 0;
    Fore(i, 1, n) {
        ll cur = st_get(0, a[i] - 1) + w[i];
        ans = max(ans, cur);
        st_update(a[i], cur);
    }
    
    cout << ans;
    ////////////////
    return 0;
}