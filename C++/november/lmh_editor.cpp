#if DEBUG
    #include "lib/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "editor"
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
#define Fors(i, l, r) for (int i = (l), _r = (r); i < _r; i++)
#define Ford(i, r, l) for (int i = (r) + 1, _l = (l); --i >= _l; )
#define Forin(it, var) for (auto& it : var)
#define bmask(i) (1ULL << (i))
#define bget(mask, i) ((mask >> (i)) & 1)
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
bool mxmz(T &a, T b) { return a < b ? a = b, 1 : 0; }
template <class T>
bool mnmz(T &a, T b) { return b < a ? a = b, 1 : 0; }
void add(ll &a, ll b) { a = (a + b) % MOD; }
void sub(ll &a, ll b) { a = (a + MOD - b) % MOD; }
void mul(ll &a, ll b) { a = a * (b % MOD) % MOD; }

// lmh_editor
// dp, hashing, strings

int n;
vector<int> st, lz;
////////////////////////////////////////
void push(int v) {
    mnmz(st[v * 2], lz[v]);
    mnmz(st[v * 2 + 1], lz[v]);
    
    mnmz(lz[v * 2], lz[v]);
    mnmz(lz[v * 2 + 1], lz[v]);
    
    lz[v] = INF;
}
////////////////////
void update(int l, int r, int v, int tl = 1, int tr = n, int tv = 1) {
    if (tr < l || r < tl || l > r) return;
    if (l <= tl && tr <= r) {
        mnmz(st[tv], v);
        mnmz(lz[tv], v);
        return;
    }
    
    push(tv);
    int tm = (tl + tr) / 2;
    update(l, r, v, tl, tm, tv * 2);
    update(l, r, v, tm + 1, tr, tv * 2 + 1);
    st[tv] = min(st[tv * 2], st[tv * 2 + 1]);
}
////////////////////
int query(int p, int tl = 1, int tr = n, int tv = 1) {
    if (tr < p || p < tl) return INF;
    if (p == tl && tr == p) return st[tv];
    
    push(tv);
    int tm = (tl + tr) / 2;
    if (p <= tm) return query(p, tl, tm, tv * 2);
    return query(p, tm + 1, tr, tv * 2 + 1);
}
////////////////////////////////////////
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
        if (l > r) return -1;
        l++, r++;
        return (a[r] - a[l - 1] * p[r - l + 1] + mod * mod) % mod;
    }
};
////////////////////////////////////////
void solve() {
    str a;
    cin >> a;
    n = a.size();
    
    Hash h(sp + a);
    
    auto getmx = [&](int i) {
        int l = 1, r = min(i, n - i) + 1;
        while (l < r) {
            int m = (r + l) / 2;
            if (h.get(1, m) == h.get(i + 1, i + m)) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return l - 1;
    };
    
    st.assign(n * 4 + 4, INF);
    
    lz = st;
    update(1, 1, 1);
    
    For(i, 1, n - 1) {
        int cur = query(i);
        update(i + 1, i + 1, cur + 1);
        update(i + 2, i + getmx(i), cur + 1);
        // print(i, cur, getmx(i));
    }
    // print();
    
    // Fors(i, 1, n - 1) cout << query(i) << sp;
    
    cout << query(n) << nl;
}
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////////
    int q;
    cin >> q;
    
    while (q--) {
        solve();
    }
    ////////////////////
    return 0;
}