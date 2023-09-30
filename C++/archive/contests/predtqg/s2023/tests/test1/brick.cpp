#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #pragma GCC optimize("O3,unroll-loops,inline")
    #include <bits/stdc++.h>
    #define TASK "brick"
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
#define MASK(POS) (1ULL << (POS))
#define GETBIT(MASK, POS) ((MASK >> (POS)) & 1)
#define all(VAR) (VAR).begin(), (VAR).end()
const int N = 1e6;
const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
// directions = left, up, right, down, upper_l, upper_r, lower_r, lower_l
const int dx[8] = {0, -1, 0, 1, -1, -1, 1, 1};
const int dy[8] = {-1, 0, 1, 0, -1, 1, 1, -1};
template<typename tVar, typename tVal>
void mnmz(tVar &var, tVal val) { if (val < var) var = val; }
template<typename tVar, typename tVal>
void mxmz(tVar &var, tVal val) { if (val > var) var = val; }

// brick
// <tags>

int n, m;
ull MOD;
ll dp[N + 1][33];
////////////////////////////////////////
bool ok(int pre, int cur) {
    for (int i = 0; i < m - 1; i++) {
        int cnt = GETBIT(pre, i) + GETBIT(pre, i + 1) + GETBIT(cur, i) + GETBIT(cur, i + 1);
        if (cnt % 4 == 0) {
            return false;
        };
    }
    return true;
}
////////////////////////////////////////
int main() {
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    };
    cin.tie(0) -> sync_with_stdio(0);
    ////////////////
    cin >> n >> m >> MOD;
    
    for (int cur = 0; cur < MASK(m); cur++) dp[0][cur] = 1;
    
    for (int i = 1; i < n; i++) {
        for (int cur = 0; cur < MASK(m); cur++) {
            for (int pre = 0; pre < MASK(m); pre++) {
                if (!ok(pre, cur)) continue;
                dp[i][cur] = (dp[i][cur] + dp[i - 1][pre]) % MOD;
            }
        }
    }
    
    ll res = 0;
    for (int cur = 0; cur < MASK(m); cur++) {
        res = (res + dp[n - 1][cur]) % MOD;
    }
    
    cout << res;
    ////////////////
    return 0;
}