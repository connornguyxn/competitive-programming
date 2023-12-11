#if DEBUG
    #include "lib/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "checknet"
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

// lmh_checknet
// graph, tree
// difference array on tree

int n, m, k;
vector<int> sum;
vector<pii> range;
int tmr;
vector<vector<int>> a, up;
////////////////////////////////////////
void build(int cur, int pre) {
    range[cur].fi = tmr++;
    
    up[cur][0] = pre;
    For(i, 1, k) {
        up[cur][i] = up[up[cur][i - 1]][i - 1];
    }
    
    Forin(nxt, a[cur]) {
        if (nxt != pre) build(nxt, cur);
    }
    
    range[cur].se = tmr;
}
////////////////////
bool is_ansc(int u, int v) {
    return range[u].fi <= range[v].fi && range[u].se >= range[v].se;
}
////////////////////
int lca(int u, int v) {
    if (is_ansc(u, v)) return u;
    if (is_ansc(v, u)) return v;
    Repd(i, k) {
        if (!is_ansc(up[u][i], v)) u = up[u][i];
    }
    return up[u][0];
}
////////////////////////////////////////
void calcsum(int cur, int pre) {
    Forin(nxt, a[cur]) {
        if (nxt == pre) continue;
        calcsum(nxt, cur);
        sum[cur] += sum[nxt];
    }
}
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////////
    cin >> n >> m;
    a.resize(n + 1);
    Rep(i, n - 1) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    
    k = __lg(n) + 1;
    up.resize(n + 1, vector<int>(k + 1));
    range.resize(n + 1);
    
    build(1, 1);
    
    sum.resize(n + 1);
    Rep(i, m) {
        int u, v;
        cin >> u >> v;
        sum[u]++;
        sum[v]++;
        sum[lca(u, v)] -= 2;
    }
    // print(sum);
    
    calcsum(1, 1);
    // print(sum);
    
    int ans = 0;
    For(i, 1, n) ans += !!sum[i];
    cout << ans;
    ////////////////////
    return 0;
}