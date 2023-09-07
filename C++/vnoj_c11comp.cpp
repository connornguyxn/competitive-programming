#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "c11comp"
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
#define bmask(i) (1ULL << (i))
#define bget(mask, i) ((mask >> (i)) & 1)
#define blog(n) (63 - __builtin_clzll(n))
template <class T = int>
T inp() { T x; cin >> x; return x; }
template <class... T>
void print(T&&... n) {
    using exp = int[];
    exp{0, (cout << n << sp, 0)...};
    cout << endl;
}
template <class T>
void mxmz(T &a, T b) { a = max(a, b); }
template <class T>
void mnmz(T &a, T b) { a = min(a, b); }
const int N = 1e6;
const ull MOD = 1e9 + 7;
const ull BASE = 311;
const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
const int dx[8] = {0, -1, 0, 1, -1, -1, 1, 1};
const int dy[8] = {-1, 0, 1, 0, -1, 1, 1, -1};

// https://oj.vnoi.info/problem/c11comp
// datastruct, dfs, incomplete

int n, m, k;
vector<vector<int>> adj;
vector<int> v, pl, pr, pos;
////////////////////////////////////////
void dfs(int cur) {
    pos.push_back(cur);
    pl[cur] = pos.size();
    Forin(nxt, adj[cur]) dfs(nxt);
    pr[cur] = pos.size();
}
////////////////////////////////////////
vector<int> st;
//////////////////////////
map<int, int> build(int tl = 0, int tr = n - 1, int cur = 1) {
    map<int, int> res;
    
    if (tl == tr) {
        res[v[pos[tl]]] = 1;
        st[cur] = 1;
    } else {
        int tm = (tl + tr) / 2;
        // map<int, int> lq = build(tl, tm, cur * 2);
        // map<int, int> rq = build(tm + 1, tr, cur * 2 + 1);
        // Forin(it, lq) res[it.fi] += it.se;
        // Forin(it, rq) res[it.fi] += it.se;
        
        Forin(it, build(tl, tm, cur * 2)) res[it.fi] += it.se;
        Forin(it, build(tm + 1, tr, cur * 2 + 1)) res[it.fi] += it.se;
        
        Forin(it, res) st[cur] += it.se <= k;
    }
    
    return res;
}
//////////////////////////
int query(int l, int r, int tl = 0, int tr = n - 1, int cur = 1) {
    if (tr < l || r < tl) return 0;
    if (l <= tl && tr <= r) {
        return st[cur];
    } else {
        int tm = (tl + tr) / 2;
        int lq = query(l, r, tl, tm, cur * 2);
        int rq = query(l, r, tm + 1, tr, cur * 2 + 1);
        return lq + rq;
    }
}
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////
    cin >> n >> m >> k;
    
    adj.resize(n + 1);
    Fore(i, 2, n) {
        int u;
        cin >> u;
        adj[u].push_back(i);
    }
    
    v.resize(n + 1);
    Fore(i, 1, n) cin >> v[i];
    
    pos.reserve(n + 1);
    pl.resize(n + 1);
    pr.resize(n + 1);
    dfs(1);
    // print(pos);
    
    st.resize(n * 4);
    build();
    
    int q;
    cin >> q;
    print(q);
    while (q--) {
        int u;
        cin >> u;
        // print(u, pl[u], pr[u]);
        cout << query(pl[u], pr[u]) << nl;
    }
    ////////////////
    return 0;
}