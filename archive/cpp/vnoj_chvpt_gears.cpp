#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #pragma GCC optimize("O3,unroll-loops,inline")
    #include <bits/stdc++.h>
    #define TASK "gears"
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
const int N = 1e5 + 1;
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

// https://oj.vnoi.info/problem/chvpt_banhxe
// graph, dfs

array<vector<int>, N> adj;
array<int, N> root, type, stat, invalid;
////////////////////////////////////////
void dfs(int cur, int pre, int stt) {
    // db(cur, pre, stt);
    root[cur] = root[pre];
    if (stat[cur] != 0) {
        if (stat[cur] + stt == 0) {
            invalid[root[cur]] = 1;
        };
        return;
    }
    stat[cur] = stt;
    
    for (int nxt : adj[cur]) {
        if (nxt == pre) continue;
        
        if (type[cur] != type[nxt]) {
            dfs(nxt, cur, stt);
        } else {
            dfs(nxt, cur, -stt);
        }
    }
}
////////////////
bool ok(int u, int v, bool eql) {
    if (invalid[root[u]] || invalid[root[v]]) return false;
    if (root[u] != root[v]) return true;
    return eql == (stat[u] == stat[v]);
}
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(0);
    ////////////////
    int n, m, tc;
    cin >> n >> m >> tc;
    
    for (int i = 1; i <= n; i++) {
        cin >> type[i];
    }
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for (int i = 1; i <= n; i++) {
        if (stat[i] == 0) {
            root[0] = i;
            dfs(i, 0, 1);
        };
    }
    
    while (tc--) {
        int u, v, s1, s2;
        cin >> u >> v >> s1 >> s2;
        
        cout << (ok(u, v, s1 == s2) ? "YES" : "NO") << nl;
    }
    ////////////////
    return 0;
}