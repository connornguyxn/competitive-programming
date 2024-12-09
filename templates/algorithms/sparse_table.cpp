#include "../template.cpp"


struct SparseTable {
    int n, k;
    vector2<ll> st;
    ll combine(ll x, ll y) {
        return max(x, y);
    }
    ////////////////////////////////////////
    void init(const vector<ll>& a) {
        n = size(a);
        k = __lg(n);
        
        st.resize(k + 1, vector<ll>(n));
        st[0] = a;
        
        for (int i = 1; i <= k; i++) {
            for (int j = 0; j + bmask(i) - 1 < n; j++) {
                st[i][j] = combine(st[i - 1][j], st[i - 1][j + bmask(i - 1)]);
            }
        }
    }
    ////////////////////////////////////////
    ll get(int l, int r) {
        int i = __lg(r - l + 1);
        return combine(st[i][l], st[i][r - bmask(i) + 1]);
    }
};