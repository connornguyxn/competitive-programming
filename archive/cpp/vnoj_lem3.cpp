#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #pragma GCC optimize("O3,unroll-loops,inline")
    #include <bits/stdc++.h>
    #define TASK "lem3"
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

// vnoj_lem3
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
    
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    
    int m = b_mask(n);
    vector<vector<int>> dp(m, vector<int>(n, INF));
    for (int i = 0; i < n; i++) {
        dp[b_mask(i)][i] = 0;
    }
    
    for (int cur = 1; cur < m; cur++) {
        for (int i = 0; i < n; i++) {
            if (!b_get(cur, i)) continue;
            
            for (int j = 0; j < n; j++) {
                if (b_get(cur, j)) continue;
                
                int nxt = cur | b_mask(j);
                mnmz(dp[nxt][j], dp[cur][i] + a[i][j]);
            }
        }
    }
    
    cout << *min_element(all(dp[m - 1]));
    ////////////////
    return 0;
}