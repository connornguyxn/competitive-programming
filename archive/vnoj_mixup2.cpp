#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #pragma GCC optimize("O3,unroll-loops,inline")
    #include <bits/stdc++.h>
    #define TASK "mixup2"
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

// mixup2
// <tags>

////////////////////////////////////////
int main() {
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        // freopen(TASK".out", "w", stdout);
    };
    cin.tie(0) -> sync_with_stdio(0);
    ////////////////
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int m = b_mask(n);
    
    vector<pii> match;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j || abs(a[i] - a[j]) <= k) continue;
            match.push_back({i, j});
        }
    }
    
    vector<vector<ll>> dp(m, vector<ll>(n));
    for (int i = 0; i < n; i++) {
        dp[b_mask(i)][i] = 1;
    }
    
    for (int cur = 1; cur < m; cur++) {
        for (auto [i, j] : match) {
            if (!b_get(cur, i) || b_get(cur, j)) continue;
            
            int nxt = cur | b_mask(j);
            
            dp[nxt][j] += dp[cur][i];
        }
    }
    
    cout << accumulate(all(dp[m - 1]), 0LL);
    ////////////////
    return 0;
}