#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #pragma GCC optimize("O3,unroll-loops,inline")
    #include <bits/stdc++.h>
    #define TASK "hana2"
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
const ull MOD = 1e7;
const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
// directions = left, up, right, down, upper_l, upper_r, lower_r, lower_l
const int dx[8] = {0, -1, 0, 1, -1, -1, 1, 1};
const int dy[8] = {-1, 0, 1, 0, -1, 1, 1, -1};
template<typename tVar, typename tVal>
void mnmz(tVar &var, tVal val) { if (val < var) var = val; }
template<typename tVar, typename tVal>
void mxmz(tVar &var, tVal val) { if (val > var) var = val; }

// https://ntucoder.net/Problem/Details/3314
// dp, bitwise

////////////////////////////////////////
int main() {
    // freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(0);
    ////////////////
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    
    vector<vector<array<ll, 8>>> dp(n + 1, vector<array<ll, 8>>(m + 1));
    dp[1][1][0] = 1;
    a[n][m] = 8;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i + j == 2 || a[i][j] == -1) continue;
            
            for (int pre = 0; pre < 8; pre++) {
                int cur = pre | (b_mask(a[i][j] - 1) * (i + j < n + m));
                
                dp[i][j][cur] = (dp[i][j][cur] + dp[i][j - 1][pre] + dp[i - 1][j][pre]) % MOD;
            }
        }
    }
    
    ll res = 0;
    for (int i = 0; i < 8; i++) {
        if (__popcount(i) > 1) {
            (res += dp[n][m][i]) %= MOD;
        };
    }
    
    cout << res;
    ////////////////
    return 0;
}