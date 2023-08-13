#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #pragma GCC optimize("O3,unroll-loops,inline")
    #include <bits/stdc++.h>
    #define TASK "digitsum"
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

// https://open.kattis.com/contests/osdm7u/problems/digitsum
// dp, digit_dp

ll dp[16][2][9 * 14 + 1];
ll solve(int idx, bool low, int sum, const str &s) {
    if (idx == s.size()) return sum;
    if (dp[idx][low][sum] > -1) return dp[idx][low][sum];
    
    dp[idx][low][sum] = 0;
    
    int mx = low ? 9 : s[idx] - '0';
    for (int i = 0; i <= mx; i++) {
        dp[idx][low][sum] += solve(idx + 1, low || i < mx, sum + i, s);
    }
    
    return dp[idx][low][sum];
}
////////////////////////////////////////
int main() {
    // freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(0);
    ////////////////
    int tc;
    cin >> tc;
    while (tc--) {
        str l, r;
        cin >> l >> r;
        
        memset(dp, -1, sizeof(dp));
        ll cntl = solve(0, 0, 0, l);
        
        memset(dp, -1, sizeof(dp));
        ll cntr = solve(0, 0, 0, r);
        
        ll res = cntr - cntl;
        for (char num : l) {
            res += num - '0';
        }
        
        cout << res << nl;
    }
    ////////////////
    return 0;
}