#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #pragma GCC optimize("O3,unroll-loops,inline")
    #include <bits/stdc++.h>
    #define TASK "lightball"
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
const int N = 1e5;
const ll MOD = 1e9 + 7;
const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
// directions = left, up, right, down, upper_l, upper_r, lower_r, lower_l
const int dx[8] = {0, -1, 0, 1, -1, -1, 1, 1};
const int dy[8] = {-1, 0, 1, 0, -1, 1, 1, -1};
template<typename tVar, typename tVal>
void mnmz(tVar &var, tVal val) { if (val < var) var = val; }
template<typename tVar, typename tVal>
void mxmz(tVar &var, tVal val) { if (val > var) var = val; }

// lightball
// math

array<vector<ll>, 3> val;
////////////////////////////////////////
ll solve(vector<ll> &a, vector<ll> &b, vector<ll> &c) {
    ll res = INFLL;
    
    for (int j = 0; j < b.size(); j++) {
        int i = lower_bound(all(a), b[j]) - a.begin() - 1;
        int k = upper_bound(all(c), b[j]) - c.begin();
        // db(i, j, k);
        if (i < 0 || k == c.size()) continue;
        
        mnmz(res, (a[i] - b[j]) * (a[i] - b[j]) + (b[j] - c[k]) * (b[j] - c[k]) + (c[k] - a[i]) * (c[k] - a[i]));
    }
    
    return res;
}
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(0);
    ////////////////
    int n[3];
    cin >> n[0] >> n[1] >> n[2];
    
    for (int i = 0; i < 3; i++) {
        val[i].resize(n[i]);
        for (int j = 0; j < n[i]; j++) {
            cin >> val[i][j];
        }
        sort(all(val[i]));
    }
    
    array<int, 3> id;
    iota(all(id), 0);
    
    ll res = INFLL;
    for (int i = 0; i <= 6; i++) {
        mnmz(res, solve(val[id[0]], val[id[1]], val[id[2]]));
        next_permutation(all(id));
    }
    
    cout << res;
    ////////////////
    return 0;
}
