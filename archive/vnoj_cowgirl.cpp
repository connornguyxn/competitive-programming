#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #pragma GCC optimize("O3,unroll-loops,inline")
    #include <bits/stdc++.h>
    #define TASK "cowgirl"
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

// cowgirl
// <tags>

bool check(int msk1, int msk2, int m) {
    for (int i = 0; i < m - 1; i++) {
        int cnt = b_get(msk1, i) + b_get(msk1, i + 1) + b_get(msk2, i) + b_get(msk2, i + 1);
        if (cnt % 4 == 0) return false;
    }
    return true;
}
////////////////////////////////////////
int main() {
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        // freopen(TASK".out", "w", stdout);
    };
    cin.tie(0) -> sync_with_stdio(0);
    ////////////////
    vector<vector<pii>> match(6);
    
    for (int l = 1; l < 6; l++) {
        for (int cur = 0; cur < b_mask(l); cur++) {
            for (int pre = 0; pre < b_mask(l); pre++) {
                if (check(cur, pre, l)) {
                    match[l].push_back({cur, pre});
                }
            }
        }
    }
    
    int tc;
    cin >> tc;
    while (tc--) {
        int m, n;
        cin >> m >> n;
        if (m > n) swap(m, n);
        
        vector<vector<ll>> dp(n, vector<ll>(b_mask(m)));
        fill(all(dp[0]), 1);
        
        for (int i = 1; i < n; i++) {
            for (auto [cur, pre] : match[m]) {
                dp[i][cur] += dp[i - 1][pre];
            }
        }
        
        cout << accumulate(all(dp[n - 1]), 0) << nl;
    }
    ////////////////
    return 0;
}