#include "../template.cpp"

// internally 1-indexed, but add 1 to every index to use 0-based indexing

struct FenwickTree {
    int n;
    vector<ll> f;
    ////////////////////////////////////////
    void init(int _n) {
        n = _n + 1;
        f.assign(n + 1, 0);
    }
    ////////////////////////////////////////
    void update(int i, ll val) {
        i++;
        while (i <= n) {
            f[i] += val;
            i += i & -i;
        }
    }
    ////////////////////////////////////////
    ll get(int i) {
        i++;
        ll res = 0;
        while (i > 0) {
            res += f[i];
            i -= i & -i;
        }
        return res;
    }
    ////////////////////////////////////////
    ll get(int l, int r) {
        return get(r) - get(l - 1);
    }
};



template <int M = 100000>
struct FenwickTree_static {
    array<ll, M + 1> f = {};
    ////////////////////////////////////////
    void update(int i, ll val) {
        i++;
        while (i <= n) {
            f[i] += val;
            i += i & -i;
        }
    }
    ////////////////////////////////////////
    ll get(int i) {
        i++;
        ll res = 0;
        while (i > 0) {
            res += f[i];
            i -= i & -i;
        }
        return res;
    }
    ////////////////////////////////////////
    ll get(int l, int r) {
        return get(r) - get(l - 1);
    }
};