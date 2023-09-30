#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #pragma GCC optimize("O3,unroll-loops,inline")
    #include <bits/stdc++.h>
    #define TASK "pts"
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

// pts
// <tags>

unordered_map<int, ll> dp = {
    {1, 1},
};
////////////////////////////////////////
ll bpow(ll n, ll k) {
    n %= MOD;
    ll res = 1;
    
    while (k > 0) {
        if (k % 2) res = (res * n) % MOD;
        n = (n * n) % MOD;
        k /= 2;
    }
    
    return res;
}
////////////////
ll solve(int n) {
    if (dp.count(n)) return dp[n];
    
    int sqt = sqrt(n);
    dp[n] = bpow(2, n - 1) - 1;
    for (int i = 2; i < sqt; i++) {
        if (n % i == 0) {
            dp[n] = (dp[n] + MOD - solve(i)) % MOD;
            dp[n] = (dp[n] + MOD - solve(n / i)) % MOD;
        } 
    }
    if (sqt * sqt == n) {
        dp[n] = (dp[n] + MOD - solve(sqt)) % MOD;
    };
    
    return dp[n];
}
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(0);
    ////////////////
    int n;
    cin >> n;
    
    cout << solve(n);
    ////////////////
    return 0;
}