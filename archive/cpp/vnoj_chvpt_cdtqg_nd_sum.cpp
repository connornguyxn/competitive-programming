#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #pragma GCC optimize("O3,unroll-loops")
    #include <bits/stdc++.h>
    #define TASK "sum"
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
template <class T>
void mxmz(T &a, T b) { a = max(a, b); }
template <class T>
void mnmz(T &a, T b) { a = min(a, b); }
const int N = 1e6;
const ll MOD = 1e9 + 7;
const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
const int dx[8] = {0, -1, 0, 1, -1, -1, 1, 1};
const int dy[8] = {-1, 0, 1, 0, -1, 1, 1, -1};

// https://oj.vnoi.info/problem/chvpt_nd_chondtqg1_sum
// implementation, prefsum

////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////
    int n, m;
    cin >> n >> m;
    
    vector<vector<ll>>  a(n + 2, vector<ll>(m + 2)),
                        uv(n + 2, vector<ll>(m + 2)),
                        dv(n + 2, vector<ll>(m + 2)),
                        lh(n + 2, vector<ll>(m + 2)),
                        rh(n + 2, vector<ll>(m + 2));
    
    Fore(i, 1, n) {
        Fore(j, 1, m) {
            cin >> a[i][j];
            uv[i][j] = max(uv[i - 1][j], 0LL) + a[i][j];
            lh[i][j] = max(lh[i][j - 1], 0LL) + a[i][j];
        }
    }
    
    Forde(i, n, 1) {
        Forde(j, m, 1) {
            dv[i][j] = max(dv[i + 1][j], 0LL) + a[i][j];
            rh[i][j] = max(rh[i][j + 1], 0LL) + a[i][j];
        }
    }
    
    ll ans = -INFLL;
    Forde(i, n, 1) {
        Forde(j, m, 1) {
            mxmz(ans, max(uv[i][j], dv[i][j]) + max(lh[i][j], + rh[i][j]) - a[i][j]);
        }
    }
    
    cout << ans;
    ////////////////
    return 0;
}