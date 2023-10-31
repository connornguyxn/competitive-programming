#if DEBUG
    #include "lib/debug.h"
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

// https://lqdoj.edu.vn/problem/lqdoj23r4store
// segtree, searching

int n, q;
vector<ll> a;
////////////////////////////////////////
struct mst {
    vector<ll> st;
    vector<bool> mk;
    ////////////////////
    void build(int tl, int tr, int tv = 1) {
        if (tl == tr) {
            st[tv] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(tl, tm, tv * 2);
            build(tm + 1, tr, tv * 2 + 1);
            
            st[tv] = min(st[tv * 2], st[tv * 2 + 1]);
        }
    }
    ////////////////
    void push(int tv) {
        if (!mk[tv]) return;
        st[tv * 2] = st[tv * 2 + 1] = st[tv];
        mk[tv * 2] = mk[tv * 2 + 1] = true;
        mk[tv] = false;
    }
    ////////////////
    void upd(int l, int r, ll v, int tl = 0, int tr = n - 1, int tv = 1) {
        if (tr < l || r < tl) return;
        if (l <= tl && tr <= r) {
            st[tv] = v;
            mk[tv] = true;
        } else {
            push(tv);
            
            int tm = (tl + tr) / 2;
            upd(l, r, v, tl, tm, tv * 2);
            upd(l, r, v, tm + 1, tr, tv * 2 + 1);
            
            st[tv] = min(st[tv * 2], st[tv * 2 + 1]);
        }
    }
    ////////////////////
    ll get(int l, int r, int tl = 0, int tr = n - 1, int tv = 1) {
        if (tr < l || tl > r) return INFLL;
        if (l <= tl && tr <= r) {
            return st[tv];
        } else {
            push(tv);
            
            int tm = (tl + tr) / 2;
            ll lq = get(l, r, tl, tm, tv * 2);
            ll rq = get(l, r, tm + 1, tr, tv * 2 + 1);
            
            return min(lq, rq);
        }
    }
    ////////////////////
    int find(ll v, int tl = 0, int tr = n - 1, int tv = 1) {
        if (tl == tr) {
            if (v < st[tv]) return n;
            return tl;
        } else {
            push(tv);
            
            int tm = (tl + tr) / 2;
            if (get(0, tm) <= v) {
                return find(v, tl, tm, tv * 2);
            } else {
                return find(v, tm + 1, tr, tv * 2 + 1);
            }
        }
    }
    ////////////////////
    mst() {
        st.resize(n * 4);
        mk.resize(n * 4);
        build(0, n - 1);
    }
};
////////////////////////////////////////
struct sst {
    vector<ll> st, bf;
    ////////////////////
    void build(int tl, int tr, int tv = 1) {
        if (tl == tr) {
            st[tv] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(tl, tm, tv * 2);
            build(tm + 1, tr, tv * 2 + 1);
            
            st[tv] = st[tv * 2] + st[tv * 2 + 1];
        }
    }
    ////////////////
    void push(int tv, ll sz) {
        if (!bf[tv]) return;
        st[tv * 2] = bf[tv] * sz / 2;
        st[tv * 2 + 1] = bf[tv] * ((sz + 1) / 2);
        bf[tv * 2] = bf[tv * 2 + 1] = bf[tv];
        bf[tv] = 0;
    }
    ////////////////
    void upd(int l, int r, ll v, int tl = 0, int tr = n - 1, int tv = 1) {
        if (tr < l || r < tl) return;
        if (l <= tl && tr <= r) {
            st[tv] = v * (tr - tl + 1);
            bf[tv] = v;
        } else {
            push(tv, tr - tl + 1);
            
            int tm = (tl + tr) / 2;
            upd(l, r, v, tl, tm, tv * 2);
            upd(l, r, v, tm + 1, tr, tv * 2 + 1);
            
            st[tv] = st[tv * 2] + st[tv * 2 + 1];
        }
    }
    ////////////////////
    ll get(int l, int r, int tl = 0, int tr = n - 1, int tv = 1) {
        if (tr < l || tl > r) return 0;
        if (l <= tl && tr <= r) {
            return st[tv];
        } else {
            push(tv, tr - tl + 1);
            
            int tm = (tl + tr) / 2;
            ll lq = get(l, r, tl, tm, tv * 2);
            ll rq = get(l, r, tm + 1, tr, tv * 2 + 1);
            
            return lq + rq;
        }
    }
    ////////////////////
    int find(ll v, int tl = 0, int tr = n - 1, int tv = 1) {
        if (tl == tr) {
            // print("sts", st[tv], v);
            if (st[tv] <= v) return n;
            return tl;
        } else {
            push(tv, tr - tl + 1);
            
            int tm = (tl + tr) / 2;
            if (st[tv * 2] <= v) {
                return find(v - st[tv * 2], tm + 1, tr, tv * 2 + 1);
            } else {
                return find(v, tl, tm, tv * 2);
            }
        }
    }
    ////////////////////
    sst() {
        st.resize(n * 4);
        bf.resize(n * 4);
        build(0, n - 1);
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
    
    mst stmin;
    sst stsum;
    
    cin >> q;
    Rep(i, q) {
        int t, p;
        ll v;
        cin >> t >> p >> v;
        p--;
        
        if (t == 1) {
            int l = stmin.find(v);
            // print("c", l, p, v);
            if (l > p) continue;
            
            stmin.upd(l, p, v);
            stsum.upd(l, p, v);
            
            // Rep(i, n) cout << stmin.get(0, i) << sp;
            // print();
            // Rep(i, n) cout << stsum.get(0, i) << sp;
            // print();
        } else {
            int ans = 0, l = -1, r = -1;
            // print("at", p, v);
            
            while (r < n - 1) {
                l = max(stmin.find(v), p);
                // print("stmin", stmin.find(v));
                // print('l', l);
                if (l == n) break;
                
                // print("s", v + stsum.get(0, l - 1));
                r = stsum.find(v + stsum.get(0, l - 1));
                // print('r', r, stsum.get(l, r - 1));
                ans += r - l;
                v -= stsum.get(l, r - 1);
                // print('v', v);
            }
            cout << ans << nl;
        }
        // print();
    }
    ////////////////
    return 0;
}