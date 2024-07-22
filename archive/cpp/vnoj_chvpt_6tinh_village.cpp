#if DEBUG
    #include "lib/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "village"
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
#define Ford(i, r, l) for (int i = (r) + 1, _l = (l); --i >= _l; )
#define Forin(it, var) for (auto& it : var)
#define bmask(i) (1ULL << (i))
#define bget(mask, i) ((mask >> (i)) & 1)
const int N = 2e5;
const ll MOD = 1e9 + 7;
const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
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

// https://oj.vnoi.info/contest/chvpt_6tinh2324
// hashing, hld, segtree, implementation

struct Query {
    int u, v, t = -1;
};
int n, q, mx;
vector<Query> qs;
vec<int, 2> a;
////////////////////////////////////////////////
ll powmod(ll n, ll k) {
    n %= MOD;
    ll res = 1;
    
    while (k) {
        if (k % 2) mul(res, n);
        mul(n, n);
        k /= 2;
    }
    
    return res;
}
////////////////////////////////////////////////
int hld_cur_pos = 0;
vector<int> par, depth, heavy, head, pos;
////////////////////////////////////////////////
int hld_dfs(int cur) {
    int size = 1, mx_size = 0;
    
    for (int nxt : a[cur]) {
        if (nxt == par[cur]) continue;
        
        par[nxt] = cur;
        depth[nxt] = depth[cur] + 1;
        
        int nxt_size = hld_dfs(nxt);
        size += nxt_size;
        
        if (nxt_size >= mx_size) {
            heavy[cur] = nxt;
            mx_size = nxt_size;
        }
    }
    
    return size;
}
////////////////////
void hld_decompose(int cur, int cur_head) {
    head[cur] = cur_head;
    pos[cur] = hld_cur_pos++;
    
    if (heavy[cur]) hld_decompose(heavy[cur], cur_head);
    
    for (int nxt : a[cur]) {
        if (nxt == par[cur] || nxt == heavy[cur]) continue;
        hld_decompose(nxt, nxt);
    }
}
////////////////////////////////////////////////
vector<ll> st, lz;
////////////////////
ll st_combine(ll a, ll b) {
    if (a == -2) return b;
    if (b == -2) return a;
    return (a != -1 && b == a) ? a : -1;
}
////////////////////
void st_push(int tv) {
    if (st[tv * 2] != -1) add(st[tv * 2], lz[tv]);
    if (st[tv * 2 + 1] != -1) add(st[tv * 2 + 1], lz[tv]);
    
    add(lz[tv * 2], lz[tv]);
    add(lz[tv * 2 + 1], lz[tv]);
    
    lz[tv] = 0;
}
////////////////////////
void st_update(int l, int r, ll v, int tl = 0, int tr = mx - 1, int tv = 1) {
    if (tr < l || r < tl) return;
    if (l <= tl && tr <= r) {
        if (st[tv] != -1) add(st[tv], v);
        add(lz[tv], v);
        return;
    }
    
    st_push(tv);
    int tm = (tl + tr) / 2;
    st_update(l, r, v, tl, tm, tv * 2);
    st_update(l, r, v, tm + 1, tr, tv * 2 + 1);
    
    st[tv] = st_combine(st[tv * 2], st[tv * 2 + 1]);
}
////////////////////
ll st_get(int l, int r, int tl = 0, int tr = mx - 1, int tv = 1) {
    if (tr < l || r < tl) return -2;
    if (l <= tl && tr <= r) return st[tv];
    
    st_push(tv);
    int tm = (tl + tr) / 2;
    ll lq = st_get(l, r, tl, tm, tv * 2);
    ll rq = st_get(l, r, tm + 1, tr, tv * 2 + 1);
    
    return st_combine(lq, rq);
}
////////////////////////////////////////////////
void update(int u, int v, int t) {
    for (; head[u] != head[v]; v = par[head[v]]) {
        if (depth[head[u]] > depth[head[v]]) swap(u, v);
        st_update(pos[head[v]], pos[v], t);
    }
    
    if (depth[u] > depth[v]) swap(u, v);
    st_update(pos[u], pos[v], t);
}
////////////////////
bool query(int u, int v) {
    for (; head[u] != head[v]; v = par[head[v]]) {
        if (depth[head[u]] > depth[head[v]]) swap(u, v);
        if (st_get(pos[head[v]], pos[v]) == -1) return false;
    }
    
    if (depth[u] > depth[v]) swap(u, v);
    if (st_get(pos[u], pos[v]) == -1) return false;
    
    return true;
}
////////////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////////////
    cin >> n >> q;
    
    a.resize(n + 1);
    Rep(i, n - 1) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    
    vector<int> zip;
    qs.resize(q);
    
    Forin(it, qs) {
        int c;
        cin >> c >> it.u >> it.v;
        if (c == 1) {
            cin >> it.t;
            zip.push_back(it.t);
        }
    }
    
    sort(all(zip));
    zip.erase(unique(all(zip)));
    Forin(it, qs) if (it.t > 0) {
        it.t = lower_bound(all(zip), it.t) - zip.begin();
    }
    mx = zip.size();
    
    pos.resize(n + 1);
    par = depth = heavy = head = pos;
    hld_dfs(1);
    hld_decompose(1, 1);
    
    st.resize(mx * 4);
    lz = st;
    
    Forin(it, qs) {
        if (it.t == -1) {
            cout << query(it.u, it.v) << nl;
        } else {
            update(it.u, it.v, powmod(mx, it.t));
        }
    }
    ////////////////////////
    return 0;
}