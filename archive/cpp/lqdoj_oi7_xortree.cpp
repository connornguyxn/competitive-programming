#if DEBUG
    #include "lib/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "xortree"
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
#define Ford(i, r, l) for (int i = (r), _l = (l); i >= _l; i--)
#define Forin(it, var) for (auto& it : var)
#define bmask(i) (1ULL << (i))
#define bget(mask, i) ((mask >> (i)) & 1)
const int N = 1e6;
const ll MOD = 1e9 + 7;
const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
// right, down, left, up, lower right, lower left, upper left, upper right
const int dv[] = {0, 1, 0, -1, 1, 1, -1, -1};
const int dh[] = {1, 0, -1, 0, 1, -1, -1, 1};
using namespace chrono;
struct Timer : high_resolution_clock {
    const time_point start_time;
    Timer() : start_time(now()) {}
    rep elapsed() const {
        return duration_cast<milliseconds>(now() - start_time).count();
    }
} timer;
template <class... T>
void print(T&&... n) {
    using exp = int[];
    exp{0, (cout << n << sp, 0)...};
    cout << endl;
}
template <class T>
bool mxmz(T &a, T b) { return a < b ? a = b, 1 : 0; }
template <class T>
bool mnmz(T &a, T b) { return b < a ? a = b, 1 : 0; }
void add(ll &a, ll b) { a = (a + b) % MOD; }
void sub(ll &a, ll b) { a = (a + MOD - b) % MOD; }
void mul(ll &a, ll b) { a = a * (b % MOD) % MOD; }
template <typename T, int D>
struct vec : vector<vec<T, D - 1>> {
    template <typename... Args>
    vec(int n = 0, Args... args) : vector<vec<T, D - 1>>(n, vec<T, D - 1>(args...)) {}
};
template <typename T>
struct vec<T, 1> : vector<T> {
    vec(int n = 0, const T& val = T()) : vector<T>(n, val) {}
};

// https://lqdoj.edu.vn/problem/lqdojcontest7bai6
// graph, tree, hld, segtree, bitwise, math

int n, q;
vector<int> a(n);
////////////////////////////////////////
////////////////////////////////////////
struct Segtree {
    int n;
    vector<ll> st, lz;
    Segtree(int _n) : n(_n), st(n * 4, INFLL), lz(n * 4, INFLL) {}
    
    void push(int tv) {
        int l = tv * 2, r = l + 1;
        mnmz(st[l], lz[tv]);
        mnmz(st[r], lz[tv]);
        
        mnmz(lz[l], lz[tv]);
        mnmz(lz[r], lz[tv]);
        
        lz[tv] = INFLL;
    }
    
    void upd(int l, int r, ll v, int tl, int tr, int tv) {
        if (tr < l || r < tl) return;
        if (l <= tl && tr <= r) {
            mnmz(st[tv], v);
            mnmz(lz[tv], v);
            return;
        }
        push(tv);
        
        int tm = (tl + tr) / 2;
        upd(l, r, v, tl, tm, tv * 2);
        upd(l, r, v, tm + 1, tr, tv * 2 + 1);
        st[tv] = min(st[tv * 2], st[tv * 2 + 1]);
    }
    void upd(int l, int r, ll v) {
        upd(l, r, v, 0, n - 1, 1);
    }
    
    
    ll get(int l, int r, int tl, int tr, int tv) {
        if (tr < l || r < tl) return INFLL;
        if (l <= tl && tr <= r) {
            return st[tv];
        }
        push(tv);
        
        int tm = (tl + tr) / 2;
        return min(get(l, r, tl, tm, tv * 2), get(l, r, tm + 1, tr, tv * 2 + 1));
    }
    ll get(int l, int r) {
        return get(l, r, 0, n - 1, 1);
    }
};
////////////////////////////////////////
struct HLD {
    vector<vector<int>>& adj;
    int n, cpos = 0;
    Segtree st;
    vector<int> par, depth, heavy, head, pos;
    ////////////////////
    HLD(vector<vector<int>>& _adj) : adj(_adj), n(adj.size() - 1),
    st(n + 1), par(n + 1), depth(n + 1), heavy(n + 1), head(n + 1), pos(n + 1) {
        dfs(1);
        dcmp(1, 1);
    }
    ////////////////////////////////////////
    int dfs(int cur) {
        int size = 1, maxsize = 0;
        
        Forin(nxt, adj[cur]) {
            if (nxt == par[cur]) continue;
            
            par[nxt] = cur;
            depth[nxt] = depth[cur] + 1;
            
            int nxtsize = dfs(nxt);
            size += nxtsize;
            if (mxmz(maxsize, nxtsize)) heavy[cur] = nxt;
        }
        
        return size;
    }
    ////////////////////
    void dcmp(int cur, int chead) {
        head[cur] = chead;
        pos[cur] = cpos++;
        
        if (heavy[cur]) dcmp(heavy[cur], chead);
        Forin(nxt, adj[cur]) {
            if (nxt == par[cur] || nxt == heavy[cur]) continue;
            dcmp(nxt, nxt);
        }
    }
    ////////////////////
    void update(int u, int v, ll val) {
        while (head[u] != head[v]) {
            if (depth[head[u]] > depth[head[v]]) swap(u, v);
            st.upd(pos[head[v]], pos[v], val);
            v = par[head[v]];
        }
        if (depth[u] > depth[v]) swap(u, v);
        st.upd(pos[u] + 1, pos[v], val);
    }
    ////////////////////
    ll query(int u, int v) {
        ll res = INFLL;
        
        while (head[u] != head[v]) {
            if (depth[head[u]] > depth[head[v]]) swap(u, v);
            mnmz(res, st.get(pos[head[v]], pos[v]));
            v = par[head[v]];
        }
        if (depth[u] > depth[v]) swap(u, v);
        mnmz(res, st.get(pos[u] + 1, pos[v]));
        
        return res;
    }
};
////////////////////////////////////////
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////////
    
    
    
    
    ////////////////////
    return 0;
}