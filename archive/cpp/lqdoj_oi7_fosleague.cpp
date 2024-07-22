#if DEBUG
    #include "lib/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "fosleague"
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
// using namespace chrono;
// struct Timer : high_resolution_clock {
//     const time_point start_time;
//     Timer() : start_time(now()) {}
//     rep elapsed() const {
//         return duration_cast<milliseconds>(now() - start_time).count();
//     }
// } timer;
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
template <typename T, int D>
struct vec : vector<vec<T, D - 1>> {
    template <typename... Args>
    vec(int n = 0, Args... args) : vector<vec<T, D - 1>>(n, vec<T, D - 1>(args...)) {}
};
template <typename T>
struct vec<T, 1> : vector<T> {
    vec(int n = 0, const T& val = T()) : vector<T>(n, val) {}
};

// lhttps://lqdoj.edu.vn/problem/lqdojcontest7bai1
// binsearch

int n, k;
vector<pii> a;
////////////////////////////////////////
////////////////////////////////////////
struct sub1 {
    void main() {
        int mn1 = INT32_MAX, mn2 = INT32_MAX, mx1 = 0, mx2 = 0;
        Rep(i, n) {
            mnmz(mn1, a[i].fi);
            mnmz(mn2, a[i].se);
            mxmz(mx1, a[i].fi);
            mxmz(mx2, a[i].se);
        }
        cout << max(mx1 - mn1, mx2 - mn2);
    }
};
////////////////////////////////////////
struct sub2 {
    int ans = INT32_MAX;
    
    void gen(int idx, int cnt, pii mn, pii mx) {
        if (idx == n) {
            if (cnt) return;
            mnmz(ans, max(mx.fi - mn.fi, mx.se - mn.se));
            return;
        }
        gen(idx + 1, cnt, mn, mx);
        if (cnt == 0) return;
        mnmz(mn.fi, a[idx].fi);
        mnmz(mn.se, a[idx].se);
        mxmz(mx.fi, a[idx].fi);
        mxmz(mx.se, a[idx].se);
        gen(idx + 1, cnt - 1, mn, mx);
    }
    
    void main() {
        gen(0, k, {INT32_MAX, INT32_MAX}, {0, 0});
        cout << ans;
    }
};
////////////////////////////////////////
struct sub3 {
    void main() {
        vector<int> b;
        Forin(it, a) {
            b.push_back(it.se);
        }
        sort(all(b));
        int ans = INT32_MAX;
        Rep(i, n - k + 1) {
            mnmz(ans, b[i + k - 1] - b[i]);
        }
        cout << ans;
    }
};
////////////////////////////////////////
struct sub6 {
    int ver, hor;
    vec<int, 2> b;
    
    int count(pii l, pii r) {
        mxmz(l.fi, 1);
        mxmz(l.se, 1);
        return b[r.fi][r.se] - b[l.fi - 1][r.se] - b[r.fi][l.se - 1] + b[l.fi - 1][l.se - 1];
    }
    
    void main() {
        ver = hor = 0;
        Forin(it, a) {
            mxmz(ver, ++it.fi);
            mxmz(hor, ++it.se);
        }
        b = move(vec<int, 2>(ver + 1, hor + 1));
        
        
        Forin(it, a) {
            b[it.fi][it.se]++;
        }
        For(i, 1, ver) {
            For(j, 1, hor) {
                b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
            }
        }
        
        
        auto check = [&](int m) {
            For(i, 1, ver) {
                For(j, 1, hor) {
                    if (count({i - m + 1, j - m + 1}, {i, j}) >= k) {
                        return true;
                    }
                }
            }
            return false;
        };
        
        
        int l = 0, r = bmask(20);
        while (l < r) {
            int m = (l + r) / 2;
            if (check(m)) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        cout << r - 1;
    }
};
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////////
    int T;
    cin >> T;
    
    cin >> n >> k;
    a.resize(n);
    Forin(it, a) {
        int x;
        cin >> x;
        it = {x >> 10, x & 1023};
    }
    
    if (T == 1) return sub1().main(), 0;
    if (T == 2) return sub2().main(), 0;
    if (T == 3) return sub3().main(), 0;
    sub6().main();
    ////////////////////
    return 0;
}