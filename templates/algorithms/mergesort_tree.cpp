#include "../template.cpp"

int n;
vector<int> val;

struct Segtree {
    vector2<ll> st;
    ////////////////////////////////////////
    void build(int tl = 1, int tr = n, int tv = 1) {
        if (tl == tr) {
            st[tv] = {val[tl]};
            return;
        }
        int tm = (tl + tr) / 2;
        build(tl, tm, tvl);
        build(tm + 1, tr, tvr);
        merge(all(st[tvl]), all(st[tvr]), back_inserter(st[tv]));
    }
    ////////////////////////////////////////
    int get(int l, int r, ll hi, int tl = 1, int tr = n, int tv = 1) {
        if (r < tl || tr < l) return 0;
        if (l <= tl && tr <= r) {
            return upper_bound(all(st[tv]), hi) - st[tv].begin();
        }
        int tm = (tl + tr) / 2;
        return get(l, r, hi, tl, tm, tvl) + get(l, r, hi, tm + 1, tr, tvr);
    }
} st;