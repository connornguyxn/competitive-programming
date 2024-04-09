#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #pragma GCC optimize("O3,unroll-loops")
    #pragma GCC target("sse4.2")
    #include <bits/stdc++.h>
    #define TASK "game"
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
#define For(i, l, r) for (int i = (l), _r = (r); i < _r; i++)
#define Ford(i, r, l) for (int i = (r), _l = (l); --i >= _l; )
#define Fore(i, l, r) for (int i = (l), _r = (r); i <= _r; i++)
#define Forde(i, r, l) for (int i = (r) + 1, _l = (l); --i >= _l; )
#define Forin(it, var) for (auto it : var)
#define Bmask(i) (1ULL << (i))
#define Bget(mask, i) ((mask >> (i)) & 1)
#define Blog(n) (63 - __builtin_clzll(n))
template <class T = int>
T inp() { T x; cin >> x; return x; }
template <typename... T>
void print(T&&... n) {
    using exp = int[];
    exp{0, (cout << n << sp, 0)...};
    cout << nl;
}
const int N = 1e6;
const ll MOD = 1e9 + 7;
const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
const int dx[8] = {0, -1, 0, 1, -1, -1, 1, 1};
const int dy[8] = {-1, 0, 1, 0, -1, 1, 1, -1};

// https://oj.vnoi.info/problem/chvpt_trasua_game
// dp, easy

////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////
    int n, m, val;
    cin >> n >> m >> val;
    
    vector<vector<int>> mx(n + 1, vector<int>(m + 2, 0)),
                        mn(n + 1, vector<int>(m + 2, INF));
    
    fill(all(mx[0]), val);
    fill(all(mn[0]), val);
    
    Fore(i, 1, n) {
        Fore(j, 1, m) {
            int a = inp();
            if (a) {
                mx[i][j] = max({mx[i - 1][j - 1], mx[i - 1][j], mx[i - 1][j + 1]}) + a;
                mn[i][j] = min({mn[i - 1][j - 1], mn[i - 1][j], mn[i - 1][j + 1]}) + a;
            } else {
                mx[i][j] = max({(mx[i - 1][j - 1] + 1) / 2, (mx[i - 1][j] + 1) / 2, (mx[i - 1][j + 1] + 1) / 2});
                mn[i][j] = min({(mn[i - 1][j - 1] + 1) / 2, (mn[i - 1][j] + 1) / 2, (mn[i - 1][j + 1] + 1) / 2});
            }
        }
    }
    
    // cout << mx << nl;
    // cout << mn << nl;
    
    int resmx = 0, resmn = INF;
    Fore(i, 1, m) {
        resmx = max(resmx, mx[n][i]);
        resmn = min(resmn, mn[n][i]);
    }
    
    cout << resmn << nl << resmx;
    ////////////////
    return 0;
}