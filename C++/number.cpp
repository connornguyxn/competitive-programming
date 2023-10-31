#if DEBUG
    #include "lib/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "number"
#endif
using namespace std;
using ll = long long;
using ull = unsigned long long;
using str = string;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define fi first
#define se second
#define nl '\n'
#define sp ' '
#define all(a) (a).begin(), (a).end()
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define Repd(i, n) for (int i = (n); i--; )
#define For(i, l, r) for (int i = (l), _r = (r); i <= _r; i++)
#define Fors(i, l, r) for (int i = (l), _r = (r); i < _r; i++)
#define Ford(i, r, l) for (int i = (r) + 1, _l = (l); --i >= _l; )
#define Forin(it, var) for (auto& it : var)
#define bmask(i) (1ULL << (i))
#define bget(mask, i) ((mask >> (i)) & 1)
const int N = 1e6;
const ll MOD = 1e9 + 7;
const ull BASE = 311;
const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
const int dx[8] = {0, -1, 0, 1, -1, -1, 1, 1};
const int dy[8] = {-1, 0, 1, 0, -1, 1, 1, -1};
template <class... T>
void print(T&&... n) {
    using exp = int[];
    exp{0, (cout << n << sp, 0)...};
    cout << endl;
}
template <class T>
bool mxmz(T &a, T b) { return a < b ? a = b, 1 : 0; }
template <class T>
bool mnmz(T &a, T b) { return b < a ? a = b, 1 : 0; }
void add(ll &a, ll b) { a = (a + b) % MOD; }
void sub(ll &a, ll b) { a = (a + MOD - b) % MOD; }
void mul(ll &a, ll b) { a = a * (b % MOD) % MOD; }

// lmh_number
// dp

////////////////////////////////////////
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////////
    str a, b;
    cin >> a >> b;

    reverse(all(a));
    reverse(all(b));
    vector<vector<pair<int, char>>> dp(a.size() + 1, vector<pair<int, char>>(b.size() + 1, {0, '0'}));
    int mi = 0, mj = 0;
    pair<int, char> ans{0, '0'};
    
    For(i, 1, a.size()) {
        For(j, 1, b.size()) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = {dp[i - 1][j - 1].fi + 1, a[i - 1]};
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
            if (dp[i][j].se != '0' && dp[i][j] >= ans) {
                ans = dp[i][j];
                mi = i; mj = j;
            }
        }
    }
    // print(dp);
    // print(ans);
    
    if (ans.se == '0') return !(cout << 0);
    
    while (a[mi - 1] != ans.se) mi--;
    while (b[mj - 1] != ans.se) mj--;
    while (ans.fi) {
        cout << a[mi - 1];
        mi--; mj--; ans.fi--;
        ans.se = dp[mi][mj].se;
        // print(mi, mj);
        if (ans.fi == 0) break;
        while (a[mi - 1] != ans.se) {
            mi--;
            // print("mi", mi);
        }
        while (b[mj - 1] != ans.se) {
            mj--;
            // print("mj", mj);
        }
    }
    ////////////////////
    return 0;
}