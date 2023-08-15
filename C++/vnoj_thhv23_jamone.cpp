#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #pragma GCC optimize("O3,unroll-loops")
    #pragma GCC target("sse4.2")
    #include <bits/stdc++.h>
    #define TASK "jamone"
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
const int N = 1e6;
const ll MOD = 1e9 + 7;
const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
const int dx[8] = {0, -1, 0, 1, -1, -1, 1, 1};
const int dy[8] = {-1, 0, 1, 0, -1, 1, 1, -1};

// https://oj.vnoi.info/problem/chvpt_thhv2023_jamone
// graph, pathfinding, dp

struct node {
    int n, w, d;
    bool st = false;
    bool operator<(node oth) const {
        if (d == oth.d) return w > oth.w;
        return d > oth.d;
    }
};
int n, m;
vector<vector<node>> adj;
////////////////////////////////////////
int dijkstra(int s, int t) {
    vector<vector<int>> dst(n + 1, vector<int>(2, INF));
    dst[s][0] = 0;
    priority_queue<node> pq;
    pq.push({s, 0, 0, 0});
    
    while (pq.size()) {
        node cur = pq.top();
        pq.pop(); 
        
        for (node nxt : adj[cur.n]) {
            if (cur.st) {
                if (nxt.d > cur.d) continue;
                if (nxt.w + cur.w < dst[nxt.n][1]) {
                    dst[nxt.n][1] = nxt.w + cur.w;
                    pq.push({nxt.n, dst[nxt.n][1], cur.d, true});
                }
            } else {
                if (nxt.w + cur.w + nxt.d < dst[nxt.n][1]) {
                    dst[nxt.n][1] = nxt.w + cur.w + nxt.d;
                    pq.push({nxt.n, dst[nxt.n][1], max(cur.d, nxt.d), true});
                }
                if (nxt.w + cur.w < dst[nxt.n][0]) {
                    dst[nxt.n][0] = nxt.w + cur.w;
                    pq.push({nxt.n, dst[nxt.n][0], max(cur.d, nxt.d), false});
                }
            }
        }
    }
    
    return dst[t][1];
}
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////
    int tc;
    cin >> n >> m >> tc;
    
    adj.resize(n + 1);
    Rep(i, m) {
        int u, v, p, q;
        cin >> u >> v >> p >> q;
        adj[u].push_back({v, p, q - p});
        adj[v].push_back({u, p, q - p});
    }
    
    while (tc--) {
        int s, t;
        cin >> s >> t;
        cout << dijkstra(s, t) << nl;
    }
    ////////////////
    return 0;
}