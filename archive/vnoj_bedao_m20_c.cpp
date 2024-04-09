#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #pragma GCC optimize("O3,unroll-loops")
    #pragma GCC target("sse4.2")
    #include <bits/stdc++.h>
    #define TASK "c"
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
#define all(var) (var).begin(), (var).end()
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define Repd(i, n) for (int i = (n); i--; )
#define For(i, l, r) for (int i = (l), _r = (r); i < _r; i++)
#define Ford(i, r, l) for (int i = (r), _l = (l); --i >= _l; )
#define Fore(i, l, r) for (int i = (l), _r = (r); i <= _r; i++)
#define Forde(i, r, l) for (int i = (r) + 1, _l = (l); --i >= _l; )
#define Forin(it, var) for (auto it : var)
#define Bmask(i) (1ULL << (i))
#define Bget(mask, i) ((mask >> (i)) & 1)
#define Blog(n) (63 - __builtin_clzll(n))
template <class T = int>
T inp() { T x; cin >> x; return x; }
template <typename... T>
void print(T&&... n) {
    using exp = int[];
    exp{0, (cout << n << sp, 0)...};
    cout << nl;
}
template <class T>
void mxmz(T &a, T b) { a = max(a, b); }
template <class T>
void mnmz(T &a, T b) { a = max(a, b); }
const int N = 1e6;
const ll MOD = 1e9 + 7;
const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
const int dx[8] = {0, -1, 0, 1, -1, -1, 1, 1};
const int dy[8] = {-1, 0, 1, 0, -1, 1, 1, -1};

// vnoj_bedao_m20_c
// <tags>

////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        
        vector<ll> a(2);
        vector<vector<int>> cnt(2, vector<int>(10));
        Fore(i, 1, n) {
            cin >> a.back();
            [&](ll tmp) {
                while (tmp > 0) {
                    cnt.back()[tmp % 10]++;
                    if (cnt.back()[tmp % 10] > 1) {
                        cnt.back().assign(10, 0);
                        return;
                    }
                    tmp /= 10;
                }
                a.push_back(0);
                cnt.push_back(vector<int>(10));
            }(a.back());
        }
        a.pop_back();
        cnt.pop_back();
        n = a.size() - 1;
        // print(n, a);
        
        vector<vector<ll>> dp(n + 1, vector<ll>(1024, -INFLL));
        dp[0][0] = 0;
        
        Fore(id, 1, n) {
            dp[id] = dp[id - 1];
            Rep(pre, 1024) {
                [&]() {
                    int cur = pre;
                    Rep(i, 10) {
                        if (cnt[id][i]) {
                            if (Bget(cur, i)) return;
                            cur |= Bmask(i);
                        }
                    }
                    mxmz(dp[id][cur], dp[id - 1][pre] + a[id]);
                }();
            }
        }
        cout << *max_element(all(dp[n])) << nl;
    }
    ////////////////
    return 0;
}