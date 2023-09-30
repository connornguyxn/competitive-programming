#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #pragma GCC optimize("O3,unroll-loops,inline")
    #include <bits/stdc++.h>
    #define TASK "pleasant"
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
const int N = 105;
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

// pleasant
// dp, digit_dp

ll dp[N][2][10];
////////////////////////////////////////
ll solve(int i, bool dif, int pre, const str &s) {
    if (i == s.size()) return 1 * !!pre;
    if (dp[i][dif][pre] > 0) return dp[i][dif][pre];
    
    int cur = s[i] - '0';
    for (int num = pre; num <= max(cur, 9 * dif); num++) {
        dp[i][dif][pre] = (dp[i][dif][pre] + solve(i + 1, dif || (num != cur), num, s)) % MOD;
    }
    
    return dp[i][dif][pre];
}
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(0);
    ////////////////
    str l, r;
    cin >> l;
    cin >> r;
    
    ll cntl = solve(0, false, 0, l);
    memset(dp, 0, sizeof(dp));
    ll cntr = solve(0, false, 0, r);
    
    cout << (cntr + MOD - cntl + is_sorted(all(l))) % MOD;
    ////////////////
    return 0;
}