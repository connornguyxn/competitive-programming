#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #pragma GCC optimize("O3,unroll-loops,inline")
    #pragma GCC target("sse4.2")
    #include <bits/stdc++.h>
    #define TASK "hoicho"
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
#define all(VAR) (VAR).begin(), (VAR).end()
template<typename tVar, typename tVal>
void mnmz(tVar &var, tVal val) { if (val < var) var = val; }
template<typename tVar, typename tVal>
void mxmz(tVar &var, tVal val) { if (val > var) var = val; }
#define b_mask(POS) (1ULL << (POS))
#define b_get(MASK, POS) ((MASK >> (POS)) & 1)
#define b_log2(NUM) (__builtin_clzll(1) - __builtin_clzll(NUM))
const int N = 1e6;
const ll MOD = 1e9 + 7;
const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
const int dx[8] = {0, -1, 0, 1, -1, -1, 1, 1};
const int dy[8] = {-1, 0, 1, 0, -1, 1, 1, -1};

// hoicho
// <tags>

////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(0);
    ////////////////
    int n, m;
    cin >> n >> m;
    
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(all(a));
    
    vector<ll> w(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> w[i];
    }
    for (int i = m - 1; i > 0; i--) {
        w[i] = min(w[i], w[i + 1]);
    }
    
    vector<ll> dp(n + 1, INF);
    dp[0] = 0;
    for (int r = 1; r <= n; r++) {
        for (int l = 1; l <= r; l++) {
            mnmz(dp[r], dp[l - 1] + w[a[r] - a[l] + 1]);
        }
    }
    
    cout << dp[n];
    ////////////////
    return 0;
}