#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "data"
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
void sub(ll &a, ll b) { a = (a + MOD - b) % MOD; }
void mul(ll &a, ll b) { a = a * (b % MOD) % MOD; }


struct node {
    int n, t;
    bool operator<(node oth) const {
        return t > oth.t;
    }
};
struct edge {
    int u, v;
    long double w;
    int t;
    bool operator<(edge oth) const {
        return w > oth.w;
    }
};
int n, m, s, t;
long double w;
vector<vector<node>> adj;
////////////////////////////////////////
long double dijkstra() {
    vector<int> dst(n + 1, INF);
    dst[s] = 0;
    priority_queue<node> pq;
    pq.push({s, 0});
    
    while (pq.size()) {
        node cur = pq.top();
        pq.pop();
        
        if (cur.t > dst[cur.n]) continue;
        if (cur.n == t) break;
        
        Forin(nxt, adj[cur.n]) {
            if (cur.t + nxt.t < dst[nxt.n]) {
                dst[nxt.n] = cur.t + nxt.t;
                pq.push({nxt.n, dst[nxt.n]});
            }
        }
    }
    
    return dst[t];
}
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////
    cin >> n >> m >> s >> t >> w;
    
    vector<edge> edg(m);
    Rep(i, m) {
        cin >> edg[i].u >> edg[i].v >> edg[i].w >> edg[i].t;
    }
    
    sort(all(edg));
    adj.resize(n + 1);
    
    long double ans = INFLL;
    Rep(i, m) {
        adj[edg[i].u].push_back({edg[i].v, edg[i].t});
        adj[edg[i].v].push_back({edg[i].u, edg[i].t});
        ans = min(ans, w / edg[i].w + dijkstra());
    }
    
    cout << fixed << setprecision(2) << ans;
    ////////////////
    return 0;
}