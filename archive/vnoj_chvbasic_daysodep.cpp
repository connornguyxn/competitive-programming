#if DEBUG
    #include "lib/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "daysodep"
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
template <class... T>
void print(T&&... n) {
    using exp = int[];
    exp{0, (cout << n << sp, 0)...};
    cout << endl;
}
using namespace chrono;
struct Timer : high_resolution_clock {
    const time_point start_time;
    Timer() : start_time(now()) {}
    rep elapsed() const {
        return duration_cast<milliseconds>(now() - start_time).count();
    }
} timer;

// https://oj.vnoi.info/problem/chvbasic_dttinh43
// datastruct

////////////////////////////////////////
struct Segtree {
    int n;
    vector<vector<ll>> st;
    Segtree(const vector<ll> &a) : n(a.size()), st(n * 4) {
        build(a, 0, n - 1, 1);
    }
    ////////////////////
    void build(const vector<ll> &a, int tl, int tr, int tv) {
        if (tl == tr) {
            st[tv] = {a[tl]};
            return;
        }
        int tm = (tl + tr) / 2;
        build(a, tl, tm, tv * 2);
        build(a, tm + 1, tr, tv * 2 + 1);
        merge(all(st[tv * 2]), all(st[tv * 2 + 1]), back_inserter(st[tv]));
    }
    ////////////////////
    ll get(int l, int r, ll vl, ll vr, int tl, int tr, int tv) {
        if (r < tl || tr < l) return 0;
        if (l <= tl && tr <= r) {
            return upper_bound(all(st[tv]), vr) - lower_bound(all(st[tv]), vl);
        }
        int tm = (tl + tr) / 2;
        return get(l, r, vl, vr, tl, tm, tv * 2) + get(l, r, vl, vr, tm + 1, tr, tv * 2 + 1);
    }
    ll get(int l, int r, ll vl, ll vr) {
        return get(l, r, vl, vr, 0, n - 1, 1);
    }
};
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////////
    int n;
    ll k;
    cin >> n >> k;
    
    vector<ll> a(n + 1), s(n + 1);
    For(i, 1, n) {
        cin >> a[i];
        s[i] = s[i - 1] + (a[i] % 2 ? -a[i] : a[i]);
        a[i] %= 2;
    }
    
    Segtree st(s);
    int lastodd = 0, lastevn = 0;
    ll ans = 0;
    
    For(i, 1, n) {
        if (a[i]) {
            lastodd = i;
        } else {
            lastevn = i;
        }
        ans += st.get(0, min(lastodd, lastevn) - 1, s[i] - k, s[i]);
    }
    
    cout << ans;
    ////////////////////
    return 0;
}