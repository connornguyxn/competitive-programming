#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #pragma GCC optimize("O3,unroll-loops,inline")
    #include <bits/stdc++.h>
    #define TASK "numbersgame"
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

// numbersgame
// <tags>

////////////////////////////////////////
int main() {
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    };
    cin.tie(0) -> sync_with_stdio(0);
    ////////////////
    int n, m;
    cin >> n >> m;
    
    vector<int> sl(m + 2), sr(m + 2);
    
    for (int i = 0; i < n; i++) {
        int l, r, w;
        cin >> l >> r >> w;
        
        sl[r] += w;
        sr[l] += w;
    }
    
    for (int i = 1; i <= m; i++) {
        sl[i] += sl[i - 1];
        sr[m - i + 1] += sr[m - i + 2];
    }
    
    int res = 0;
    for (int i = 1; i <= m; i++) {
        mxmz(res, sl[i - 1] + sr[i + 1]);
    }
    
    cout << res;
    ////////////////
    return 0;
}