#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "miko"
#endif
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define str string
#define nl '\n'
#define sp ' '
#define all(var) (var).begin(), (var).end()
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define Repd(i, n) for (int i = (n); i--; )
#define Fors(i, l, r) for (int i = (l), _r = (r); i < _r; i++)
#define Forsd(i, r, l) for (int i = (r), _l = (l); --i >= _l; )
#define For(i, l, r) for (int i = (l), _r = (r); i <= _r; i++)
#define Ford(i, r, l) for (int i = (r) + 1, _l = (l); --i >= _l; )
#define Forin(it, var) for (auto it : var)
#define bmask(i) (1ULL << (i))
#define bget(mask, i) ((mask >> (i)) & 1)
#define blog(n) (63 - __builtin_clzll(n))
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
const int N = 1e6;
const ll MOD = 1e9 + 7;
const ull BASE = 311;
const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
const int dx[8] = {0, -1, 0, 1, -1, -1, 1, 1};
const int dy[8] = {-1, 0, 1, 0, -1, 1, 1, -1};

// https://oj.vnoi.info/problem/chvpt_marathon_r3_miko
// math

int n;
vector<int> a, st;
/////////////////////
void build(int tl, int tr, int tv = 1) {
    if (tl == tr) {
        st[tv] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(tl, tm, tv * 2);
        build(tm + 1, tr, tv * 2 + 1);
        st[tv] = max(st[tv * 2], st[tv * 2 + 1]);
    }
}
/////////////////////
void update(int p, int val, int tl = 0, int tr = n, int tv = 1) {
    if (tr < p || p < tl) return;
    if (tl == p && tr == p) {
        st[tv] = val;
    } else {
        int tm = (tl + tr) / 2;
        update(p, val, tl, tm, tv * 2);
        update(p, val, tm + 1, tr, tv * 2 + 1);
        st[tv] = max(st[tv * 2], st[tv * 2 + 1]);
    }
}
/////////////////////
int get(int l, int r, int tl = 0, int tr = n, int tv = 1) {
    if (r < tl || tr < l) return -INF;
    if (l <= tl && tr <= r) {
        return st[tv];
    } else {
        int tm = (tl + tr) / 2;
        int ql = get(l, r, tl, tm, tv * 2);
        int qr = get(l, r, tm + 1, tr, tv * 2 + 1);
        return max(ql, qr);
    }
}
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////
    cin >> n;
    a.resize(n + 1);
    For(i, 1, n - 1) cin >> a[i];
    print(a);
    
    st.resize(n * 5);
    build(0, n);
    
    ll ans = 0;
    For(i, 1, n) {
        
    }
    ////////////////
    return 0;
}