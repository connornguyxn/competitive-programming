#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "tinhphi"
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

// https://oj.vnoi.info/problem/chvpt_qtri_chondtqg_tinhphi
// graph, pathfinding

struct node {
    int n;
    ll w;
    int k = 0;
    bool operator<(const node oth) const {
        return w > oth.w;
    }
};
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(0);
    ////////////////
    int n, m, k, s, t;
    cin >> n >> m >> k >> s >> t;
    
    vector<vector<node>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    vector<vector<ll>> dst(n + 1, vector<ll>(k + 1, INFLL));
    dst[s][0] = 0;
    priority_queue<node> pq;
    pq.push({s, 0, 0});
    int mk = 0;
    
    while (pq.size()) {
        node cur = pq.top();
        pq.pop();
        
        if (cur.n == t) {
            mk |= bmask(cur.k);
            if (__builtin_popcount(mk) == k) break;
        }
        
        for (node nxt : adj[cur.n]) {
            if (cur.k < k && cur.w < dst[nxt.n][cur.k + 1]) {
                dst[nxt.n][cur.k + 1] = cur.w;
                pq.push({nxt.n, cur.w, cur.k + 1});
            }
            if (cur.w + nxt.w < dst[nxt.n][cur.k]) {
                dst[nxt.n][cur.k] = cur.w + nxt.w;
                pq.push({nxt.n, cur.w + nxt.w, cur.k});
            }
        }
    }
    
    cout << *min_element(all(dst[t]));
    ////////////////
    return 0;
}