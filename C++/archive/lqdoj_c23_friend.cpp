#if DEBUG
    #include "lib/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "friend"
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
void mxmz(T &a, T b) { a = max(a, b); }
template <class T>
void mnmz(T &a, T b) { a = min(a, b); }
void add(ll &a, ll b) { a = (a + b) % MOD; }
void sub(ll &a, ll b) { a = (a + MOD - b) % MOD; }
void mul(ll &a, ll b) { a = a * (b % MOD) % MOD; }

// lqdoj_c23_friend
// <tags>

struct node {
    int n, cs, cm;
};
int n, k;
vector<vector<node>> adj;
vector<ll> cnt, cs, cm;
vector<vector<int>> up;
vector<int> tin, tout;
int timer = 0;
////////////////////////////////////////
void buildlca(int cur, int par, int c1, int c2) {
    cs[cur] = c1;
    cm[cur] = c2;
    tin[cur] = ++timer;
    up[cur][0] = par;
    For(i, 1, k) up[cur][i] = up[up[cur][i - 1]][i - 1];
    Forin(nxt, adj[cur]) if (nxt.n != par) buildlca(nxt.n, cur, nxt.cs, nxt.cm);
    tout[cur] = ++timer;
}
////////////////////
bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}
////////////////////
int lca(int u, int v) {
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = k; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}
////////////////////////////////////////
ll buildcnt(int cur, int par) {
    ll res = 0;
    Forin(nxt, adj[cur]) if (nxt.n != par) res += buildcnt(nxt.n, cur);
    return cnt[cur] += res;
}
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////////
    cin >> n;
    adj.resize(n + 1);
    
    Rep(i, n - 1) {
        int u, v, c1, c2;
        cin >> u >> v >> c1 >> c2;
        adj[u].push_back({v, c1, c2});
        adj[v].push_back({u, c1, c2});
    }
    
    k = blog2(n + 1);
    up.resize(n + 1, vector<int>(k + 1));
    tin.resize(n + 1);
    tout.resize(n + 1);
    cnt.resize(n + 1);
    cs.resize(n + 1);
    cm.resize(n + 1);
    buildlca(1, 1, 0, 0);
    
    For(i, 2, n) {
        int l = lca(i, i - 1);
        cnt[i]++;
        cnt[i - 1]++;
        cnt[l] -= 2;
    }
    
    buildcnt(1, 1);
    // print(cnt);
    // print(cs);
    // print(cm);
    
    ll ans = 0;
    For(i, 2, n) {
        ans += min(cs[i] * cnt[i], cm[i]);
    }
    cout << ans;
    ////////////////////
    return 0;
}