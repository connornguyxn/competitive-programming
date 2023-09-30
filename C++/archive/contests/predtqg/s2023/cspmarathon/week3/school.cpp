#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #pragma GCC optimize("O3,unroll-loops")
    #include <bits/stdc++.h>
    #define TASK "school"
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

// school
// <tags>

struct Node {
    int n;
    ll w;
};
int n, m, k;
ll x;
vector<vector<Node>> adj;
vector<int> mx;
////////////////////////////////////////
void dfs(int cur, ll cst, int s) {
    // print(cur, cst);
    Forin(nxt, adj[cur]) {
        // db(nxt.n, mx[nxt.n], cst + nxt.w);
        if (mx[nxt.n] || cst + nxt.w > x) continue;
        mx[nxt.n] = s;
        dfs(nxt.n, cst + nxt.w, s);
    }
}
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////
    cin >> n >> m >> k >> x;
    
    adj.resize(n + 1);
    Rep(i, m) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    mx.resize(n + 1);
    Forde(i, n, 1) {
        if (mx[i] == 0) mx[i] = i;
        dfs(i, 0, i);
    }
    
    int ans = n;
    Rep(i, k) mnmz(ans, mx[inp()]);
    
    cout << ans;
    ////////////////
    return 0;
}