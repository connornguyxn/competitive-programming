#if DEBUG
    #include "lib/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "sseq"
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

// https://oj.vnoi.info/problem/voi22_sseq
// implementation, segtree

struct Seg {
    int l, r;
    ll w;
    bool operator < (Seg o) const {
        return l < o.l;
    }
};
int n;
vector<Seg> a;
////////////////////////////////////////
struct Segtree {
    int n;
    vector<ll> st, lz;
    Segtree(int _n) : n(_n), st(n * 4, 0), lz(n * 4, 0) {}
    
    void push(int tv) {
        int l = tv * 2, r = l + 1;
        st[l] += lz[tv];
        st[r] += lz[tv];
        
        lz[l] += lz[tv];
        lz[r] += lz[tv];
        
        lz[tv] = 0;
    }
    
    void upd(int l, int r, ll v, int tl, int tr, int tv) {
        if (tr < l || r < tl) return;
        if (l <= tl && tr <= r) {
            st[tv] += v;
            lz[tv] += v;
            return;
        }
        push(tv);
        
        int tm = (tl + tr) / 2;
        upd(l, r, v, tl, tm, tv * 2);
        upd(l, r, v, tm + 1, tr, tv * 2 + 1);
        st[tv] = max(st[tv * 2], st[tv * 2 + 1]);
    }
    void upd(int l, int r, ll v) {
        upd(l, r, v, 0, n - 1, 1);
    }
    
    
    ll get(int l, int r, int tl, int tr, int tv) {
        if (tr < l || r < tl) return INT64_MIN;
        if (l <= tl && tr <= r) {
            return st[tv];
        }
        push(tv);
        
        int tm = (tl + tr) / 2;
        return max(get(l, r, tl, tm, tv * 2), get(l, r, tm + 1, tr, tv * 2 + 1));
    }
    ll get(int l, int r) {
        return get(l, r, 0, n - 1, 1);
    }
};
////////////////////////////////////////
struct sub4 {
    void main() {
        Segtree st(N + 1);
        Forin(it, a) st.upd(it.r, N, it.w);
        
        ll ans = 0;
        int l = 0;
        Forin(it, a) {
            while (a[l].l < it.l) {
                st.upd(a[l].r, N, -a[l].w);
                l++;
            }
            mxmz(ans, st.get(1, N));
        }
        
        cout << ans;
    }
};
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////////
    cin >> n;
    a.resize(n);
    Forin(it, a) cin >> it.l >> it.r >> it.w;
    sort(all(a));
    
    sub4().main();
    ////////////////////
    return 0;
}