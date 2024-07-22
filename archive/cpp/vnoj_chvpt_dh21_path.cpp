#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #pragma GCC optimize("O3,unroll-loops,inline")
    #include <bits/stdc++.h>
    #define TASK "path"
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
const int N = 1e5 + 10;
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

// https://oj.vnoi.info/problem/chvpt_duyenhai21_ld_path
// dp, graph, tree

int n;
vector<int> adj[N];
ll dpp[N][2], dpt[N][2];
////////////////////////////////////////
void calc1(int cur, int par) {
    dpp[cur][1] = 1;
    dpt[cur][1] = 1;
    
    priority_queue<ll> mxp;
    for (int nxt : adj[cur]) {
        if (nxt == par) continue;
        calc1(nxt, cur);
        
        mxmz(dpp[cur][1], dpp[nxt][1] + 1);
        mxp.push(dpp[nxt][1]);
        
        mxmz(dpt[cur][1], dpt[nxt][1]);
    }
    
    if (mxp.size() > 1) {
        ll p1 = mxp.top();
        mxp.pop();
        ll p2 = mxp.top();
        mxmz(dpt[cur][1], p1 + p2 + 1);
    }
}
////////////////////////////////////////
void calc0(int cur, int par) {
    set<pll, greater<pll>> mxp, mxt;
    for (int nxt : adj[cur]) {
        if (nxt == par) continue;
        mxp.insert({dpp[nxt][1], nxt});
        mxt.insert({dpt[nxt][1], nxt});
        dpp[nxt][0] = dpp[cur][0] + 1;
        dpt[nxt][0] = dpt[cur][0];
    }
    
    for (int nxt : adj[cur]) {
        if (nxt == par) continue;
        mxp.erase({dpp[nxt][1], nxt});
        mxt.erase({dpt[nxt][1], nxt});
        
        if (mxp.size()) {
            mxmz(dpp[nxt][0], (*mxp.begin()).fi + 1);
            mxp.insert({dpp[cur][0], cur});
            dpt[nxt][0] = max({dpt[nxt][0], (*mxp.begin()).fi + (*(++mxp.begin())).fi + 1, (*mxt.begin()).fi});
            mxp.erase({dpp[cur][0], cur});
        }
        
        mxp.insert({dpp[nxt][1], nxt});
        mxt.insert({dpt[nxt][1], nxt});
    }
    
}
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(0);
    ////////////////
    cin >> n;
    
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    calc1(1, 0);
    calc0(1, 0);
    
    for (int i = 1; i <= n; i++) {
        cout << dpt[i][1] << sp;
    }
    cout << nl;
    for (int i = 1; i <= n; i++) {
        cout << dpp[i][1] << sp;
    }
    cout << nl;
    
    for (int i = 1; i <= n; i++) {
        cout << dpt[i][0] << sp;
    }
    cout << nl;
    for (int i = 1; i <= n; i++) {
        cout << dpp[i][0] << sp;
    }
    cout << nl;
    
    ll res = 1;
    for (int i = 1; i <= n; i++) {
        mxmz(res, dpt[i][0] * dpt[i][1]);
    }
    
    cout << res;
    ////////////////
    return 0;
}