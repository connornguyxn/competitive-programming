#if DEBUG
    #include "lib/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "num19"
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

// https://oj.vnoi.info/contest/chvpt_ksdtqg2/
// dp

str n;
ll dp[10000][2][19][8];
int vis[10000][2][19][8];
int tmr;
////////////////////////////////////////
ll solve(int id, bool low, int mod, int mask) {
    if (id == n.size()) return mod == 0;
    if (vis[id][low][mod][mask] == tmr) return dp[id][low][mod][mask];
    
    vis[id][low][mod][mask] = tmr;
    ll& res = dp[id][low][mod][mask] = 0;
    
    int lim = low ? 9 : n[id] - '0';
    For(i, 0, lim) {
        if (bget(mask, (9 - i) % 3)) continue;
        int nmask = mask;
        if (i > 0 || __builtin_popcount(mask) > 0) nmask |= bmask(i % 3);
        add(res, solve(id + 1, low || i < lim, (mod * 10 + i) % 19, nmask));
    }
    
    return res;
}
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////
    int tc;
    cin >> tc;
    while (tc--) {
        str l, r;
        cin >> l >> r;
        
        int sum = 0, mask = 0;
        Rep(i, l.size()) {
            sum = (sum * 10 + l[i] - '0') % 19;
            if (bget(mask, (9 - (l[i] - '0')) % 3)) {
                sum = 1;
                break;
            }
            mask |= bmask((l[i] - '0') % 3);
        }
        ll ans = sum == 0;
        // print("ans", ans);
        
        tmr++;
        n = r;
        add(ans, solve(0, 0, 0, 0));
        // print("add", solve(0, 0, 0, 0));
        
        tmr++;
        n = l;
        sub(ans, solve(0, 0, 0, 0));
        // print("sub", solve(0, 0, 0, 0));
        
        cout << ans << nl;
    }
    ////////////////
    return 0;
}
