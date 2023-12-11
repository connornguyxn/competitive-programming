#if DEBUG
    #include "lib/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "build"
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
#define sqr(n) ((n) * (n))
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
template <int D, typename T>
struct vec : vector<vec<D - 1, T>> {
    template <typename... Args>
    vec(int n = 0, Args... args) : vector<vec<D - 1, T>>(n, vec<D - 1, T>(args...)) {}
};
template <typename T>
struct vec<1, T> : vector<T> {
    vec(int n = 0, const T& val = T()) : vector<T>(n, val) {}
};

// https://oj.vnoi.info/contest/chvpt_khaosat_lan3_2324/ranking/
// dp, convex hull trick

int n;
vector<ll> h, w;
////////////////////////////////////////
struct sub1 {
    sub1() {
        vector<ll> dp(n + 1);
        For(i, 2, n) {
            dp[i] = INFLL;
            For(j, 1, i - 1) {
                mnmz(dp[i], dp[j] + sqr(h[i] - h[j]) + w[i - 1] - w[j]);
                // dp[j] + h[i] * h[i] - 2 h[i] * h[j] + h[j] * h[j] + w[i - 1] - w[j]
                // h[i] * h[i] + w[i - 1] + min(-2 * h[j] * h[i] + h[j] * h[j] - w[j] + dp[j])
            }
        }
        cout << dp[n];
    }
};
struct sub3 {
    struct Line {
        mutable ll k, m, p;
        bool operator < (const Line& o) const {
            return k < o.k;
        }
        bool operator < (ll x) const {
            return p < x;
        }
    };
    struct ConvexHull : multiset<Line, less<>> {
        ll div(ll a, ll b) {
            return a / b - ((a ^ b) < 0 && a % b);
        }
        
        bool isect(iterator a, iterator b) {
            if (b == end()) {
                a->p = INFLL;
                return false;
            }
            
            if (a->k == b->k) {
                a->p = (a->m > b->m ? INFLL : -INFLL);
            } else {
                a->p = div(b->m - a->m, a->k - b->k);
            }
            return a->p >= b->p;
        }
        
        void insert(ll k, ll m) {
            iterator z = multiset::insert({k, m, 0}), y = z++, x = y;
            
            while (isect(y, z)) {
                z = erase(z);
            }
            
            if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
            while ((y = x) != begin() && (--x)->p >= y->p) {
                isect(x, erase(y));
            }
        }
        
        ll get(ll x) {
            Line l = *lower_bound(x);
            return l.k * x + l.m;
        }
    } cvh;
    
    sub3() {
        vector<ll> dp(n + 1);
        cvh.insert(2 * h[1], -(h[1] * h[1] - w[1]));
        
        For(i, 2, n) {
            dp[i] = h[i] * h[i] + w[i - 1] - cvh.get(h[i]);
            cvh.insert(2 * h[i], -(h[i] * h[i] - w[i] + dp[i]));
        }
        cout << dp[n];
    }
};
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////////
    cin >> n;
    
    h.resize(n + 1);
    w = h;
    For(i, 1, n) cin >> h[i];
    For(i, 1, n) {
        cin >> w[i];
        w[i] += w[i - 1];
    }
    
    sub3();
    ////////////////////
    return 0;
}