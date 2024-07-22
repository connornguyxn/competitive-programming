#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #pragma GCC optimize("O3,unroll-loops")
    #pragma GCC target("sse4.2")
    #include <bits/stdc++.h>
    #define TASK "work"
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
#define For(i, p, r) for (int i = (p), _r = (r); i < _r; i++)
#define Ford(i, r, p) for (int i = (r), _l = (p); --i >= _l; )
#define Fore(i, p, r) for (int i = (p), _r = (r); i <= _r; i++)
#define Forde(i, r, p) for (int i = (r) + 1, _l = (p); --i >= _l; )
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
template <class T>
void mxmz(T &a, T b) { a = max(a, b); }
template <class T>
void mnmz(T &a, T b) { a = max(a, b); }
const int N = 1e6;
const ll MOD = 1e9 + 7;
const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
const int dx[8] = {0, -1, 0, 1, -1, -1, 1, 1};
const int dy[8] = {-1, 0, 1, 0, -1, 1, 1, -1};

// prac_nvh_work
// https://imgur.com/a/Ah12RPx

////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////
    int k, n, m;
    cin >> k >> n >> m;

    vector<int> a(n), b(n), x(m), z(m);
    vector<ll> y(m);
    Rep(i, n) {
        cin >> a[i] >> b[i];
    }
    Rep(i, m) {
        cin >> x[i] >> y[i] >> z[i];
    }
    
    vector<vector<ll>> dp(k + 1, vector<ll>(k * 10 + 1, -INF));
    dp[0][0] = 0;
    Fore(i, 1, k) {
        Fore(j, 0, i * 10) {
            Rep(p, n) {
                if (i >= a[p] && j >= b[p]) {
                    mxmz(dp[i][j], dp[i - a[p]][j - b[p]]);
                }
            }
            Rep(p, m) {
                if (i >= x[p] && j + z[p] <= i * 10) {
                    mxmz(dp[i][j], dp[i - x[p]][j + z[p]] + y[p]);
                }
            }
        }
    }

    ll ans = 0;
    Fore(i, 1, k) {
        Fore(j, 0, i * 10) {
            mxmz(ans, dp[i][j]);
        }
    }
    cout << ans;
    ////////////////
    return 0;
}
