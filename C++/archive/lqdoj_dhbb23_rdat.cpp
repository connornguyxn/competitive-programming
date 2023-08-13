#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #pragma GCC optimize("O3,unroll-loops")
    #pragma GCC target("sse4.2")
    #include <bits/stdc++.h>
    #define TASK "rdat"
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
#define all(VAR) (VAR).begin(), (VAR).end()
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; ++i)
#define Repd(i, n) for (int i = (n); i--; )
#define For(i, l, r) for (int i = (l), _b = (r); i < _b; ++i)
#define Ford(i, r, l) for (int i = (r), _a = (l); --i >= _a; )
#define Fore(i, l, r) for (int i = (l), _b = (r); i <= _b; ++i)
#define ForDe(i, r, l) for (int i = (r), _a = (l); i >= _a; --i)
#define Forin(it, var) for (auto it : var)
template<typename tVar, typename tVal>
void mnmz(tVar &var, tVal val) { if (val < var) var = val; }
template<typename tVar, typename tVal>
void mxmz(tVar &var, tVal val) { if (val > var) var = val; }
#define bmask(POS) (1ULL << (POS))
#define bget(MASK, POS) ((MASK >> (POS)) & 1)
#define blog2(NUM) (__builtin_clzll(1) - __builtin_clzll(NUM))
const int N = 1e5;
const ll MOD = 1e9 + 7;
const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
const int dx[8] = {0, -1, 0, 1, -1, -1, 1, 1};
const int dy[8] = {-1, 0, 1, 0, -1, 1, 1, -1};

// https://lqdoj.edu.vn/contest/dhbb23
// segtree

int n, q;
int a[N];
pii st[N * 4];

pii cmb(pii a, pii b) {
    if (a < b) swap(a, b);
    a.se = max({a.se, b.fi, b.se});
    return a;
}

void build(int tl = 0, int tr = n - 1, int v = 1) {
    if (tl == tr) {
        st[v] = {a[tl], -INF};
    } else {
        int tm = (tl + tr) / 2;
        build(tl, tm, v * 2);
        build(tm + 1, tr, v * 2 + 1);
        st[v] = cmb(st[v * 2], st[v * 2 + 1]);
    }
}

pii get(int l, int r, int tl = 0, int tr = n - 1, int v = 1) {
    if (r < tl || l > tr) return {-INF, -INF};
    if (l <= tl && tr <= r) {
        return st[v];
    } else {
        int tm = (tl + tr) / 2;
        pii lq = get(l, r, tl, tm, v * 2);
        pii rq = get(l, r, tm + 1, tr, v * 2 + 1);
        return cmb(lq, rq);
    }
}
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(0);
    ////////////////
    cin >> n >> q;
    
    Rep(i, n) cin >> a[i];
    build();
    
    while (q--) {
        int l, r;
        cin >> l >> r;
        pii res = get(l - 1, r - 1);
        cout << res.fi + res.se << nl;
    }
    ////////////////
    return 0;
}