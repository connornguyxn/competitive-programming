#if DEBUG
    #include "lib/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "sdseq"
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
template <int D, typename T>
struct vec : vector<vec<D - 1, T>> {
    template <typename... Args>
    vec(int n = 0, Args... args) : vector<vec<D - 1, T>>(n, vec<D - 1, T>(args...)) {}
};
template <typename T>
struct vec<1, T> : vector<T> {
    vec(int n = 0, const T& val = T()) : vector<T>(n, val) {}
};

// https://oj.vnoi.info/contest/chvpt_6tinh2324/
// dp, segtree, implementation

struct Query {
    int t, l, r;
};
int n, s, q;
vector<Query> qs;
int pw[10], a[10];
vector<vector<vector<pll>>> dp(10, vector<vector<pll>>(2, vector<pll>(10, {-1, -1})));
////////////////////////////////////////
pll solve(int idx, bool low, bool inc, int mod) {
    if (idx == 10) return {0, inc || mod == 0};
    
    pll& mem = dp[idx][inc][mod];
    if (low && mem.fi != -1) return mem;
    
    pll res = {0, 0};
    For(i, 0, (low ? 9 : a[idx])) {
        pll cur = solve(idx + 1, low || i < a[idx], inc || i == s, (mod * 10 + i) % s);
        res.se += cur.se;
        res.fi += cur.fi + pw[9 - idx] * i * cur.se;
    }
    
    if (low) mem = res;
    return res;
}
////////////////////
ll get_sum(int x) {
    int i = 9;
    while (x > 0) {
        a[i] = x % 10;
        x /= 10;
        i--;
    }
    while (i >= 0) a[i--] = 0;
    
    return solve(0, 0, 0, 0).fi;
}
////////////////////
int valid(int x) {
    if (x % s == 0) return 1;
    while (x > 0) {
        if (x % 10 == s) return 1;
        x /= 10;
    }
    return 0;
}
////////////////////////////////////////
vector<ll> st;
////////////////////
void update(int p, ll v, int tl = 0, int tr = n - 1, int tv = 1) {
    if (p < tl || tr < p) return;
    if (tl == tr) {
        st[tv] = v;
        return;
    }
    int tm = (tl + tr) / 2;
    if (p <= tm) update(p, v, tl, tm, tv * 2);
    else update(p, v, tm + 1, tr, tv * 2 + 1);
    st[tv] = st[tv * 2] + st[tv * 2 + 1];
}
////////////////////
ll get(int l, int r, int tl = 0, int tr = n - 1, int tv = 1) {
    if (r < tl || tr < l) return 0;
    if (l <= tl && tr <= r) return st[tv];
    int tm = (tl + tr) / 2;
    return get(l, r, tl, tm, tv * 2) + get(l, r, tm + 1, tr, tv * 2 + 1);
}
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////////
    cin >> n >> s >> q;
    qs.resize(q);
    Forin(it, qs) cin >> it.t >> it.l >> it.r;
    
    vector<int> zip;
    Forin(it, qs) {
        zip.push_back(it.l);
        if (it.t == 2) zip.push_back(it.r);
    }
    sort(all(zip));
    unordered_map<int, int> pos;
    int pre = -INF, num = -1;
    Forin(it, zip) {
        if (it != pre) num++;
        pos[it] = num;
    }
    n = zip.size();
    
    st.resize(n * 4);
    
    pw[0] = 1;
    For(i, 1, 9) pw[i] = pw[i - 1] * 10;
    
    Forin(it, qs) {
        if (it.t == 1) {
            update(pos[it.l], 1LL * (it.r - it.l) * (valid(it.l) + 1));
        } else {
            ll ans = 1LL * (it.l + it.r) * (it.r - it.l + 1) / 2;
            ans += get_sum(it.r) - get_sum(it.l) + it.l * valid(it.l);
            ans += get(pos[it.l], pos[it.r]);
            
            cout << ans << nl;
        }
    }
    ////////////////////
    return 0;
}