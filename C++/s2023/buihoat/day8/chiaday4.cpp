#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #pragma GCC optimize("O3,unroll-loops,inline")
    #include <bits/stdc++.h>
    #define TASK "chiaday4"
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
#define b_mask(POS) (1ULL << (POS))
#define b_get(MASK, POS) ((MASK >> (POS)) & 1)
#define all(VAR) (VAR).begin(), (VAR).end()
const int N = 1e6;
const ull MOD = 1e9 + 7;
const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
// directions = left, up, right, down, upper_l, upper_r, lower_r, lower_l
const int dx[8] = {0, -1, 0, 1, -1, -1, 1, 1};
const int dy[8] = {-1, 0, 1, 0, -1, 1, 1, -1};
template<typename tVar, typename tVal>
void mnmz(tVar &var, tVal val) { if (val < var) var = val; }
template<typename tVar, typename tVal>
void mxmz(tVar &var, tVal val) { if (val > var) var = val; }

// chiaday4
// dp

////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(0);
    ////////////////
    int n;
    cin >> n;
    
    vector<ll> a(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    ll opt = 0, cur = 0;
    vector<ll> mxl(n + 2);
    for (int i = 1; i <= n + 1; i++) {
        cur += a[i];
        mxl[i] = opt * 2 - cur;
        mxmz(opt, cur);
    }
    
    opt = 0, cur = 0;
    vector<ll> mxr(n + 2);
    for (int i = n; i >= 0; i--) {
        cur += a[i];
        mxr[i] = cur - opt * 2;
        mnmz(opt, cur);
    }
    
    // db(mxl);
    // db(mxr);
    
    ll res = -INFLL;
    for (int i = 0; i <= n + 1; i++) {
        res = max({res, mxl[i] + mxr[i], mxl[i] + mxr[min(n + 1, i + 1)]});
    }
    
    cout << res;
    ////////////////
    return 0;
}