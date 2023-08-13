#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #pragma GCC optimize("O3,unroll-loops,inline")
    #include <bits/stdc++.h>
    #define TASK "shortestdk"
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

// https://oj.vnoi.info/problem/chvpt_shortestdk
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
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<vector<node>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    vector<vector<ll>> dst(n + 1, vector<ll>(k + 1, INFLL));
    dst[1][0] = 0;
    priority_queue<node> pq;
    pq.push({1, 0, 0});
    
    while (pq.size()) {
        node cur = pq.top();
        pq.pop();
        
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
    
    for (int i = 1; i <= n; i++) {
        cout << *min_element(all(dst[i])) << sp;
    }
    ////////////////
    return 0;
}
