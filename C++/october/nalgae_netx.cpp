#if DEBUG
    #include "lib/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "netx"
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
template <int D, typename T>
struct vec : vector<vec<D - 1, T>> {
    template<typename... Args>
    vec(int n = 1, Args... args) : vector<vec<D - 1, T>>(n, vec<D - 1, T>(args...)) {}
};
template<typename T>
struct vec<1, T> : vector<T> {
    vec(int n = 0, const T& val = T()) : vector<T>(n, val) {}
};

// nalgae_netx
// graph, dfstree

struct DSU {
    vector<int> lab;
    
    DSU(int n) : lab(n + 1, -1) {}
    
    int getRoot(int u) {
        if (lab[u] < 0) return u;
        return lab[u] = getRoot(lab[u]);
    }
    
    bool merge(int u, int v) {
        u = getRoot(u); v = getRoot(v);
        if (u == v) return false;
        if (lab[u] > lab[v]) swap(u, v);
        lab[u] += lab[v];
        lab[v] = u;
        return true;
    }
    
    bool same_component(int u, int v) {
        return getRoot(u) == getRoot(v);
    }
    
    int component_size(int u) {
        return -lab[getRoot(u)];
    }
};
int n, m;
vector<vector<int>> adj;
vector<int> low, num, par;
set<pii> bridge;
int tmr;
////////////////////////////////////////
void dfs(int cur) {
    num[cur] = low[cur] = ++tmr;
    Forin(nxt, adj[cur]) {
        if (!num[nxt]) {
            par[nxt] = cur;
            dfs(nxt);
            low[cur] = min(low[cur], low[nxt]);
            if (low[nxt] > num[cur]) {
                bridge.insert({min(cur, nxt), max(cur, nxt)});
            }
        } else if (nxt != par[cur]) {
            low[cur] = min(low[cur], num[nxt]);
        }
    }
}
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////////
    cin >> n >> m;
    
    adj.resize(n + 1);
    num = par = low = vector<int>(n + 1);
    
    vector<pii> edges;
    Rep(i, m) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.push_back({min(u, v), max(u, v)});
    }
    
    dfs(1);
    DSU dsu(n);
    
    Forin(edge, edges) {
        if (bridge.count(edge)) continue;
        dsu.merge(edge.fi, edge.se);
    }
    vector<int> cnt(n + 1);
    set<int> comp;
    Forin(it, bridge) {
        cnt[dsu.getRoot(it.fi)]++;
        cnt[dsu.getRoot(it.se)]++;
        comp.insert(dsu.getRoot(it.fi));
        comp.insert(dsu.getRoot(it.se));
    }
    
    int ans = 0;
    Forin(it, comp) {
        if (cnt[it] == 1) ans++;
    }
    
    cout << (ans + 1) / 2;
    ////////////////////
    return 0;
}