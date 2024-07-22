#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #pragma GCC optimize("O3,unroll-loops")
    #pragma GCC target("sse4.2")
    #include <bits/stdc++.h>
    #define TASK "c11sum"
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
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define Repd(i, n) for (int i = (n); i--; )
#define For(i, l, r) for (int i = (l), _r = (r); i < _r; i++)
#define Ford(i, r, l) for (int i = (r), _l = (l); --i >= _l; )
#define Fore(i, l, r) for (int i = (l), _r = (r); i <= _r; i++)
#define Forde(i, r, l) for (int i = (r), _l = (l); i >= _l; i++)
#define Forin(it, var) for (auto it : var)
#define bmask(i) (1ULL << (i))
#define bget(mask, i) ((mask >> (i)) & 1)
#define blog2(n) (__builtin_clzll(1) - __builtin_clzll(n))
const int N = 1e6;
const ll MOD = 1e9 + 7;
const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
const int dx[8] = {0, -1, 0, 1, -1, -1, 1, 1};
const int dy[8] = {-1, 0, 1, 0, -1, 1, 1, -1};

// https://oj.vnoi.info/problem/c11sum
// math

////////////////////////////////////////
int main() {
    // freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(0);
    ////////////////
    str s;
    cin >> s;
    s = '0' + s;
    
    ll ans = 0, sum = 0;
    For(i, 1, s.size()) {
        sum = (sum * 10 + 1LL * i * (s[i] - '0')) % MOD;
        ans = (ans + sum) % MOD;
    }
    
    cout << ans;
    ////////////////
    return 0;
}