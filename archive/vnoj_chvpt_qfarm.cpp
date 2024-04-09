#if DEBUG
    #include "lib/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "qfarm"
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

// https://oj.vnoi.info/contest/chvpt_chieu_6_12_2023
// implementation, 2d, segtree


using pil = pair<int, ll>;
////////////////////////////////////////

struct Segtree {
    int n;
    vector<int> st;
    Segtree(int _n) : n(_n), st(n * 4) {}
    
    void update(int p, int v, int tl = 0, int tr = -1, int tv = 1) {
        if (tr < 0) tr = n - 1;
        if (p < tl || tr < p) return;
        if (tl == tr) {
            st[tv] += v;
        } else {
            int tm = (tl + tr) / 2;
            update(p, v, tl, tm, tv * 2);
            update(p, v, tm + 1, tr, tv * 2 + 1);
            st[tv] = st[tv * 2] + st[tv * 2 + 1];
        }
    }
    
    int get(int l, int r, int tl = 0, int tr = -1, int tv = 1) {
        if (tr < 0) tr = n - 1;
        if (r < tl || tr < l) return 0;
        if (l <= tl && tr <= r) return st[tv];
        int tm = (tl + tr) / 2;
        return get(l, r, tl, tm, tv * 2) + get(l, r, tm + 1, tr, tv * 2 + 1);
    }
};
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////////
    int n;
    ll w, h;
    cin >> n >> w >> h;
    if (n % 2) {
        cout << -1;
        return 0;
    }
    
    vector<pll> a(n);
    vector<int> zip;
    Forin(it, a) {
        cin >> it.fi >> it.se;
        zip.push_back(it.se);
    }
    
    sort(all(zip));
    zip.erase(unique(all(zip)), zip.end());
    sort(all(a));
    
    vector<ll> rval{a[0].fi};
    vector<vector<pil>> rows(1);
    Forin(it, a) {
        if (it.fi > rval.back()) {
            rval.push_back(it.fi);
            rows.push_back({});
        }
        rows.back().emplace_back(lower_bound(all(zip), it.se) - zip.begin(), it.se);
    }
    int mxc = zip.size();
    
    ll ans = -1;
    auto solve = [&]() {
        print();
        print(rval);
        print(rows);
        
        Segtree st(mxc);
        
        Rep(r, rows.size()) {
            Forin(it, rows[r]) st.update(it.fi, 1);
            
            Forin(it, rows[r]) {
                if (st.get(0, it.fi) == n / 2) {
                    print("valid left at", r, it, w * h - rval[r] * it.se);
                    print(mxmz(ans, w * h - rval[r] * it.se), ans);
                    // mxmz(ans, w * h - rval[r] * it.se);
                }
                if (st.get(it.fi, mxc - 1) == n / 2) {
                    print("valid right at", r, it, w *  h - rval[r] * (h - it.se + 1));
                    print(mxmz(ans, w * h - rval[r] * (h - it.se + 1)), ans);
                    // mxmz(ans, w * h - rval[r] * (h - it.se + 1));
                }
            }
        }
    };
    
    solve();
    reverse(all(rows));
    reverse(all(rval));
    Forin(it, rval) it = w - it + 1;
    solve();
    
    cout << ans;
    ////////////////////
    return 0;
}