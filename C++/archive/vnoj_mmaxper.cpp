#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #pragma GCC optimize("O3,unroll-loops,inline")
    #include <bits/stdc++.h>
    #define TASK "mmaxper"
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

// https://oj.vnoi.info/problem/mmaxper
// dp

////////////////////////////////////////
int main() {
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    };
    cin.tie(0) -> sync_with_stdio(0);
    ////////////////
    int n;
    cin >> n;
    
    vector<pll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].fi >> a[i].se;
    }
    
    vector<vector<ll>> dp(n, vector<ll>(2));
    dp[0][0] = a[0].fi;
    dp[0][1] = a[0].se;
    
    for (int i = 1; i < n; i++) {
        dp[i][0] = max(dp[i - 1][0] + abs(a[i].se - a[i - 1].se) + a[i].fi, dp[i - 1][1] + abs(a[i].se - a[i - 1].fi) + a[i].fi);
        dp[i][1] = max(dp[i - 1][0] + abs(a[i].fi - a[i - 1].se) + a[i].se, dp[i - 1][1] + abs(a[i].fi - a[i - 1].fi) + a[i].se);
    }
    
    cout << max(dp[n - 1][0], dp[n - 1][1]);
    ////////////////
    return 0;
}