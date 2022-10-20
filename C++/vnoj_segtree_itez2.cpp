#ifdef local_debug
#include <debugging.h>

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

// https://oj.vnoi.info/problem/segtree_itez2
// segtree

/////////////////////////////////////
template <typename data> class segtree {
public:
    int n;
    vector<data> t;
    // "empty" value
    // eg: INFINITY for min queries, 0 for sum queries
    data defval = 0;
    data process(data &a, data &b) {
        return a + b;
    };
    /////////////////
    segtree (vector<data> &a) {
        n = a.size();
        t.resize(n * 4);
        build(a, 0, n - 1, 1);
    };
    data query(int l, int r, int tl = 0, int tr = 0, int v = 1) {
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
        data lq = query(l, min(r, tm), tl, tm, v * 2);
        data rq = query(max(l, tm + 1), r, tm + 1, tr, v * 2 + 1);
        return process(lq, rq);
    };
    void update(int p, int val, int tl = 0, int tr = 0, int v = 1) {
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
            t[v] = process(t[v * 2], t[v * 2 + 1]);
        }
    };
private:
    void build(vector<data> &a, int tl, int tr, int v) {
        if (tr == tl) {
            t[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(a, tl, tm, v * 2);
            build(a, tm + 1, tr, v * 2 + 1);
            t[v] = process(t[v * 2], t[v * 2 + 1]);
        };
    };
};
///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init_ifs();
    int n;
    cin >> n;
    vector<ll> a(n);
    segtree<ll> t(a);
    /////////////////
    int tc = 1;
    cin >> tc;
    while (tc--) {
        int c, l, r;
        cin >> c >> l >> r;
        if (c == 1) {
            t.update(l - 1, r);
        } else {
            cout << t.query(l - 1, r - 1) << nl;
        };
    };
    return 0;
};