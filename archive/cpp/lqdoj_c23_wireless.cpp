#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #pragma GCC optimize("O3")
    #include <bits/stdc++.h>
    #define TASK "wireless"
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
#define Fors(i, l, r) for (int i = (l), _r = (r); i < _r; i++)
#define Forsd(i, r, l) for (int i = (r), _l = (l); --i >= _l; )
#define For(i, l, r) for (int i = (l), _r = (r); i <= _r; i++)
#define Ford(i, r, l) for (int i = (r) + 1, _l = (l); --i >= _l; )
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

// https://lqdoj.edu.vn/problem/lqdoj2023r1wireless
// graph, tree, incomplete

struct node {
    int n;
    ll w;
};
int n, q;
vector<vector<node>> adj;
vector<vector<int>> queries;
////////////////////////////////////////
struct sub1 {
    vector<vector<ll>> cost;
    
    void dfs(int cur, int par, int root, ll price) {
        cost[root][cur] = price;
        Forin(nxt, adj[cur]) {
            if (nxt.n == par) continue;
            dfs(nxt.n, cur, root, price + nxt.w);
        }
    }
    
    sub1() {
        cost.resize(n + 1, vector<ll>(n + 1));
        For(i, 1, n) {
            dfs(i, i, i, 0);
        }
        
        Forin(query, queries) {
            ll ans = INFLL;
            
            For(i, 1, n) {
                ll sum = 0;
                Forin(cur, query) {
                    sum += cost[cur][i];
                }
                
                mnmz(ans, sum);
            }
            cout << ans << nl;
        }
    }
};
////////////////////////////////////////
struct sub2 {
    int tmr, l;
    vector<int> tin, tout;
    vector<vector<int>> up;
    vector<vector<ll>> sum;
    
    void calc_price(int cur, int par, ll price) {
        sum[cur][0] = price;
        Forin(nxt, adj[cur]) {
            if (nxt.n == par) continue;
            calc_price(nxt.n, cur, price + nxt.w);
        }
    }
    
    void dfs(int cur, int par) {
        tin[cur] = ++tmr;
        up[cur][0] = par;
        
        For(i, 1, l) {
            up[cur][i] = up[up[cur][i - 1]][i - 1];
            sum[cur][i] = sum[cur][i - 1] + sum[up[cur][i - 1]][i - 1];
        }
        
        Forin(nxt, adj[cur]){
            if (nxt.n == par) continue;
            dfs(nxt.n, cur);
        }
        
        tout[cur] = ++tmr;
    }
    
    bool is_ancestor(int u, int v) {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }
        
    int lca(int u, int v) {
        if (is_ancestor(u, v)) return u;
        if (is_ancestor(v, u)) return v;
        for (int i = l; i >= 0; --i) {
            if (!is_ancestor(up[u][i], v))
                u = up[u][i];
        }
        return up[u][0];
    }
    
    ll path_sum(int u, int v) {
        int p = lca(u, v);
        ll res = 0;
        
        for (int i = l; i >= 0; --i) {
            if (!is_ancestor(up[u][i], p)) {
                res += sum[u][i];
                u = up[u][i];
            }
        }
        
        for (int i = l; i >= 0; --i) {
            if (!is_ancestor(up[v][i], p)) {
                res += sum[v][i];
                v = up[v][i];
            }
        }
        
        return res;
    }
    
    sub2() {
        tin.resize(n + 1);
        tout.resize(n + 1);
        tmr = 0;
        l = blog(n) + 1;
        
        up.assign(n + 1, vector<int>(l + 1));
        sum.assign(n + 1, vector<ll>(l + 1));
        
        calc_price(1, 1, 0);
        dfs(1, 1);
        
        Forin(query, queries) {
            cout << path_sum(query[0], query[1]) << nl;
        }
    }
};
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////
    cin >> n >> q;
    
    adj.resize(n + 1);
    Rep(i, n - 1) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    queries.resize(q);
    Rep(i, q) {
        int k;
        cin >> k;
        queries[i].resize(k);
        Rep(j, k) cin >> queries[i][j];
    }
    
    if ([&]() {
        Forin(query, queries) {
            if (query.size() > 2) return false;
        }
        return true;
    }()) {
        sub2();
    } else {
        sub1();
    }
    ////////////////
    return 0;
}