#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #pragma GCC optimize("O3,unroll-loops,inline")
    #include <bits/stdc++.h>
    #define TASK "veque"
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
#define b_mask(POS) (1ULL << (POS))
#define b_get(MASK, POS) ((MASK >> (POS)) & 1)
#define all(VAR) (VAR).begin(), (VAR).end()
const int N = 1e6;
const ll MOD = 1e9 + 7;
const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
// directions = left, up, right, down, upper_l, upper_r, lower_r, lower_l
const int dx[8] = {0, -1, 0, 1, -1, -1, 1, 1};
const int dy[8] = {-1, 0, 1, 0, -1, 1, 1, -1};
template<typename tVar, typename tVal>
void mnmz(tVar &var, tVal val) { if (val < var) var = val; }
template<typename tVar, typename tVal>
void mxmz(tVar &var, tVal val) { if (val > var) var = val; }

// veque
// graph, pathfinding

struct node {
    int n;
    ll w;
    bool operator>(const node oth) const {
        return w > oth.w;
    }
};
////////////////////////////////////////
ll dijkstra(int s, int t, const vector<vector<node>> &adj) {
    vector<ll> dst(adj.size(), INFLL);
    dst[s] = 0;
    
    priority_queue<node, vector<node>, greater<node>> pq;
    pq.push({s, 0});
    
    while (pq.size()) {
        node cur = pq.top();
        pq.pop();
        
        if (cur.n == t) break;
        
        for (node nxt : adj[cur.n]) {
            if (cur.w + nxt.w < dst[nxt.n]) {
                dst[nxt.n] = cur.w + nxt.w;
                pq.push({nxt.n, dst[nxt.n]});
            };
        }
    }
    
    return dst[t];
}
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(0);
    ////////////////
    int n, m, s, t, f;
    cin >> n >> m >> s >> f >> t;
    
    vector<vector<node>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    ll res = dijkstra(s, t, adj) + dijkstra(t, f, adj);
    cout << (res < INFLL ? res : -1);
    ////////////////
    return 0;
}