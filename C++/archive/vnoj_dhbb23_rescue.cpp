#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #pragma GCC optimize("O3,unroll-loops")
    #pragma GCC target("sse4.2")
    #include <bits/stdc++.h>
    #define TASK "rescue"
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
#define all(VAR) (VAR).begin(), (VAR).end()
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define Repd(i, n) for (int i = (n); i--; )
#define For(i, l, r) for (int i = (l), _b = (r); i < _b; i++)
#define Ford(i, r, l) for (int i = (r), _a = (l); --i >= _a; )
#define Fore(i, l, r) for (int i = (l), _b = (r); i <= _b; i++)
#define Forde(i, r, l) for (int i = (r), _a = (l); i >= _a; i++)
#define Forin(it, var) for (auto it : var)
template<typename tVar, typename tVal>
void mnmz(tVar &var, tVal val) { if (val < var) var = val; }
template<typename tVar, typename tVal>
void mxmz(tVar &var, tVal val) { if (val > var) var = val; }
#define bmask(POS) (1ULL << (POS))
#define bget(MASK, POS) ((MASK >> (POS)) & 1)
#define blog2(NUM) (__builtin_clzll(1) - __builtin_clzll(NUM))
const int N = 1e6;
const ll MOD = 1e9 + 7;
const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
const int dx[8] = {0, -1, 0, 1, -1, -1, 1, 1};
const int dy[8] = {-1, 0, 1, 0, -1, 1, 1, -1};

// https://lqdoj.edu.vn/contest/dhbb23
// pathfinding, dp, incomplete

struct node {
    int n;
    ll w;
    int a = 0, b = 0;
    bool r = 0;
    bool operator<(node oth) const {
        return w > oth.w;
    }
};
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(0);
    ////////////////
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    
    vector<vector<node>> adj(n + 1);
    Rep(i, m) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w, 0, 0, 0});
        adj[v].push_back({u, w, 0, 0, 1});
    }
    
    vector<vector<vector<vector<ll>>>> dst(n + 1,
                                        vector<vector<vector<ll>>>(a + 1,
                                        vector<vector<ll>>(b + 1,
                                        vector<ll>(2, INFLL))));
    dst[1][0][0][0] = 0;
    priority_queue<node> pq;
    pq.push({1, 0});
    
    while (pq.size()) {
        node cur = pq.top();
        pq.pop();
        
        Forin(nxt, adj[cur.n]) {
            if (nxt.r == cur.r && cur.w + nxt.w < dst[nxt.n][cur.a][cur.b][nxt.r]) {
                dst[nxt.n][cur.a][cur.b][nxt.r] = cur.w + nxt.w;
                pq.push({nxt.n, cur.w + nxt.w, cur.a, cur.b, nxt.r});
            }
            if (!cur.r && !nxt.r && cur.a < a && cur.w < dst[nxt.n][cur.a + 1][cur.b][0]) {
                dst[nxt.n][cur.a + 1][cur.b][0] = cur.w;
                pq.push({nxt.n, cur.w, cur.a + 1, cur.b, 0});
            }
            if (nxt.r && cur.b < b && cur.w + nxt.w * 2 < dst[nxt.n][cur.a][cur.b + 1][1]) {
                dst[nxt.n][cur.a][cur.b + 1][1] = cur.w + nxt.w * 2;
                pq.push({nxt.n, cur.w + nxt.w * 2, cur.a, cur.b + 1, 1});
            }
            if (nxt.r > cur.r && cur.w + nxt.w < dst[nxt.n][cur.a][cur.b][1]) {
                dst[nxt.n][cur.a][cur.b][1] = cur.w + nxt.w;
                pq.push({nxt.n, cur.w + nxt.w, cur.a, cur.b, 1});
            }
        }
    }
    
    Fore(i, 2, n) {
        ll res = INFLL;
        Fore(ca, 0, a) {
            Fore(cb, 0, b) {
                mnmz(res, *min_element(all(dst[i][ca][cb])));
            }
        }
        cout << res << sp;
    }
    ////////////////
    return 0;
}