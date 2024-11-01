struct Segtree {
    int n;
    vector<int> st;
    Segtree(int _n) : n(_n), st(n * 4, INFLL) {}
    ////////////////////////////////////////
    void update(int p, int v, int tl, int tr, int tv) {
        if (tl == tr) {
            st[tv] = v;
            return;
        }
        int tm = (tl + tr) / 2;
        if (p <= tm) update(p, v, tl, tm, tvl);
        else update(p, v, tm + 1, tr, tvr);
        st[tv] = min(st[tvl], st[tvr]);
    }
    void update(int p, int v) {
        update(p, v, 0, n - 1, 1);
    }
    ////////////////////////////////////////
    int get(int l, int r, int tl, int tr, int tv) {
        if (tr < l || r < tl) return INFLL;
        if (l <= tl && tr <= r) return st[tv];
        int tm = (tl + tr) / 2;
        return min(get(l, r, tl, tm, tvl), get(l, r, tm + 1, tr, tvr));
    }
    int get(int l, int r) {
        return get(l, r, 0, n - 1, 1);
    }
};