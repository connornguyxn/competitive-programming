#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "store"
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
#define Forin(it, var) for (auto it : var)
#define bmask(i) (1ULL << (i))
#define bget(mask, i) ((mask >> (i)) & 1)
#define blog2(n) (63 - __builtin_clzll(n))
const int N = 1e6;
const ll MOD = 1e9 + 7;
const ull BASE = 311;
const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
const int dx[8] = {0, -1, 0, 1, -1, -1, 1, 1};
const int dy[8] = {-1, 0, 1, 0, -1, 1, 1, -1};
template <class... T>
void print(T&&... n) {
    using exp = int[];
    exp{0, (cout << n << sp, 0)...};
    cout << endl;
}
template <class T>
void mxmz(T &a, T b) { a = max(a, b); }
template <class T>
void mnmz(T &a, T b) { a = min(a, b); }
void add(ll &a, ll b) { a = (a + b) % MOD; }
void sub(ll &a, ll b) { a = (a + MOD - b) % MOD; }
void mul(ll &a, ll b) { a = a * (b % MOD) % MOD; }

// lqdoj_c23_store
// <tags>

struct query {
    int t, p;
    ll v;
};
int n, q;
vector<ll> a;
vector<query> qs;
////////////////////////////////////////
struct sub1 {
    sub1() {
        Forin(cur, qs) {
            if (cur.t == 1) {
                For(i, 0, cur.p) mxmz(a[i], cur.v);
            } else {
                int res = 0;
                For(i, cur.p, n - 1) {
                    if (a[i] <= cur.v) {
                        res++;
                        cur.v -= a[i];
                    }
                }
                cout << res << nl;
            }
        } 
    }
};
////////////////////////////////////////
struct full {
    vector<ll> st, buf;
    void st_build(int tl, int tr, int tv = 1) {
        if (tl == tr) {
            st[tv] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            st_build(tl, tm, tv * 2);
            st_build(tm + 1, tr, tv * 2 + 1);
            
            st[tv] = min(st[tv * 2], st[tv * 2 + 1]);
        }
    }
    ////////////////
    void st_push(int cur) {
        mxmz(st[cur * 2], buf[cur]);
        mxmz(st[cur * 2 + 1], buf[cur]);
        
        mxmz(buf[cur * 2], buf[cur]);
        mxmz(buf[cur * 2 + 1], buf[cur]);
        
        buf[cur] = 0;
    }
    ////////////////
    void st_update(int l, int r, ll v, int tl, int tr, int tv = 1) {
        if (tr < l || tl > r) return;
        if (l <= tl && tr <= r) {
            mxmz(st[tv], v);
            mxmz(buf[tv], v);
        } else {
            st_push(tv);
            
            int tm = (tl + tr) / 2;
            st_update(l, r, v, tl, tm, tv * 2);
            st_update(l, r, v, tm + 1, tr, tv * 2 + 1);
            st[tv] = min(st[tv * 2], st[tv * 2 + 1]);
        }
    }
    ////////////////
    ll st_get(int l, int r, int tl, int tr, int tv = 1) {
        if (tr < l || tl > r) return INF;
        if (l <= tl && tr <= r) {
            return st[tv];
        } else {
            st_push(tv);
            
            int tm = (tl + tr) / 2;
            ll lq = st_get(l, r, tl, tm, tv * 2);
            ll rq = st_get(l, r, tm + 1, tr, tv * 2 + 1);
            return min(lq, rq);
        }
    }
    ////////////////
    full() {
        st.resize(n * 4);
        buf.resize(n * 4);
        st_build(0, n - 1);
        
        Forin(cur, qs) {
            if (cur.t == 1) {
                st_update(0, cur.p, cur.v, 0, n - 1);
            } else {
                int res = 0;
                int nxt = [&]() {
                    int l = cur.p, r = n;
                    while (l < r) {
                        int m = (l + r) / 2;
                        if (st_get(0, m, 0, n - 1) <= cur.v) {
                            r = m;
                        } else {
                            l = m + 1;
                        }
                    }
                    return l - 1;
                }();
                if (nxt == n) return;
            }
        } 
    }
};
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////
    cin >> n;
    a.resize(n);
    Rep(i, n) cin >> a[i];
    
    cin >> q;
    qs.resize(q);
    Rep(i, q) {
        cin >> qs[i].t >> qs[i].p >> qs[i].v;
        qs[i].p--;
    }
    
    sub1();
    // full();
    ////////////////
    return 0;
}