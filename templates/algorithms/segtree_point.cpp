struct Segtree {
    int n;
    vector<ll> st;
    Segtree(int _n) : n(_n), st(n * 4, INFLL) {}
    ////////////////////////////////////////
    void update(int p, ll v, int tl, int tr, int tv) {
        if (tl == tr) {
            st[tv] = v;
            return;
        }
        int tm = (tl + tr) / 2;
        if (p <= tm) update(p, v, tl, tm, lnode);
        else update(p, v, tm + 1, tr, rnode);
        st[tv] = min(st[lnode], st[rnode]);
    }
    void update(int p, ll v) {
        update(p, v, 0, n - 1, 1);
    }
    ////////////////////////////////////////
    ll get(int l, int r, int tl, int tr, int tv) {
        if (tr < l || r < tl) return INFLL;
        if (l <= tl && tr <= r) return st[tv];
        int tm = (tl + tr) / 2;
        return min(get(l, r, tl, tm, lnode), get(l, r, tm + 1, tr, rnode));
    }
    ll get(int l, int r) {
        return get(l, r, 0, n - 1, 1);
    }
};