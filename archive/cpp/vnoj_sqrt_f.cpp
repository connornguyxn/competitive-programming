#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("popcnt")

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sp ' '
#define nl '\n'
#define FOR(i, l, r) for (int i = (l), _r = (r); i <= _r; i++)


// https://oj.vnoi.info/problem/sqrt_f
// sqrtdcmp


constexpr int N = 250000, bsize = 21000, bcnt = N / bsize + !!(N % bsize);
constexpr int M = 5e4;

int n, q;
ll ans = 0;
array<int, N> a;
////////////////////////////////////////
struct FenwickTree {
    array<int, M + 1> f = {};
    ////////////////////////////////////////
    void update(int i, const int& val) {
        while (i <= M) {
            f[i] += val;
            i += i & -i;
        }
    }
    ////////////////////////////////////////
    int get(int i) {
        int res = 0;
        while (i > 0) {
            res += f[i];
            i -= i & -i;
        }
        return res;
    }
    ////////////////////////////////////////
    int get(const int& l, const int& r) {
        return get(r) - get(l - 1);
    }
};
////////////////////////////////////////
array<FenwickTree, bcnt> block;
FenwickTree arr;
////////////////////////////////////////////////////////////////////////////////
int main() {
    #define TASK "vnoj_sqrt_f"
    // freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    ////////////////////////////////////////
    cin >> n;
    FOR(i, 0, n - 1) {
        cin >> a[i];
        
        ans += arr.get(a[i] + 1, M);
        arr.update(a[i], 1);
        
        block[i / bsize].update(a[i], 1);
    }
    
    
    cin >> q;
    FOR(cq, 1, q) {
        int pos, x;
        cin >> pos >> x;
        pos--;
        
        int p = pos / bsize;
        
        FOR(i, 0, p - 1) {
            ans += block[i].get(x + 1, M) - block[i].get(a[pos] + 1, M);
        }
        
        FOR(i, p + 1, bcnt - 1) {
            ans += block[i].get(1, x - 1) - block[i].get(1, a[pos] - 1);
        }
        
        FOR(i, bsize * p, pos - 1) {
            ans += (a[i] > x) - (a[i] > a[pos]);
        }
        FOR(i, pos + 1, min(bsize * (p + 1), n) - 1) {
            ans += (a[i] < x) - (a[i] < a[pos]);
        }
        
        block[p].update(a[pos], -1);
        block[p].update(x, 1);
        a[pos] = move(x);
        
        cout << ans << nl;
    }
    ////////////////////////////////////////
    return 0;
}
