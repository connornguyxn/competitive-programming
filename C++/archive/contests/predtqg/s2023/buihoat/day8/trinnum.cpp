#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #pragma GCC optimize("O3,unroll-loops,inline")
    #include <bits/stdc++.h>
    #define TASK "trinnum"
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

// trinum
// <tags>

////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(0);
    ////////////////
    int n;
    ll m;
    cin >> n >> m;
    
    vector<ll> cnt(m);
    for (int i = 0; i < n; i++) {
        ll inp;
        cin >> inp;
        cnt[inp % m]++;
    }
    
    vector<ll> cnt2(m);
    for (ll i = 0; i < m; i++) {
        for (ll j = 0; j < m; j++) {
            cnt2[i * j % m] += cnt[i] * cnt[j];
        }
    }
    
    ll res = 0;
    for (ll i = 0; i < m; i++) {
        for (ll j = 0; j < m; j++) {
            if (i * j % m == 0) {
                res += cnt[i] * cnt2[j];
            }
        }
    }
    
    cout << res;
    ////////////////
    return 0;
}