#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "test"
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
#define Fors(i, l, r) for (int i = (l), _r = (r); i < _r; i++)
#define Forsd(i, r, l) for (int i = (r), _l = (l); --i >= _l; )
#define For(i, l, r) for (int i = (l), _r = (r); i <= _r; i++)
#define Ford(i, r, l) for (int i = (r) + 1, _l = (l); --i >= _l; )
#define Forin(it, var) for (auto it : var)
#define bmask(i) (1ULL << (i))
#define bget(mask, i) ((mask >> (i)) & 1)
#define blog(n) (63 - __builtin_clzll(n))
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

struct node {
    int n;
    ll w;
    bool mk;
    bool operator<(node oth) const {
        if (w == oth.w) return mk > oth.mk;
        return w > oth.w;
    };
};
ostream& operator<<(ostream& os, node n) {
    os << '(' << n.n << sp << n.w << sp << n.mk << ')';
    return os;
}
int n, m, k;
vector<vector<node>> adj;
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////
    cin >> n >> m >> k;
    
    adj.resize(n + 1);
    Rep(i, m) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w, false});
        adj[v].push_back({u, w, false});
    }
    
    Rep(i, k) {
        int v, w;
        cin >> v >> w;
        adj[1].push_back({v, w, true});
    }
    
    // For(i, 1, n) {
    //     cout << i << sp;
    //     Forin(it, adj[i]) {
    //         cout << '(' << it.n << sp << it.w << sp << it.mk << ')' << sp;
    //     }
    //     cout << nl;
    // }
    
    vector<bool> ans(n + 1);
    int cnt = 0;
    vector<ll> dst(n + 1, INFLL);
    dst[1] = 0;
    priority_queue<node> pq;
    pq.push({1, 0, false});
    
    while (pq.size()) {
        node cur = pq.top();
        pq.pop();
        
        Forin(nxt, adj[cur.n]) {
            
        }
    }
    
    cout << cnt;
    ////////////////
    return 0;
}