#if DEBUG
    #include "lib/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "debt"
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

// https://wc2023northern.contest.codeforces.com/group/wgk1jQXfDf/contest/484506
// dp

int n, m, k;
vector<pii> a, b;
vector<vector<vector<int>>> dp;
////////////////////////////////////////
int solve(int ida, int idb, int cst) {
    if (cst > k) return INF;
    if (ida == n) return 0;
    
    int& res = dp[ida][idb][cst];
    if (res != -1) return res;
    
    res = solve(ida + 1, idb, cst) + a[ida].fi;
    For(i, idb, m - 1) {
        mnmz(res, solve(ida + 1, i + 1, cst + abs(a[ida].se - b[i].se)) + b[i].fi);
    }
    return res;
}
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////////
    int l, r;
    cin >> n >> l >> r >> k;
    
    For(i, 1, n) {
        int inp;
        cin >> inp;
        if (l <= i && i <= r) {
            a.emplace_back(inp, i);
        } else {
            b.emplace_back(inp, i);
        }
    }
    // print(a);
    // print(b);
    
    n = a.size();
    m = b.size();
    dp.resize(n, vector<vector<int>>(m + 1, vector<int>(k + 1, -1)));
    
    cout << solve(0, 0, 0);
    ////////////////////
    return 0;
}