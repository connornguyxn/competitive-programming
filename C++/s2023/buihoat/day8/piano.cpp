#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #pragma GCC optimize("O3,unroll-loops,inline")
    #include <bits/stdc++.h>
    #define TASK "piano"
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
const int N = 1e5 + 5;
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

// piano
// dp, prime

int n;
int a[N], dp[N], spf[N + 1];
////////////////////////////////////////
int solve(int i) {
    if (dp[i] > 0) return dp[i];
    
    dp[i] = 1;
    for (int j = max(0, i - 5); j <= min(n - 1, i + 5); j++) {
        if (a[j] - a[i] > 1 && spf[a[j] - a[i]] == 0) {
            mxmz(dp[i], solve(j) + 1);
        }
    }
    
    return dp[i];
}
////////////////
void trace(int i) {
    cout << i + 1 << sp;
    for (int j = max(0, i - 5); j <= min(n - 1, i + 5); j++) {
        if (a[j] - a[i] > 1 && spf[a[j] - a[i]] == 0 && dp[i] == dp[j] + 1) {
            trace(j);
            return;
        }
    }
}
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(0);
    ////////////////
    for (int i = 2; i * i <= N; i++) {
        if (spf[i] == 0) {
            for (int j = i * i; j <= N; j += i) {
                spf[j] = i;
            }
        }
    }
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int res = 0;
    for (int i = 1; i < n; i++) {
        if (solve(i) > solve(res)) res = i;
    }
    
    cout << dp[res] << nl;
    trace(res);
    ////////////////
    return 0;
}