#if DEBUG
    #include "lib/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "parpalin"
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
#define Ford(i, r, l) for (int i = (r) + 1, _l = (l); --i >= _l; )
#define Forin(it, var) for (auto& it : var)
#define bmask(i) (1ULL << (i))
#define bget(mask, i) ((mask >> (i)) & 1)
const int N = 1e6;
const ll MOD = 1e9 + 7;
const ull BASE = 311;
const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
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
// template <class... T>
// void print(T&&... n) {
//     using exp = int[];
//     exp{0, (cout << n << sp, 0)...};
//     cout << endl;
// }
template <class T>
bool mxmz(T &a, T b) { return a < b ? a = b, 1 : 0; }
template <class T>
bool mnmz(T &a, T b) { return b < a ? a = b, 1 : 0; }
void add(ll &a, ll b) { a = (a + b) % MOD; }
void sub(ll &a, ll b) { a = (a + MOD - b) % MOD; }
void mul(ll &a, ll b) { a = a * (b % MOD) % MOD; }
template <int D, typename T>
struct vec : vector<vec<D - 1, T>> {
    template <typename... Args>
    vec(int n = 1, Args... args) : vector<vec<D - 1, T>>(n, vec<D - 1, T>(args...)) {}
};
template <typename T>
struct vec<1, T> : vector<T> {
    vec(int n = 0, const T& val = T()) : vector<T>(n, val) {}
};

struct Hash {
    int n;
    vector<ll> a, p;
    ll base, mod;
    
    Hash(const str& s, ll _mod = MOD, ll _base = BASE) : n(s.size()), a(n + 1), p(n + 1) {
        base = _base;
        mod = _mod;
        
        p[0] = 1;
        For(i, 1, n) {
            p[i] = p[i - 1] * base % mod;
            a[i] = (a[i - 1] * base + (ll)s[i - 1]) % mod;
        }
    }
    
    ll get(int l, int r) {
        return (a[r] - a[l - 1] * p[r - l + 1] + mod * mod) % mod;
    }
};
////////////////////////////////////////
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////////
    int tc;
    cin >> tc;
    while (tc--) [&]() {
        str s;
        cin >> s;
        int n = s.size();
        
        Hash h(s);
        int i = 1, j = n, pi = 1, pj = n, ans = 0;
        while (i < j) {
            if (h.get(pi, i) == h.get(j, pj)) {
                ans += 2;
                pi = i + 1;
                pj = j - 1;
            }
            i++;
            j--;
        }
        cout << ans + (pi <= pj) << nl;
    }();
    ////////////////////
    return 0;
}