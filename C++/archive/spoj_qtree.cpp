#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #pragma GCC optimize("O3,unroll-loops")
    #pragma GCC target("sse4.2")
    #include <bits/stdc++.h>
    #define TASK "qtree"
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
template <typename... T>
void print(T&&... n) {
    using exp = int[];
    exp{0, (cout << n << sp, 0)...};
    cout << nl;
}
const int N = 1e4;
const ll MOD = 1e9 + 7;
const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
const int dx[8] = {0, -1, 0, 1, -1, -1, 1, 1};
const int dy[8] = {-1, 0, 1, 0, -1, 1, 1, -1};

// https://www.spoj.com/problems/QTREE/
// graph, hld

int n;
struct node {
    int n, w;
};
vector<vector<node>> adj(N + 1);
int hev[N + 1], par[N + 1], head[N + 1], depth[N + 1], pos[N + 1], w[N + 1];
////////////////////////////////////////
int hld_cnt(int cur) {
    int cnt = 1, mx = 0;
    hev[cur] = 0;
    
    for (node nxt : adj[cur]) {
        if (nxt.n == par[cur]) continue;
        
        par[nxt.n] = cur;
        depth[nxt.n] = depth[cur] + 1;
        w[nxt.n] = nxt.w;
        
        int ncnt = hld_cnt(nxt.n);
        cnt += ncnt;
        
        if (ncnt > mx) {
            hev[cur] = nxt.n;
            mx = ncnt;
        };
    }
    
    return cnt;
}
////////////////
vector<int> hld_arr;
void hld_decompose(int cur, int chead) {
    head[cur] = chead;
    pos[cur] = hld_arr.size();
    hld_arr.push_back(cur);
    
    if (hev[cur]) hld_decompose(hev[cur], chead);
    
    for (node nxt : adj[cur]) {
        if (nxt.n == par[cur] || nxt.n == hev[cur]) continue;
        hld_decompose(nxt.n, nxt.n);
    }
}
////////////////////////////////////////
int st[N * 4];
void st_build(int tl = 0, int tr = n - 1, int v = 1) {
    if (tl == tr) {
        st[v] = w[hld_arr[tl]];
    } else {
        int tm = (tl + tr) / 2;
        st_build(tl, tm, v * 2);
        st_build(tm + 1, tr, v * 2 + 1);
        st[v] = max(st[v * 2], st[v * 2 + 1]);
    }
}
////////////////
void st_update(int p, int val, int tl = 0, int tr = n - 1, int v = 1) {
    if (tr < p || tl > p) return;
    if (tl == p && tr == p) {
        st[v] = val;
    } else {
        int tm = (tl + tr) / 2;
        st_update(p, val, tl, tm, v * 2);
        st_update(p, val, tm + 1, tr, v * 2 + 1);
        st[v] = max(st[v * 2], st[v * 2 + 1]);
    }
}
////////////////
int st_get(int l, int r, int tl = 0, int tr = n - 1, int v = 1) {
    if (r < tl || tr < l) return -INF;
    if (l <= tl && tr <= r) {
        return st[v];
    } else {
        int tm = (tl + tr) / 2;
        int lq = st_get(l, r, tl, tm, v * 2);
        int rq = st_get(l, r, tm + 1, tr, v * 2 + 1);
        return max(lq, rq);
    }
}
////////////////////////////////////////
int query(int u, int v) {
    int res = -INF;
    
    for (; head[u] != head[v]; v = par[head[v]]) {
        if (depth[head[u]] > depth[head[v]]) swap(u, v);
        
        res = max(res, st_get(pos[head[v]], pos[v]));
    }
    
    if (depth[u] > depth[v]) swap(u, v);
    res = max(res, st_get(pos[u] + 1, pos[v]));
    
    return res;
}
////////////////////////////////////////
void solve() {
    cin >> n;
    Rep(i, n + 1) adj[i].clear();
    
    vector<pii> e(n + 1);
    Rep(i, n - 1) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        e[i + 1] = {u, v};
    }
    
    par[1] = 0;
    depth[1] = 0;
    hld_cnt(1);
    
    hld_arr.clear();
    hld_decompose(1, 1);
    
    st_build();
    
    str q;
    while (true) {
        cin >> q;
        if (q == "DONE") break;
        
        int u, v;
        cin >> u >> v;
        
        if (q == "QUERY") {
            cout << query(u, v) << nl;
        } else {
            if (par[e[u].fi] == e[u].se) swap(e[u].fi, e[u].se);
            st_update(pos[e[u].se], v);
        }
    }
}
////////////////////////////////////////
int main() {
    // freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////
    int tc;
    cin >> tc;
    hld_arr.reserve(N + 1);
    while (tc--) {
        solve();
    }
    ////////////////
    return 0;
}