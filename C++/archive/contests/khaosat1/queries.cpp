#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #pragma GCC optimize("O3,unroll-loops,inline")
    #include <bits/stdc++.h>
    #define TASK "queries"
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
const int N = 2e5;
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

// https://oj.vnoi.info/problem/chvpt_kscldt_queries
// graph, tree

int n, tc;
struct node {
    int n;
    ll w;
};
struct edge {
    int u, v;
    ll w;
    bool operator<(const edge x) const {
        return w < x.w;
    };
};
vector<vector<node>> adj;
vector<edge> edges;
vector<ll> weight;
////////////////////////////////////////
struct sub3 {
    int par[N + 1];
    ////////////////
    int root(int v) {
        if (par[v] < 0) return v;
        return par[v] = root(par[v]);
    };
    ////////////////
    bool merge(int a, int b) {
        if ((a = root(a)) == (b = root(b))) return false;
        if (-par[a] < -par[b]) {
            swap(a, b);
        };
        par[a] += par[b];
        par[b] = a;
        return true;
    };
    ////////////////
    sub3() {
        memset(par, -1, sizeof(par));
        sort(all(edges));
        
        vector<ll> res(N + 1);
        ll cres = 0;
        for (edge cur : edges) {
            ll cntu = -par[root(cur.u)];
            ll cntv = -par[root(cur.v)];
            cres -= cntu * (cntu - 1) / 2;
            cres -= cntv * (cntv - 1) / 2;
            merge(cur.u, cur.v);
            cntu = -par[root(cur.u)];
            cres += cntu * (cntu - 1) / 2;
            res[cur.w] = cres;
        }
        
        while (tc--) {
            ll mx;
            cin >> mx;
            int w = lower_bound(all(weight), mx + 1) - weight.begin() - 1;
            cout << res[weight[w]] << sp;
        }
    }
};
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(0);
    ////////////////
    cin >> n >> tc;
    
    adj.resize(n + 1);
    weight.push_back(0);
    for (int i = 1; i < n; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        edges.push_back({u, v, w});
        weight.push_back(w);
    }
    sort(all(weight));
    
    // if (n <= 5000) {
    //     sub2();
    // } else {
        sub3();
    // }
    
    ////////////////
    return 0;
}