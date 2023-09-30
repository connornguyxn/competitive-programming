#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #pragma GCC optimize("O3,unroll-loops,inline")
    #include <bits/stdc++.h>
    #define TASK "classynumber"
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

// classynumber
// dp, digit_dp

ll dp[20][2][4];
ll solve(int idx, bool low, int cnt, const str &s) {
    if (cnt > 3) return 0;
    if (idx == s.size()) return 1;
    if (dp[idx][low][cnt] > -1) return dp[idx][low][cnt];
    
    dp[idx][low][cnt] = 0;
    
    int cur = low ? 9 : s[idx] - '0';
    for (int i = 0; i <= cur; i++) {
        dp[idx][low][cnt] += solve(idx + 1, low || i < cur, cnt + (i > 0), s);
    }
    
    return dp[idx][low][cnt];
}
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
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
        
        cout << cntr - cntl + [](str &s) {
            int cnt = 0;
            for (char num : s) {
                cnt += num > '0';
            }
            return cnt <= 3;
        }(l) << nl;
    }

        
    ////////////////
    return 0;
}