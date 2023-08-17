#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #pragma GCC optimize("O3,unroll-loops")
    #pragma GCC target("sse4.2")
    #include <bits/stdc++.h>
    #define TASK "543d"
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
template <typename... T>
void print(T&&... n) {
    using exp = int[];
    exp{0, (cout << n << sp, 0)...};
    cout << nl;
}
template <class T>
void mxmz(T &a, T b) { a = max(a, b); }
template <class T>
void mnmz(T &a, T b) { a = max(a, b); }
const int N = 1e6;
const ll MOD = 1e9 + 7;
const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
const int dx[8] = {0, -1, 0, 1, -1, -1, 1, 1};
const int dy[8] = {-1, 0, 1, 0, -1, 1, 1, -1};

// https://codeforces.com/contest/543/problem/D
// <tags>

int n;
vector<vector<int>> adj;
vector<ll> down, up, pre;
////////////////////////////////////////
void dfs_down(int cur, int par) {
    down[cur] = 1;
    for (int nxt : adj[cur]) {
        if (nxt == par) continue;
        dfs_down(nxt, cur);
        down[cur] *= down[nxt] + 1;
    }
    for(int nxt : adj[cur]){
        pre[nxt] = .0
        
    }
}
void dfs_up(int cur, int par) {
    for (int nxt : adj[cur]) {
        if (nxt == par) continue;
        up[nxt] = down[cur] / (down[nxt] + 1) * (up[cur] + 1);
        dfs_up(nxt, cur);
    }
}
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////
    cin >> n;
    adj.resize(n + 1);
    Fore(i, 2, n) {
        int u = inp();
        adj[i].push_back(u);
        adj[u].push_back(i);
    }
    cout << adj;
    
    down.resize(n + 1);
    up.resize(n + 1);
    pre.resize(n + 1);
    
    dfs_down(1, 1);
    up[1] = 1;
    for (int nxt : adj[1]) {
        up[nxt] = down[1] / (down[nxt] + 1) + 1;
        cout << up[nxt] <<" "<< nxt <<"\n";
        dfs_up(nxt, 1);
    }
    
    db(down);
    db(up);
    ////////////////
    return 0;
}