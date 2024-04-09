#if DEBUG
    #include "lib/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "whome"
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
#define all(a) (a).begin(), (a).end()
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define Repd(i, n) for (int i = (n); i--; )
#define For(i, l, r) for (int i = (l), _r = (r); i <= _r; i++)
#define Ford(i, r, l) for (int i = (r), _l = (l); i >= _l; i--)
#define Forin(it, var) for (auto& it : var)
#define bmask(i) (1ULL << (i))
#define bget(mask, i) ((mask >> (i)) & 1)
const int N = 1e6;
const ll MOD = 1e9 + 7;
const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
// right, down, left, up, lower right, lower left, upper left, upper right
const int dv[] = {0, 1, 0, -1, 1, 1, -1, -1};
const int dh[] = {1, 0, -1, 0, 1, -1, -1, 1};
using namespace chrono;
struct Timer : high_resolution_clock {
    const time_point start_time;
    Timer() : start_time(now()) {}
    rep elapsed() const {
        return duration_cast<milliseconds>(now() - start_time).count();
    }
} timer;
template <class... T>
void print(T&&... n) {
    using exp = int[];
    exp{0, (cout << n << sp, 0)...};
    cout << endl;
}
template <class T>
bool mxmz(T &a, T b) { return a < b ? a = b, 1 : 0; }
template <class T>
bool mnmz(T &a, T b) { return b < a ? a = b, 1 : 0; }
void add(ll &a, ll b) { a = (a + b) % MOD; }
void sub(ll &a, ll b) { a = (a + MOD - b) % MOD; }
void mul(ll &a, ll b) { a = a * (b % MOD) % MOD; }
template <typename T, int D>
struct vec : vector<vec<T, D - 1>> {
    template <typename... Args>
    vec(int n = 0, Args... args) : vector<vec<T, D - 1>>(n, vec<T, D - 1>(args...)) {}
};
template <typename T>
struct vec<T, 1> : vector<T> {
    vec(int n = 0, const T& val = T()) : vector<T>(n, val) {}
};
#define sqr(x) ((x) * (x))

// https://oj.vnoi.info/problem/voi23_whome
// dp, bitwise, bitmask

int n, m;
ll p, c;
vector<ll> a;
vector<int> s;
////////////////////////////////////////
ll profit(int k, int i) {
    return p - sqr(a[i] - a[i - s[k] + 1]) * c;
}
////////////////////////////////////////
struct sub4 {
    void main() {
        vec<ll, 2> dp(n + 1, bmask(m), -INFLL);
        dp[0][0] = 0;
        
        For(i, 1, n) {
            Rep(cur, bmask(m)) {
                mxmz(dp[i][cur], dp[i - 1][cur]);
                Rep(k, m) {
                    if (i < s[k]) continue;
                    mxmz(dp[i][cur | bmask(k)], dp[i - s[k]][cur] + profit(k, i));
                }
            }
        }
        
        cout << dp[n][bmask(m) - 1];
    }
};
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////////
    cin >> n >> m >> p >> c;
    a.resize(n + 1);
    For(i, 1, n) cin >> a[i];
    sort(1 + all(a));
    s.resize(m);
    Forin(it, s) cin >> it;
    
    sub4().main();
    ////////////////////
    return 0;
}