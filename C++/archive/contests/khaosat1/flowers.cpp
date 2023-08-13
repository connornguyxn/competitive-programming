#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #pragma GCC optimize("O3,unroll-loops,inline")
    #include <bits/stdc++.h>
    #define TASK "flowers"
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
const int N = 1e5;
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

// flowers
// <tags>

////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(0);
    ////////////////
    int tc, k;
    cin >> tc >> k;
    
    ll dp[N + 1][2];
    for (int i = 0; i < k; i++) {
        dp[i][0] = 1;
        dp[i][1] = 0;
        // db(i, dp[i][0], dp[i][1]);
    }
    
    for (int i = k; i <= N; i++) {
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
        dp[i][1] = (dp[i - k][0] + dp[i - k][1]) % MOD;
        // db(i, dp[i][0], dp[i][1]);
    }
    
    ll sum[N + 1];
    sum[0] = 0;
    for (int i = 1; i <= N; i++) {
        sum[i] = (sum[i - 1] + dp[i][0] + dp[i][1]) % MOD;
    }
    
    while (tc--) {
        int l, r;
        cin >> l >> r;
        cout << (sum[r] + MOD - sum[l - 1]) % MOD << nl;
    }
    ////////////////
    return 0;
}