#include "../template.cpp"


struct Segtree {
    int n;
    vector<ll> st;
    ////////////////////////////////////////
    const ll D = -INFLL;
    ll combine(const ll& ln, const ll& rn) {
        return max(ln, rn);
    }
    ////////////////////////////////////////
    void init(const int& _n) {
        n = _n;
        st.assign(n * 4, D);
    }
    void update(const int& p, const ll& v) {
        update(p, v, 0, n - 1, 1);
    }
    ll get(const int& l, const int& r) {
        return get(l, r, 0, n - 1, 1);
    }
    ////////////////////////////////////////
    private:
    void update(const int& p, const ll& v, const int& tl, const int& tr, const int& tv) {
        if (tl == tr) {
            maximize(st[tv], v);
            return;
        }
        const int tm = (tl + tr) / 2;
        if (p <= tm) update(p, v, tl, tm, tvl);
        else update(p, v, tm + 1, tr, tvr);
        st[tv] = combine(st[tvl], st[tvr]);
    }
    ////////////////////////////////////////
    ll get(const int& l, const int& r, const int& tl, const int& tr, const int& tv) {
        if (tr < l || r < tl) return D;
        if (l <= tl && tr <= r) return st[tv];
        const int tm = (tl + tr) / 2;
        return combine(get(l, r, tl, tm, tvl), get(l, r, tm + 1, tr, tvr));
    }
};