#if DEBUG
    #include "lib/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "uptree"
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

// nalgae_uptree
// dp, sqrtdcmp

int n;
vector<vector<int>> adj;
vector<int> par;
vector<ll> w;
map<pii, ll> dp;
////////////////////////////////////////
void dfs(int cur) {
    Forin(nxt, adj[cur]) if (nxt != par[cur]) {
        par[nxt] = cur;
        dfs(nxt);
    }
}
////////////////////
ll solve(pii cur) {
    if (cur.fi == 0 || cur.se == 0) return 0;
    if (dp.count(cur)) return dp[cur];
    return dp[cur] = solve({par[cur.fi], par[cur.se]}) + w[cur.fi] * w[cur.se];
}
////////////////////////////////////////
int main() {
    // freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////////
    int tc;
    cin >> n >> tc;
    
    w.resize(n + 1);
    For(i, 1, n) cin >> w[i];
    
    adj.resize(n + 1);
    Rep(i, n - 1) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    par.resize(n + 1);
    dfs(1);
    
    Rep(_, tc) {
        int u, v;
        cin >> u >> v;
        cout << solve({u, v}) << nl;
    }
    ////////////////////
    return 0;
}