#if localdb
    #include "include/debug.h"
    #define TASK "test"
#else
    #pragma GCC optimize("O3,unroll-loops,inline")
    #include <bits/stdc++.h>
    #define db(...)
    #define TASK "itmed"
#endif
using namespace std;
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int, int>
#define fi first
#define se second
#define str string
#define nl '\n'
#define sp ' '
#define mask(BI) (1LL << (BI))
#define bitcnt(BM) __builtin_popcountll(BM)
#define getbit(BM, BI) ((BM >> BI) & 1)
#define all(A) (A).begin(), (A).end()
#define point(N) fixed << showpoint << setprecision(N)
const int MAXN = 1e6;
const ull MOD = 1e9 + 7;

// https://oj.vnoi.info/problem/segtree_itmed
// dp, segtree

template<typename data>
struct segtree {
    int n;
    vector<ll> t;
    // "empty" value
    // eg: INFINITY for min queries, 0 for sum queries
    data defval = -INFINITY;
    data proc(data &a, data &b) {
        return max(a, b);
    };
    /////////////////
    segtree (vector<data> a) {
        n = a.size();
        t.resize(n * 4);
        for (int i = 0; i < n; i++) {
            update(i, a[i]);
        };
    };
    data get(int l, int r, int tl = 0, int tr = 0, int v = 1) {
        if (v == 1) {
            tr = n - 1;
        };
        if (l > r) {
            return defval;
        };
        if ((l <= tl) && (r >= tr)) {
            return t[v];
        };
        int tm = (tl + tr) / 2;
        data lq = get(l, min(r, tm), tl, tm, v * 2);
        data rq = get(max(l, tm + 1), r, tm + 1, tr, v * 2 + 1);
        return proc(lq, rq);
    };
    void update(int p, data val, int tl = 0, int tr = 0, int v = 1) {
        if (v == 1) {
            tr = n - 1;
        };
        if (tl == tr) {
            t[v] = val;
        } else {
            int tm = (tl + tr) / 2;
            if (p <= tm) {
                update(p, val, tl, tm, v * 2);
            } else {
                update(p, val, tm + 1, tr, v * 2 + 1);
            };
            t[v] = proc(t[v * 2], t[v * 2 + 1]);
        }
    };
};
///////////////////////////////////////
int main() {
    if (fopen(TASK".inp", "r")) freopen(TASK".inp", "r", stdin);
    if (fopen(TASK".out", "r")) freopen(TASK".out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(0);
    /////////////////
    ll n, k;
    cin >> n >> k;
    
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    };
    
    segtree<ll> dp({vector<ll>(n)});
    
    for (ll i = 0; i < n; i++) {
        dp.update(i, max(0LL, dp.get(max(0LL, i - k), max(0LL, i - 1)) + a[i]));
    };
    
    cout << dp.get(0, n - 1);
    /////////////////
    return 0;
};
/*
000000000000000000000000000000000000000000011111111100000000000000000000000000000000000000
0000000000000000000000000000000000001111.............1111111000000000000000000000000000000
00000000000000000000000000000000011.. .....11111111.........111000000000000000000000000000
000000000000000000000000000000011.  .1111111111111111111111.. .110000000000000000000000000
0000000000000000000000000000001. ..111111111111111111111111111. .1100000000000000000000000
000000000000000000000000000001. .111111111111111111111111111111. .110000000000000000000000
00000000000000000000000000001. .111111.............11111111111111. .1000000000000000000000
00000000000000000000000000001  111.   ..............   ...11111111. .100000000000000000000
0000000000000000000000000001. .11.  ..11111111111111111..  .1111111. .10000000000000000000
0000000000000000000000000001  111. ..11111111111111111111.  .1111111. .1000000000000000000
000000000000000000000000001. .111.  ..1111111111111111111.. .11111111. .100000000000000000
000000000000000000000000001. 11111.   ...11111111111111...  .11111111. .100000000000000000
000000000000000000000000011 .1111111..   ..............   .11111111111. 110000000000000000
00000000000000000000000001. .1111111111.................11111111111111. .10000000000000000
00000000000000000000000001 .1111111111111111111111111111111111111111111  10000000000000000
0000000000000000000000001. .1111111111111111111111111111111111111111111. .1000000000000000
0000000000000000000000001. 11111111111111111111111111111111111111111111. .1000000000000000
000000000000000000000001. .11111111111111111111111111111111111111111111. .1000000000000000
000000000000000000000001. .111111111111111111111111111111111111111111111 .1000000000000000
000000000000000000000011 .1111111111111111111111111111111111111111111111 .1000000000000000
00000000000000000000001. .1111111111111111111111111111111111111111111111. 1000000000000000
00000000000000000000001. 11111111111111111111111111111111111111111111111. 1000000000000000
0000000000000000000001. .11111111111111111111111111111111111111111111111. 1100000000000000
0000000000000000000001. .11111111111111111111111111111111111111111111111. 1100000000000000
0000000000000000000011 .111111111111111111111111111111111111111111111111. 1100000000000000
000000000000000000001. .111111111111111111111111111111111111111111111111. 1100000000000000
000000000000000000001 .1111111111111111111111111111111111111111111111111  1000000000000000
00000000000000000001. .1111111111111111111111111111111111111111111111111 .1000000000000000
00000000000000000001. 11111111111111111111.........11111111111111111111. .1000000000000000
0000000000000000001. .111111111111................... .1111111111111111. .1000000000000000
0000000000000000001. .111111111....111111111111111111. .111111111111111. .1000000000000000
0000000000000000011 .111111111. .100000000000000000001  111111111111111. .1000000000000000
000000111111111111. .111111111. .100000000000000000001  111111111111111. .1000000000000000
00111...............11111111111 .100000000000000000001 .111111111111111. .1000000000000000
001. ..111111111111111111111111. 110000000000000000001  111111111111111. .1000000000000000
001. 11111111111111111111111111. .10000000000000000001  111111111111111. .1000000000000000
001. .1111111111111111111111111. .10000000000000000001 .111111111111111. .1000000000000000
00011. ..11111111111111111111..  .1000000000111111111. .111111111111111 .10000000000000000
0000011.. ................. ...11100000111........... ..11111111111111. .10000000000000000
0000000111111...........111111000000011. ...11111111111111111111111111  110000000000000000
00000000000000000000000000000000000001. .111111111111111111111111111.  .100000000000000000
000000000000000000000000000000000000011. .11111111111111111111111.. ..11000000000000000000
00000000000000000000000000000000000000111.. ......111111111.... ...11000000000000000000000
00000000000000000000000000000000000000000111111...............1111000000000000000000000000
000000000000000000000000000000000000000000000000011111111111100000000000000000000000000000
*/