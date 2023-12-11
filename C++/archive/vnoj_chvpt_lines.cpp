#if DEBUG
    #include "lib/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "lines"
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

// https://oj.vnoi.info/problem/chvpt_line
// dp


int n;
vector<pii> st;
////////////////////////////////////////
void st_update(int p, pii v, int tl = 0, int tr = n, int tv = 1) {
    if (p < tl || tr < p) return;
    if (tl == tr) {
        st[tv] = v;
        return;
    }
    int tm = (tl + tr) / 2;
    if (p <= tm) st_update(p, v, tl, tm, tv * 2);
    else st_update(p, v, tm + 1, tr, tv * 2 + 1);
    st[tv] = max(st[tv * 2], st[tv * 2 + 1]);
}
////////////////////
pii st_get(int l, int r, int tl = 0, int tr = n, int tv = 1) {
    if (r < tl || tr < l) return {0, 0};
    if (l <= tl && tr <= r) return st[tv];
    int tm = (tl + tr) / 2;
    return max(st_get(l, r, tl, tm, tv * 2), st_get(l, r, tm + 1, tr, tv * 2 + 1));
}
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////////
    cin >> n;
    
    vector<int> a(n + 1), p(n + 1);
    For(i, 1, n) cin >> a[i];
    For(i, 1, n) {
        int x;
        cin >> x;
        p[x] = i;
    }
    
    st.resize(n * 4 + 4, {-INF, -INF});
    st_update(0, {0, 0});
    
    vector<int> trace(n + 1);
    For(i, 1, n) {
        pii pre = st_get(0, p[a[i]] - 1);
        trace[i] = pre.se;
        st_update(p[a[i]], {pre.fi + 1, i});
    }
    
    pii ans = st_get(1, n);
    cout << ans.fi << nl;
    while (ans.se) {
        cout << a[ans.se] << sp;
        ans.se = trace[ans.se];
    }
    ////////////////////
    return 0;
}