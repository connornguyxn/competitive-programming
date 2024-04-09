#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #pragma GCC optimize("O3,unroll-loops,inline")
    #include <bits/stdc++.h>
    #define TASK "329b"
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
const int N = 1e3;
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

// https://codeforces.com/problemset/problem/329/B
// graph, bfs

////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(0);
    ////////////////
    int n, m;
    cin >> n >> m;
    
    pii s, e;
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'S') s = {i, j};
            if (grid[i][j] == 'E') e = {i, j};
        }
    }
    
    auto ok = [&](pii cur) {
        if (cur.fi < 0 || cur.fi == n) return false;
        if (cur.se < 0 || cur.se == m) return false;
        if (grid[cur.fi][cur.se] == 'T') return false;
        return true;
    };
    vector<vector<int>> dst(n, vector<int>(m, INF));
    dst[e.fi][e.se] = 0;
    deque<pii> q = {e};
    
    while (q.size()) {
        pii cur = q.back();
        q.pop_back();
        
        for (int d = 0; d < 4; d++) {
            pii nxt = {cur.fi + dx[d], cur.se + dy[d]};
            
            if (!ok(nxt) || dst[nxt.fi][nxt.se] <= dst[cur.fi][cur.se] + 1) continue;
            dst[nxt.fi][nxt.se] = dst[cur.fi][cur.se] + 1;
            q.push_front(nxt);
        }
    }
    
    int res = 0;
    grid[s.fi][s.se] = '0';
    grid[e.fi][e.se] = '0';
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dst[i][j] <= dst[s.fi][s.se]) {
                res += grid[i][j] - '0';
            }
        }
    }
    
    cout << res;
    ////////////////
    return 0;
}