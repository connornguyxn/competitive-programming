#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #pragma GCC optimize("O3,unroll-loops,inline")
    #include <bits/stdc++.h>
    #define TASK "safenet"
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
#define mask(POS) (1ULL << (POS))
#define getbit(MASK, POS) ((MASK >> POS) & 1)
#define all(VAR) (VAR).begin(), (VAR).end()
const int N = 1e5;
const ull MOD = 1e9 + 7;
template<typename tVar, typename tVal>
void mnmz(tVar &var, tVal val) { if (val < var) var = val; }
template<typename tVar, typename tVal>
void mxmz(tVar &var, tVal val) { if (val > var) var = val; }
// offset = up, upper_r, right, lower_r, down, lower_l, left, upper_l
const int off_ver[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int off_hor[8] = {0, 1, 1, 1, 0, -1, -1, -1};

// https://voicamp2023hd.contest.codeforces.com/group/d65fJALFhR/contest/445196/problem/D
// graph

int n, m;
array<vector<int>, N + 1> adj;
array<int, N + 1> tin, low;
int timer = 1;
deque<int> st;
int res = 0;
////////////////////////////////////////
void dfs(int cur, int par) {
    tin[cur] = low[cur] = timer++;
    st.push_back(cur);
    
    for (int nxt : adj[cur]) {
        if (nxt == par) continue;
        
        if (!tin[nxt]) dfs(nxt, cur);
        mnmz(low[cur], low[nxt]);
        
        if (low[nxt] >= tin[cur]) {
            int node = 0, cnt = 1;
            while (node != nxt) {
                node = st.back();
                st.pop_back();
                cnt++;
            }
            mxmz(res, cnt);
        }
    }
}
////////////////////////////////////////
int main() {
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        // freopen(TASK".out", "w", stdout);
    };
    cin.tie(0) -> sync_with_stdio(0);
    ////////////////
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    };
    
    for (int i = 1; i <= n; i++) {
        if (!tin[i]) {
            dfs(i, 0);
        }
    }
    
    cout << res;
    ////////////////
    return 0;
}
/*
000000000000000000000000000000000000000000011111111100000000000000000000000000000000000000
0000000000000000000000000000000000001111.............1111111000000000000000000000000000000
00000000000000000000000000000000011.. .....11111111.........111000000000000000000000000000
000000000000000000000000000000011.  .1111111111111111111111.. .110000000000000000000000000
0000000000000000000000000000001. ..111111111111111111111111111. .1100000000000000000000000
000000000000000000000000000001. .111111111111111111111111111111. .110000000000000000000000
00000000000000000000000000001. .111111.............11111111111111. .1000000000000000000000
00000000000000000000000000001  111.   ..............   ...11111111. .100000000000000000000
0000000000000000000000000001. .11.  ..11111111111111111..  .1111111. .10000000000000000000
0000000000000000000000000001  111. ..11111111111111111111.  .1111111. .1000000000000000000
000000000000000000000000001. .111.  ..1111111111111111111.. .11111111. .100000000000000000
000000000000000000000000001. 11111.   ...11111111111111...  .11111111. .100000000000000000
000000000000000000000000011 .1111111..   ..............   .11111111111. 110000000000000000
00000000000000000000000001. .1111111111.................11111111111111. .10000000000000000
00000000000000000000000001 .1111111111111111111111111111111111111111111  10000000000000000
0000000000000000000000001. .1111111111111111111111111111111111111111111. .1000000000000000
0000000000000000000000001. 11111111111111111111111111111111111111111111. .1000000000000000
000000000000000000000001. .11111111111111111111111111111111111111111111. .1000000000000000
000000000000000000000001. .111111111111111111111111111111111111111111111 .1000000000000000
000000000000000000000011 .1111111111111111111111111111111111111111111111 .1000000000000000
00000000000000000000001. .1111111111111111111111111111111111111111111111. 1000000000000000
00000000000000000000001. 11111111111111111111111111111111111111111111111. 1000000000000000
0000000000000000000001. .11111111111111111111111111111111111111111111111. 1100000000000000
0000000000000000000001. .11111111111111111111111111111111111111111111111. 1100000000000000
0000000000000000000011 .111111111111111111111111111111111111111111111111. 1100000000000000
000000000000000000001. .111111111111111111111111111111111111111111111111. 1100000000000000
000000000000000000001 .1111111111111111111111111111111111111111111111111  1000000000000000
00000000000000000001. .1111111111111111111111111111111111111111111111111 .1000000000000000
00000000000000000001. 11111111111111111111.........11111111111111111111. .1000000000000000
0000000000000000001. .111111111111................... .1111111111111111. .1000000000000000
0000000000000000001. .111111111....111111111111111111. .111111111111111. .1000000000000000
0000000000000000011 .111111111. .100000000000000000001  111111111111111. .1000000000000000
000000111111111111. .111111111. .100000000000000000001  111111111111111. .1000000000000000
00111...............11111111111 .100000000000000000001 .111111111111111. .1000000000000000
001. ..111111111111111111111111. 110000000000000000001  111111111111111. .1000000000000000
001. 11111111111111111111111111. .10000000000000000001  111111111111111. .1000000000000000
001. .1111111111111111111111111. .10000000000000000001 .111111111111111. .1000000000000000
00011. ..11111111111111111111..  .1000000000111111111. .111111111111111 .10000000000000000
0000011.. ................. ...11100000111........... ..11111111111111. .10000000000000000
0000000111111...........111111000000011. ...11111111111111111111111111  110000000000000000
00000000000000000000000000000000000001. .111111111111111111111111111.  .100000000000000000
000000000000000000000000000000000000011. .11111111111111111111111.. ..11000000000000000000
00000000000000000000000000000000000000111.. ......111111111.... ...11000000000000000000000
00000000000000000000000000000000000000000111111...............1111000000000000000000000000
000000000000000000000000000000000000000000000000011111111111100000000000000000000000000000
*/