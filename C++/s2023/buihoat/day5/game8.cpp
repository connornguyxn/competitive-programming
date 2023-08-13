#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #pragma GCC optimize("O3,unroll-loops,inline")
    #include <bits/stdc++.h>
    #define TASK "game8"
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
const ull MOD = 1e9 + 7;
const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
// directions = left, up, right, down, upper_l, upper_r, lower_r, lower_l
const int dx[8] = {0, -1, 0, 1, -1, -1, 1, 1};
const int dy[8] = {-1, 0, 1, 0, -1, 1, 1, -1};
template<typename tVar, typename tVal>
void mnmz(tVar &var, tVal val) { if (val < var) var = val; }
template<typename tVar, typename tVal>
void mxmz(tVar &var, tVal val) { if (val > var) var = val; }

// game8
// dp, bitwise

////////////////////////////////////////
int main() {
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    };
    cin.tie(0) -> sync_with_stdio(0);
    ////////////////
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        int m = b_mask(n);
        
        vector<vector<ll>> a(n + 1, vector<ll>(n));
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }
        
        vector<vector<ll>> dp(n + 1, vector<ll>(m, -INFLL));
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int cur = 1; cur < m; cur++) {
                if (__builtin_popcount(cur) != i) continue;
                for (int j = 0; j < n; j++) {
                    if (!b_get(cur, j)) continue;
                    int pre = cur & ~b_mask(j);
                    mxmz(dp[i][cur], dp[i - 1][pre] - a[i][j]);
                }
            }
        }
        
        ll res = -INFLL;
        for (int cur = 1; cur < m; cur++) {
            if (__builtin_popcount(cur) != n) continue;
            mxmz(res, dp[n][cur]);
        }
        
        cout << -res << nl;
    }
    ////////////////
    return 0;
}