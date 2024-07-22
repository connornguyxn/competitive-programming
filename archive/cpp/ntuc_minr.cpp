#ifdef local_debug
#include "include/debugging.h"

#define init_ofs() ofstream cout("output.out")
#else
#include <bits/stdc++.h>
#define init_ifs()
#define init_ofs()
#define vdb(...)
#define db(...)
#endif
using namespace std;
#define ll long long
#define ull unsigned long long
#define ld long double
#define str string
#define nl '\n'
#define sp ' '
#define all(a) a.begin(), a.end()
#define dec_point(n) fixed << showpoint << setprecision(n)
#define mp_optimize(mp) mp.reserve(4096); mp.max_load_factor(0.1);
#define for_in(a) for (auto& it : a)
const int LIM = 1e6;
const ull MOD = 1e9 + 7;

// http://ntucoder.net/Problem/Details/1172
// rmq, segtree

///////////////////////////////////////
array<int, LIM> a;
// height of segment tree: ceil(log(n))
// max size of segment tree: 2n - 1
array<int, LIM * 2> t;
///////////////////////////////////////
// processing function
// return result value of 2 nodes
int process(int a, int b) {
    return min(a, b);
};
/////////////////////////////////////
void build(int tl, int tr, int v = 0) {
    if (tr == tl) {
        t[v] = a[tl];
    } else {
        int m = (tl + tr) / 2;
        build(tl, m, v * 2 + 1);
        build(m + 1, tr, v * 2 + 2);
        t[v] = min(t[v * 2 + 1], t[v * 2 + 2]);
    };
};
///////////////////////////////////////
int query(int l, int r, int tl , int tr, int v = 0) {
    if (l > r) {
        // "empty" value
        // eg: INFINITY for min queries, 0 for sum queries
        return INFINITY;
    };
    if ((l <= tl) && (r >= tr)) {
        return t[v];
    };
    int tm = (tl + tr) / 2;
    int lq = query(l, min(r, tm), tl, tm, v * 2 + 1);
    int rq = query(max(l, tm + 1), r, tm + 1, tr, v * 2 + 2);
    return process(lq, rq);
};
///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init_ifs();
    int n, tc;
    cin >> n >> tc;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    };
    build(0, n - 1);
    /////////////////
    int l, r;
    while (tc--) {
        cin >> l >> r;
        cout << query(l - 1, r - 1, 0, n - 1);
        /////////////////
        cout << nl;
    };
    return 0;
};