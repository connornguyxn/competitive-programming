#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #pragma GCC optimize("O3,unroll-loops")
    #pragma GCC target("sse4.2")
    #include <bits/stdc++.h>
    #define TASK "classroom"
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
#define all(var) (var).begin(), (var).end()
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define Repd(i, n) for (int i = (n); i--; )
#define For(i, l, r) for (int i = (l), _r = (r); i < _r; i++)
#define Ford(i, r, l) for (int i = (r), _l = (l); --i >= _l; )
#define Fore(i, l, r) for (int i = (l), _r = (r); i <= _r; i++)
#define Forde(i, r, l) for (int i = (r) + 1, _l = (l); --i >= _l; )
#define Forin(it, var) for (auto it : var)
#define Bmask(i) (1ULL << (i))
#define Bget(mask, i) ((mask >> (i)) & 1)
#define Blog(n) (63 - __builtin_clzll(n))
template <class T = int>
T inp() { T x; cin >> x; return x; }
template <typename... T>
void print(T&&... n) {
    using exp = int[];
    exp{0, (cout << n << sp, 0)...};
    cout << nl;
}
const int N = 1e3 + 1;
const ll MOD = 1e9 + 7;
const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
const int dx[8] = {0, -1, 0, 1, -1, -1, 1, 1};
const int dy[8] = {-1, 0, 1, 0, -1, 1, 1, -1};

// classroom
// <tags>

ll fct[N], inv[N];
////////////////////////////////////////
ll bmul(ll n, ll k) {
    n %= MOD;
    ll res = 0;
    while (k > 0) {
        if (k % 2) res = (res + n) % MOD;
        n = n * 2 % MOD;
        k /= 2;
    }
    return res;
}

ll bpow(ll n, ll k) {
    n %= MOD;
    ll res = 1;
    while (k > 0) {
        if (k % 2) res = bmul(res, n);
        n = bmul(n, n);
        k /= 2;
    }
    return res % MOD;
}

ll C(ll n, ll r) {
    return (fct[n] * bpow(fct[r], MOD - 2) % MOD * bpow(fct[n - r], MOD - 2)) % MOD;
}
ll ans[N][N];
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////
    fct[0] = 1;
    For(i, 1, N) fct[i] = fct[i - 1] * (ll)i % MOD;
    
    For(n, 1, N) {
        Fore(r, 1, n) {
            ans[n][r] = (ans[n][r - 1] + C(n, r)) % MOD;
        }
    }
    
    int tc = inp();
    while (tc--) {
        ll r, n;
        cin >> r >> n;
        cout << ans[n][r] + 1 << nl;
    }
    ////////////////
    return 0;
}
