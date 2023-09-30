#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #pragma GCC optimize("O3,unroll-loops,inline")
    #include <bits/stdc++.h>
    #define TASK "game"
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

// game
// <tags>

int n, tc;
vector<ll> a;
////////////////////////////////////////
struct sub1 {
    sub1() {
        while (tc--) {
            int typ;
            ll x, y;
            cin >> typ >> x >> y;
            
            if (typ == 1) {
                a[x - 1] += y;
            } else {
                ll res = 0;
                for (int i = 0; i < n; i++) {
                    res += a[i] * (a[i] % x == y);
                }
                cout << res << nl;
            }
        }
    }
};
////////////////////////////////////////
struct sub2 {
    sub2() {
        vector<vector<ll>> res(201, vector<ll>(200));
        while (tc--) {
            int typ;
            ll x, y;
            cin >> typ >> x >> y;
            
            if (typ == 1) {
                x--;
                for (int i = 1; i <= 200; i++) {
                    res[i][abs(a[x] % i)] -= a[x];
                    res[i][abs((a[x] + y) % i)] += a[x] + y;
                }
                a[x] += y;
            } else {
                cout << res[x][y] << nl;
            }
        }
    }
};
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(0);
    ////////////////
    cin >> n >> tc;
    a.resize(n);
    
    if (n <= 5000 && tc <= 5000) {
        sub1();
    } else {
        sub2();
    }
    ////////////////
    return 0;
}