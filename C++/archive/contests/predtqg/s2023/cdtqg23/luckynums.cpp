#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "luckynums"
#endif
using namespace std;
using ll = long long;
using ull = unsigned long long;
using str = string;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define fi first
#define se second
#define nl '\n'
#define sp ' '
#define all(var) (var).begin(), (var).end()
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define Repd(i, n) for (int i = (n); i--; )
#define For(i, l, r) for (int i = (l), _r = (r); i <= _r; i++)
#define Ford(i, r, l) for (int i = (r) + 1, _l = (l); --i >= _l; )
#define Forin(it, var) for (auto it : var)
#define bmask(i) (1ULL << (i))
#define bget(mask, i) ((mask >> (i)) & 1)
#define blog2(n) (63 - __builtin_clzll(n))
template <class... T>
void print(T&&... n) {
    using exp = int[];
    exp{0, (cout << n << sp, 0)...};
    cout << endl;
}
const int N = 1e6;
const ll MOD = 1e9 + 7;
const ull BASE = 311;
const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
const int dx[8] = {0, -1, 0, 1, -1, -1, 1, 1};
const int dy[8] = {-1, 0, 1, 0, -1, 1, 1, -1};
template <class T>
void mxmz(T &a, T b) { a = max(a, b); }
template <class T>
void mnmz(T &a, T b) { a = min(a, b); }
void add(ll &a, ll b) { a = (a + b) % MOD; }
void sub(ll &a, ll b) { a = (a + MOD - b) % MOD; }
void mul(ll &a, ll b) { a = a * b % MOD; }



int n, h;
vector<int> a;
vector<vector<ll>> dp;
/////////////////////////////////
ll solve(int i, int cnt) {
    if (cnt < 0) return 0;
    if (i > n) return !cnt;
    if (dp[i][cnt] >= 0) return dp[i][cnt];
    
    dp[i][cnt] = 0;
    if (a[i] + cnt == h) {
        add(dp[i][cnt], solve(i + 1, cnt));
        add(dp[i][cnt], solve(i + 1, cnt - 1) * cnt);
    }
    if (a[i] + cnt + 1 == h) {
        add(dp[i][cnt], solve(i + 1, cnt + 1));
        add(dp[i][cnt], solve(i + 1, cnt));
        add(dp[i][cnt], solve(i + 1, cnt) * cnt);
    }
    return dp[i][cnt];
}
/////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    /////////////////////////////////
    cin >> n >> h;
    a.resize(n + 1);
    For(i, 1, n) cin >> a[i];
    
    dp.resize(n + 1, vector<ll>(n + 1, -1));
    cout << solve(1, 0);
}
