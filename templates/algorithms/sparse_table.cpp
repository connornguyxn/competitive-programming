#include "../template.cpp"


template <class T>
struct Cmpmin {
    static T operator()(T a, T b) {
        return min(a, b);
    }
};
template <class T, class Cmb = Cmpmin<T>>
struct SparseTable {
    int n, k;
    vector<vector<T>> st;
    Cmb cmb;
    ////////////////////////////////////////
    void init(const vector<T>& a) {
        n = a.size();
        k = __lg(n);
        
        st.resize(k + 1, vector<T>(n));
        st[0] = a;
        
        for (int i = 1; i <= k; i++) {
            for (int j = 0; j + bmask(i) - 1 < n; j++) {
                st[i][j] = cmb(st[i - 1][j], st[i - 1][j + bmask(i - 1)]);
            }
        }
    }
    ////////////////////////////////////////
    T get(int l, int r) {
        int i = __lg(r - l + 1);
        return cmb(st[i][l], st[i][r - bmask(i) + 1]);
    }
};