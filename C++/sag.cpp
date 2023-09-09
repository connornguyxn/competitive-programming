#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "sag"
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

// sag
// <tags>

struct Dsu {
    int n;
    vector<int> par;
    
    Dsu(int _n) : n(_n), par(n, -1) {}
    
    int root(int cur) {
        if (par[cur] < 0) return cur;
        return par[cur] = root(par[cur]);
    }
    
    bool merge(int u, int v) {
        if ((u = root(u)) == (v = root(v))) return false;
        if (-par[v] > -par[u]) swap(u, v);
        par[u] += par[v];
        par[v] = u;
        return true;
    }
};
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////
    int n, k, m;
    cin >> n >> k >> m;
    
    Dsu dsu(n + 1);
    
    vector<pii> edges;
    Rep(i, m) {
        str inp;
        cin >> inp;
        
        int a = 0, b = 0;
        char cmp = sp;
        Forin(it, inp) {
            if (it > '9') {
                cmp = it;
                continue;
            }
            if (cmp == sp) {
                a = a * 10 + (it - '0');
            } else {
                b = b * 10 + (it - '0');
            }
        }
        
        if (cmp == '>') swap(a, b);
        if (cmp == '=') {
            dsu.merge(a, b);
        } else {
            edges.push_back({a, b});
        }
    }
    
    vector<vector<int>> adj(n + 1), rev(n + 1);
    vector<int> deg(n + 1), root(n + 1);
    
    Fore(i, 1, n) root[i] = dsu.root(i);
    
    Forin(it, edges) {
        adj[root[it.fi]].push_back(root[it.se]);
        deg[root[it.se]]++;
        rev[root[it.se]].push_back(root[it.fi]);
    }
    
    
    ////////////////
    return 0;
}