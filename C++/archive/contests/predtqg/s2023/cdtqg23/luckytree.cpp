#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "luckytree"
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
#define all(var) (var).begin(), (var).end()
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define Repd(i, n) for (int i = (n); i--; )
#define For(i, l, r) for (int i = (l), _r = (r); i <= _r; i++)
#define Ford(i, r, l) for (int i = (r) + 1, _l = (l); --i >= _l; )
#define Forin(it, var) for (auto it : var)
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
void sub(ll &a, ll b) { a = (a + MOD * MOD - b) % MOD; }
void mul(ll &a, ll b) { a = a % MOD * (b % MOD) % MOD; }

struct edge {
    int u, v;
    ll w;
    bool operator<(edge oth) const {
        return w < oth.w;
    }
};
ostream& operator<<(ostream& out, edge x) {
    return out << '(' << x.u << sp << x.v << sp << x.w << ')';
}
int n;
vector<int> par;
////////////////////////////////////////
int root(int cur) {
    if (par[cur] < 0) return cur;
    return par[cur] = root(par[cur]);
}
bool merge(int u, int v) {
    if ((u = root(u)) == (v = root(v))) return false;
    if (par[u] > par[v]) swap(u, v);
    
    par[u] += par[v];
    par[v] = u;
    
    return true;
}
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////
    cin >> n;
    vector<ll> w(n + 1);
    For(i, 1, n) cin >> w[i];
    
    vector<edge> edges(n - 1);
    Rep(i, n - 1) {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v, max(w[u], w[v])};
    }
    
    ll ans = 0;
    
    sort(all(edges));
    par.assign(n + 1, -1);
    for (edge& cur : edges) {
        ll nu = -par[root(cur.u)];
        ll nv = -par[root(cur.v)];
        ans += cur.w * nu * nv;
        merge(cur.u, cur.v);
        
        cur.w = min(w[cur.u], w[cur.v]);
    }
    
    sort(edges.rbegin(), edges.rend());
    par.assign(n + 1, -1);
    for (edge& cur : edges) {
        ll nu = -par[root(cur.u)];
        ll nv = -par[root(cur.v)];
        ans -= cur.w * nu * nv;
        merge(cur.u, cur.v);
    }
    
    cout << ans;
    ////////////////
    return 0;
}