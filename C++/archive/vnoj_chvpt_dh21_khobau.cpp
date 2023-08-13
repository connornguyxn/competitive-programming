#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #pragma GCC optimize("O3,unroll-loops,inline")
    #include <bits/stdc++.h>
    #define TASK "khobau"
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

// https://oj.vnoi.info/problem/chvpt_duyenhai21_tq_khobau
// bruteforce, pathfinding

vector<pii> cpath;
vector<vector<pii>> paths;
bool mk[3][3];
void dfs(int x, int y, int cnt) {
    mk[x][y] = 1;
    cpath.push_back({x, y});
    
    if (cnt == 9) {
        paths.push_back(cpath);
    } else {
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || nx > 2) continue;
            if (ny < 0 || ny > 2) continue;
            if (mk[nx][ny]) continue;
            
            dfs(nx, ny, cnt + 1);
        }
    }
    mk[x][y] = 0;
    cpath.pop_back();
}

void solve() {
    str a[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> a[i][j];
        }
    }
    
    str res = "000000000";
    for (vector<pii> path : paths) {
        str cur = "";
        for (pii it : path) {
            cur += a[it.fi][it.se];
        }
        mxmz(res, cur);
    }
    
    cout << res;
}
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(0);
    ////////////////
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            dfs(i, j, 1);
        }
    }
    
    int tc;
    cin >> tc;
    
    while (tc--) {
        solve();
        cout << nl;
    }
    ////////////////
    return 0;
}