#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #pragma GCC optimize("O3,unroll-loops,inline")
    #include <bits/stdc++.h>
    #define TASK "dragonpath"
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
#define mask(POS) (1ULL << (POS))
#define getbit(MASK, POS) ((MASK >> POS) & 1)
#define all(VAR) (VAR).begin(), (VAR).end()
const int N = 1e6;
const ull MOD = 1e9 + 7;
const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
// directions = left, up, right, down, upper_l, upper_r, lower_r, lower_l
const int dx[8] = {0, -1, 0, 1, -1, -1, 1, 1};
const int dy[8] = {-1, 0, 1, 0, -1, 1, 1, -1};
template<typename tVar, typename tVal>
void mnmz(tVar &var, tVal val) { if (val < var) var = val; }
template<typename tVar, typename tVal>
void mxmz(tVar &var, tVal val) { if (val > var) var = val; }

// dragonpath
// graph, hld, segtree

int n;
array<vector<int>, N> adj;
array<int, N> e;
////////////////////////////////////////
unordered_map<int, int> pos;
array<int, N> par, hev, depth, head, hld_arr;
////////////////////////////////////////
array<int, N> st;
////////////////////////////////////////
int hld_dfs(int cur) {
    int size = 1, mx_size = 0;
    
    for (int nxt : adj[cur]) {
        if (nxt == par[cur]) continue;
        
        par[nxt] = cur;
        depth[nxt] = depth[cur] + 1;
        
        int nxt_size = hld_dfs(nxt);
        size += nxt_size;
        
        if (nxt_size > mx_size) {
            hev[cur] = nxt;
            mx_size = nxt_size;
        }
    }
    
    return size;
}
////////////////////////////////////////
void hld_decompose(int cur, int cur_head) {
    head[cur] = cur_head;
    hld_arr[pos.size()] = cur;
    pos[cur] = pos.size();
    
    // cout << cur << sp;
    
    if (hev[cur]) hld_decompose(hev[cur], cur);
    
    for (int nxt : adj[cur]) {
        if (nxt == par[cur] || nxt == hev[cur]) continue;
        
        hld_decompose(nxt, nxt);
    }
}
////////////////////////////////////////
void st_build(int tl, int tr, int cur = 1) {
    if (tl == tr) {
        st[tl] = e[hld_arr[tl]];
    } else {
        int tm = (tl + tr) / 2;
        st_build(tl, tm, cur * 2);
        st_build(tm + 1, tr, cur * 2 + 1);
        
        st[cur] = st[cur * 2] ^ st[cur * 2 + 1];
    }
}
////////////////////////////////////////
void st_update(int p, int val, int tl, int tr, int cur = 1) {
    if (tl > p || tr < p) return;
    
    if (tl == p && tr == p) {
        st[cur] = val;
    } else {
        int tm = (tl + tr) / 2;
        st_update(p, val, tl, tm, cur * 2);
        st_update(p, val, tm + 1, tr, cur * 2 + 1);
        
        st[cur] = st[cur * 2] ^ st[cur * 2 + 1];
    }
}
////////////////////////////////////////
int st_get(int l, int r, int tl, int tr, int cur = 1) {
    if (l > r) return 0;
    
    if (l == tr && r == tr) {
        return st[cur];
    } else {
        int tm = (tl + tr) / 2;
        int ql = st_get(max(tl, l), tm, tl, tm, cur * 2);
        int qr = st_get(tm + 1, min(tr, r), tm + 1, tr, cur * 2 + 1);
        
        return ql ^ qr;
    }
}
////////////////////////////////////////
int get(int u, int v) {
    int res = 0;
    
    for (; head[u] != head[v]; v = par[head[v]]) {
        if (depth[v] < depth[u]) swap(u, v);
        
        res ^= st_get(pos[head[v]], pos[v], 0, n - 1);
    }
    
    if (depth[v] < depth[u]) swap(u, v);
    res ^= st_get(pos[u], pos[v], 0, n - 1);
    
    return res;
}
////////////////////////////////////////
int main() {
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        // freopen(TASK".out", "w", stdout);
    };
    cin.tie(0) -> sync_with_stdio(0);
    ////////////////
    int tc;
    cin >> n >> tc;
    
    for (int i = 1; i <= n; i++) {
        cin >> e[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    hld_dfs(1);
    hld_decompose(1, 1);
    
    st_build(0, n - 1);
    
    while (tc--) {
        int c, u, v;
        cin >> c >> u >> v;
        
        if (c == 1) {
            st_update(pos[u], v, 0, n - 1);
        } else {
            cout << get(u, v) << nl;
        }
    }
    ////////////////
    return 0;
}