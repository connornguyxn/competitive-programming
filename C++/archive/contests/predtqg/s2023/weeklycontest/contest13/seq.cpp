#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #pragma GCC optimize("O3,unroll-loops,inline")
    #include <bits/stdc++.h>
    #define TASK "seq"
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

// seq
// <tags>

////////////////////////////////////////
int main() {
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    };
    cin.tie(0) -> sync_with_stdio(0);
    ////////////////
    int tc;
    cin >> tc;
    while (tc--) {
        int n, l, r;
        cin >> n >> l >> r;
        
        unordered_map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            int inp;
            cin >> inp;
            cnt[inp] += (i < l ? 1 : -1);
        }
        
        l = 0;
        r = 0;
        vector<pii> left;
        for (pii it : cnt) {
            if (it.se > 0) l += it.second;
            if (it.se < 0) r += -it.second;
            if (it.se != 0) left.push_back(it);
        }
        sort(all(left), [l, r](pii a, pii b) { return (l < r ? a.se < b.se : a.se > b.se); });
        // db(left);
        // db(l, r);
        
        int res = 0;
        for (pii &cur : left) {
            if (l > r && cur.se > 0) {
                int dif = (l + r) / 2 - r;
                res += min(cur.se / 2, dif);
                l -= min(cur.se / 2, dif) * 2;
                cur.se -= min(cur.se / 2, dif) * 2;
            }
            if (l < r && cur.se < 0) {
                int dif = l - (l + r) / 2;
                res += min(abs(cur.se) / 2, dif);
                r -= min(abs(cur.se) / 2, dif) * 2;
                cur.se += min(abs(cur.se) / 2, dif) * 2;
            }
        }
        // db(left);
        
        for (pii &cur : left) {
            if (l > r && cur.se > 0) {
                cur.se = -cur.se;
                l--;
                r++;
                res++;
            }
            if (l < r && cur.se < 0) {
                cur.se = -cur.se;
                r--;
                l++;
                res++;
            }
        }
        
        int pos = 0, neg = 0;
        for (pii it : left) {
            if (it.se > 0) pos++;
            if (it.se < 0) neg++;
        }
        res += max(pos, neg);
        
        cout << res << nl;
        // cout << nl;
    }
    ////////////////
    return 0;
}