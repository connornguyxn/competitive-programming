#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #pragma GCC optimize("O3,unroll-loops")
    #include <bits/stdc++.h>
    #define TASK "tree"
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
#define all(var) (var).begin(), (var).end()
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define Repd(i, n) for (int i = (n); i--; )
#define For(i, l, r) for (int i = (l), _r = (r); i < _r; i++)
#define Ford(i, r, l) for (int i = (r), _l = (l); --i >= _l; )
#define Fore(i, l, r) for (int i = (l), _r = (r); i <= _r; i++)
#define Forde(i, r, l) for (int i = (r) + 1, _l = (l); --i >= _l; )
#define Forin(it, var) for (auto it : var)
#define Bmask(i) (1ULL << (i))
#define Bget(mask, i) ((mask >> (i)) & 1)
#define Blog(n) (63 - __builtin_clzll(n))
template <class T = int>
T inp() { T x; cin >> x; return x; }
template <class... T>
void print(T&&... n) {
    using exp = int[];
    exp{0, (cout << n << sp, 0)...};
    cout << nl;
}
template <class T>
void mxmz(T &a, T b) { a = max(a, b); }
template <class T>
void mnmz(T &a, T b) { a = min(a, b); }
const int N = 1e6;
const ll MOD = 1e9 + 7;
const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
const int dx[8] = {0, -1, 0, 1, -1, -1, 1, 1};
const int dy[8] = {-1, 0, 1, 0, -1, 1, 1, -1};

// https://oj.vnoi.info/problem/chvpt_nd_chondtqg2_tree
// implementation, datastruct

int n, m, p, q;
vector<vector<int>> a, st;
////////////////////////////////////////
void build(int tl, int tr, int v) {
    if (tl == tr) {
        sort(all(a[tl]));
        st[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(tl, tm, v * 2);
        build(tm + 1, tr, v * 2 + 1);
        st[v].resize(st[v * 2].size() + st[v * 2 + 1].size());
        merge(all(st[v * 2]), all(st[v * 2 + 1]), st[v].begin());
    }
}
////////////////////////////////////////
int query(int l, int r, int val, int tl = 0, int tr = n - 1, int v = 1) {
    if (r < tl || tr < l) return 0;
    if (l <= tl && tr <= r) {
        return upper_bound(all(st[v]), val) - st[v].begin();
    } else {
        int tm = (tl + tr) / 2;
        int lq = query(l, r, val, tl, tm, v * 2);
        int rq = query(l, r, val, tm + 1, tr, v * 2 + 1);
        return lq + rq;
    }
}
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////
    cin >> n >> m >> p >> q;
    n++;
    
    a.resize(n);
    while (p--) {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
    }
    
    st.resize(n * 4);
    build(0, n - 1, 1);
    
    while (q--) {
        int li, lj, ri, rj;
        cin >> li >> lj >> ri >> rj;
        cout << query(li, ri, rj) - query(li, ri, lj - 1) << nl;
    }
    ////////////////
    return 0;
}
