#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #pragma GCC optimize("O3,unroll-loops,inline")
    #include <bits/stdc++.h>
    #define TASK "tienxu"
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

// tienxu
// <tags>

int n, m;
int a[205], dp[205][10005];
////////////////////////////////////////
int solve(int i, int sum) {
    if (sum == 0) dp[i][sum] = 0;
    if (dp[i][sum] > -1) return dp[i][sum];
    
    dp[i][sum] = INF;
    for (int j = i + 1; j <= n; j++) {
        if (sum < a[j]) continue;
        mnmz(dp[i][sum], solve(j, sum - a[j]) + 1);
    }
    
    return dp[i][sum];
}
////////////////
void trace(int i, int sum) {
    if (sum == 0) return;
    
    for (int j = i + 1; j <= n; j++) {
        if (sum < a[j]) continue;
        if (dp[i][sum] == solve(j, sum - a[j]) + 1) {
            cout << a[j] << sp;
            trace(j, sum - a[j]);
            break;
        };
    }
}
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(0);
    ////////////////
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    memset(dp, -1, sizeof(dp));
    
    cout << solve(0, m) << nl;
    trace(0, m);
    ////////////////
    return 0;
}