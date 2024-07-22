#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #pragma GCC optimize("O3,unroll-loops,inline")
    #pragma GCC target("sse4.2")
    #include <bits/stdc++.h>
    #define TASK "359d"
#endif
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define str string
#define nl '\n'
#define sp ' '
#define all(VAR) (VAR).begin(), (VAR).end()
template<typename tVar, typename tVal>
void mnmz(tVar &var, tVal val) { if (val < var) var = val; }
template<typename tVar, typename tVal>
void mxmz(tVar &var, tVal val) { if (val > var) var = val; }
#define b_mask(POS) (1ULL << (POS))
#define b_get(MASK, POS) ((MASK >> (POS)) & 1)
#define b_log2(NUM) (__builtin_clzll(1) - __builtin_clzll(NUM))
const int N = 1e6;
const ll MOD = 1e9 + 7;
const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
const int dx[8] = {0, -1, 0, 1, -1, -1, 1, 1};
const int dy[8] = {-1, 0, 1, 0, -1, 1, 1, -1};

// https://codeforces.com/problemset/problem/359/D
// https://codeforces.com/group/hr6flshS1O/contest/454552/problem/A
// binsearch

template <typename data_t>
struct sgcd {
    data_t operator()(data_t a, data_t b) {
        return __gcd(a, b);
    }
};
template <typename data_t>
struct smin {
    data_t operator()(data_t a, data_t b) {
        return min(a, b);
    }
};
template <typename data_t, typename cmp>
struct sparse_table {
    int n, k;
    vector<vector<data_t>> st;
    cmp comp;
    
    sparse_table(const vector<data_t> &a) {
        n = a.size();
        k = b_log2(n);
        
        st.resize(k + 1, vector<data_t>(n));
        st[0] = a;
        
        
        for (int i = 1; i <= k; i++){
            for (int j = 0; j + b_mask(i) - 1 < n; j++) {
                st[i][j] = comp(st[i - 1][j], st[i - 1][j + b_mask(i - 1)]);
            }
        }
    }
    
    data_t get(int l, int r) {
        int i = b_log2(r - l + 1);
        return comp(st[i][l], st[i][r - b_mask(i) + 1]);
    }
};
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(0);
    ////////////////
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    sparse_table<int, smin<int>> st_min(a);
    sparse_table<int, sgcd<int>> st_gcd(a);
    
    auto count = [&](int len) {
        vector<int> res;
        
        for (int l = 0, r = 0 + len - 1; r < n; l++, r++) {
            if (st_min.get(l, r) == st_gcd.get(l, r)) {
                res.push_back(l + 1);
            };
        }
        
        return res;
    };
    
    int al = 1, ar = n + 1;
    while (al < ar) {
        int am = (al + ar) / 2;
        
        if (count(am).size()) {
            al = am + 1;
        } else {
            ar = am;
        }
    }
    
    vector<int> ans = count(ar - 1);
    cout << ans.size() << sp << ar - 2 << nl;
    for (int it : ans) {
        cout << it << sp;
    }
    ////////////////
    return 0;
}