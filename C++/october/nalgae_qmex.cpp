#if DEBUG
    #include "lib/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "qmex"
#endif
using namespace std;
using ll = long long;
using ull = unsigned long long;
using str = string;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define fi first
#define se second
#define nl '\n'
#define sp ' '
#define all(a) (a).begin(), (a).end()
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define Repd(i, n) for (int i = (n); i--; )
#define For(i, l, r) for (int i = (l), _r = (r); i <= _r; i++)
#define Fors(i, l, r) for (int i = (l), _r = (r); i < _r; i++)
#define Ford(i, r, l) for (int i = (r) + 1, _l = (l); --i >= _l; )
#define Forin(it, var) for (auto& it : var)
#define bmask(i) (1ULL << (i))
#define bget(mask, i) ((mask >> (i)) & 1)
#define blog2(n) (63 - __builtin_clzll(n))
const int N = 1e6;
const ll MOD = 1e9 + 7;
const ull BASE = 311;
const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
const int dx[8] = {0, -1, 0, 1, -1, -1, 1, 1};
const int dy[8] = {-1, 0, 1, 0, -1, 1, 1, -1};
template <class... T>
void print(T&&... n) {
    using exp = int[];
    exp{0, (cout << n << sp, 0)...};
    cout << endl;
}
template <class T>
bool mxmz(T &a, T b) { if (b > a) return a = b, 1; }
template <class T>
bool mnmz(T &a, T b) { if (b < a) return a = b, 1; }
void add(ll &a, ll b) { a = (a + b) % MOD; }
void sub(ll &a, ll b) { a = (a + MOD - b) % MOD; }
void mul(ll &a, ll b) { a = a * (b % MOD) % MOD; }

// nalgae_qmex
// offline, segtree

struct query {
    int l, r, p;
};
int n, m;
vector<int> st(N * 4 + 4, -1);
////////////////////////////////////////
void update(int p, int v, int tl = 0, int tr = n, int tv = 1) {
    if (p < tl || tr < p) return;
    if (p == tl && tr == p) {
        st[tv] = v;
    } else {
        int tm = tl + tr >> 1;
        update(p, v, tl, tm, tv * 2);
        update(p, v, tm + 1, tr, tv * 2 + 1);
        st[tv] = min(st[tv * 2], st[tv * 2 + 1]);
    }
}
////////////////////
int findmin(int p, int tl = 0, int tr = n, int tv = 1) {
    if (tl == tr) return tl;
    int tm = tl + tr >> 1;
    if (st[tv * 2] < p) {
        return findmin(p, tl, tm, tv * 2);
    } else {
        return findmin(p, tm + 1, tr, tv * 2 + 1);
    }
}
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////////
    cin >> n >> m;
    
    vector<int> a(n);
    Rep(i, n) cin >> a[i];
    
    vector<query> q(m);
    Rep(i, m) {
        cin >> q[i].l >> q[i].r;
        q[i].l--;
        q[i].r--;
        q[i].p = i;
    }
    sort(all(q), [](query a, query b) { return a.r < b.r; });
    
    vector<int> ans(m);
    int j = 0;
    Forin(cur, q) {
        while (j <= cur.r) {
            if (a[j] != INF) update(a[j], j);
            j++;
        }
        ans[cur.p] = findmin(cur.l);
    }
    Forin(it, ans) cout << it << nl;
    ////////////////////
    return 0;
}