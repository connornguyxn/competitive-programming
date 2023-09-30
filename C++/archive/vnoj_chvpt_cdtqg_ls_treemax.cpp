#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "treemax"
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
#define For(i, l, r) for (int i = (l), _r = (r); i <= _r; i++)
#define Ford(i, r, l) for (int i = (r) + 1, _l = (l); --i >= _l; )
#define Forin(it, var) for (auto it : var)
#define bmask(i) (1ULL << (i))
#define bget(mask, i) ((mask >> (i)) & 1)
#define blog2(n) (63 - __builtin_clzll(n))
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
const ll MOD = 1e9 + 7;
const ull BASE = 311;
const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
const int dx[8] = {0, -1, 0, 1, -1, -1, 1, 1};
const int dy[8] = {-1, 0, 1, 0, -1, 1, 1, -1};

// https://oj.vnoi.info/problem/chvpt_lson23_treemax
// graph, tree, datastruct


int n;
vector<vector<int>> adj;
vector<int> val;
struct segtree {
    int n;
    vector<int> t;
    
    void build(const vector<int>& a) {
        for (int i = 0; i < n; i++) t[n + i] = a[i];
        for (int i = n - 1; i > 0; i--) {
            t[i] = max(t[i * 2], t[i * 2 + 1]);
        };
    }
    
    int get(int l, int r) {
        int res = -INFINITY;
        
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l % 2) res = max(res, t[l++]);
            if (r % 2) res = max(res, t[--r]);
        }
        
        return res;
    }
    
    segtree(const vector<int>& a) : n(a.size()), t(n * 2) {
        build(a);
    }
};
////////////////////////////////////////
int tmr;
vector<int> tin, tou;
vector<vector<int>> pin, pou, pvl;
////////////////////////
void dfs(int cur, int h) {
    tin[cur] = tmr++;
    pin[h].push_back(tin[cur]);
    
    Forin(nxt, adj[cur]) {
        dfs(nxt, h + 1);
    }
    tou[cur] = tmr;
    pou[h].push_back(tou[cur]);
}
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////
    int n;
    cin >> n;
    
    val.resize(n + 1);
    For(i, 1, n) cin >> val[i];
    
    adj.resize(n + 1);
    For(i, 2, n) {
        int u;
        cin >> u;
        adj[u].push_back(i);
    }
    
    tin.resize(n + 1);
    tou.resize(n + 1);
    pin.resize(n + 1);
    pou.resize(n + 1);
    
    dfs(1, 0);
    
    print(pin);
    print(pou);
    ////////////////
    return 0;
}