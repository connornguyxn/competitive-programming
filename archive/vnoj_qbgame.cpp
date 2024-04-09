#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #pragma GCC optimize("O3,unroll-loops,inline")
    #include <bits/stdc++.h>
    #define TASK "qbgame"
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

// vnoj_qbgame
// dp, bitmask

////////////////////////////////////////
int main() {
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        // freopen(TASK".out", "w", stdout);
    };
    cin.tie(0) -> sync_with_stdio(0);
    ////////////////
    int n;
    cin >> n;
    
    vector<array<ll, 8>> a(n + 1);
    
    for (int i = 0; i < 8; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[j][i];
        }
    }
    
    vector<pii> match;
    for (int cur = 0; cur < 256; cur++) {
        for (int pre = 0; pre < 256; pre++) {
            if (cur & pre || cur & (cur >> 1) || pre & (pre >> 1)) continue;
            match.push_back({cur, pre});
        }
    }
    
    vector<vector<ll>> dp(n + 1, vector<ll> (256, -INFLL));
    
    for (int i = 1; i <= n; i++) {
        for (auto [cur, pre] : match) {
            ll sum = max(dp[i - 1][pre], -INFLL * (cur == 0));
            for (int p = 0; p < 8; p++) {
                sum += a[i][p] * b_get(cur, p);
            }
            
            mxmz(dp[i][cur], sum);
        }
    }
    
    cout << *max_element(all(dp[n]));
    ////////////////
    return 0;
}