#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "ez"
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
const int N = 80000;
const ll MOD = 1e9 + 7;
const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
const int dx[8] = {0, -1, 0, 1, -1, -1, 1, 1};
const int dy[8] = {-1, 0, 1, 0, -1, 1, 1, -1};

// ez
// <tags>


int n, x, y;
vector<vector<int>> adj, val;
vector<int> w;
////////////////////////////////////////
bool dfs(int cur, int par, int tgt, bool ok) {
    // db(cur, par, tgt, ok);
    if (cur == tgt) return ok;
    Forin(nxt, adj[cur]) {
        if (nxt == par) continue;
        if (dfs(nxt, cur, tgt, ok || w[cur] == y)) return true;
    }
    return false;
}
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////
    cin >> n;
    
    w.resize(n + 1);
    val.resize(n + 1);
    Fore(i, 1, n) {
        cin >> w[i];
        val[w[i]].push_back(i);
    }
    
    adj.resize(n + 1);
    Rep(i, n - 1) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int tc = inp();
    while (tc--) {
        cin >> x >> y;
        // db(x, y);
        
        int ans = 0;
        vector<int> cur = val[x];
        Rep(i, cur.size()) {
            For(j, i + 1, cur.size()) {
                ans += dfs(cur[i], cur[i], cur[j], false);
            }
        }
        cout << ans << nl;
    }
    ////////////////
    return 0;
}