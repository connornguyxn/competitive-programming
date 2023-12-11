#if DEBUG
    #include "lib/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "kconnect"
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
bool mxmz(T &a, T b) { return a < b ? a = b, 1 : 0; }
template <class T>
bool mnmz(T &a, T b) { return b < a ? a = b, 1 : 0; }
void add(ll &a, ll b) { a = (a + b) % MOD; }
void sub(ll &a, ll b) { a = (a + MOD - b) % MOD; }
void mul(ll &a, ll b) { a = a * (b % MOD) % MOD; }

// https://hnoj.edu.vn/contest/lqtbr2
// graph

struct Node {
    int n, id;
};
int n, m, k;
vector<vector<Node>> adj;
vector<int> ans, mrk;
////////////////////////////////////////
struct DSU {
    vector<int> par;
    
    DSU(int n) : par(n + 1, -1) {}
    
    void clear() {
        fill(par.begin(), par.end(), -1);
    }
    
    int get_root(int u) {
        if (par[u] < 0) return u;
        return par[u] = get_root(par[u]);
    }
    
    bool merge(int u, int v) {
        u = get_root(u); v = get_root(v);
        if (u == v) return false;
        if (par[u] > par[v]) swap(u, v);
        par[u] += par[v];
        par[v] = u;
        return true;
    }
    
    int cmp_size(int u) {
        return -par[get_root(u)];
    }
};
////////////////////
void dfs(int cur, int par) {
    Forin(nxt, adj[cur]) {
        if (nxt.n == par) continue;
        
        dfs(nxt.n, cur);
        mrk[cur] |= mrk[nxt.n];
        ans[nxt.id] = mrk[nxt.n];
    }
}
////////////////////////////////////////
int main() {
    // freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////////
    cin >> n >> m >> k;
    
    DSU dsu(n);
    adj.resize(n + 1);
    
    Rep(i, m) {
        int u, v;
        cin >> u >> v;
        if (dsu.merge(u, v)) {
            adj[u].push_back({v, i});
            adj[v].push_back({u, i});
        }
    }
    
    ans.resize(m);
    mrk.resize(n + 1);
    
    int x;
    Rep(i, k) {
        cin >> x;
        mrk[x]++;
    }
    dfs(x, x);
    
    Rep(i, m) cout << ans[i] << sp;
    ////////////////////
    return 0;
}