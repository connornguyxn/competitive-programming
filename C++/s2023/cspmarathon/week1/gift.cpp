#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #pragma GCC optimize("O3,unroll-loops")
    #pragma GCC target("sse4.2")
    #include <bits/stdc++.h>
    #define TASK "gift"
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
const int N = 1e3 + 1;
const ll MOD = 1e9 + 7;
const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
const int dx[8] = {0, -1, 0, 1, -1, -1, 1, 1};
const int dy[8] = {-1, 0, 1, 0, -1, 1, 1, -1};

// gift
// <tags>

int n;
ll k;
vector<ll> a;
int dp[N][N];
////////////////////////////////////////
int solve(int id, ll mod) {
    if (id == n) return !mod;
    if (dp[id][mod] > 0) return dp[id][mod];
    
    dp[id][mod] = 0;
    For(i, id, n) {
        dp[id][mod] |= solve(i + 1, (mod + a[i]) % k);
        dp[id][mod] |= solve(i + 1, (mod + k - a[i]) % k);
    }
    
    return dp[id][mod];
}
/////////////
void trace(int id, ll mod) {
    if (id == n) return;
    
    For(i, id, n) {
        if (solve(i + 1, (mod + a[i]) % k)) {
            cout << i + 1 << sp;
            trace(i + 1, (mod + a[i]) % k);
            return;
        }
        if (solve(i + 1, (mod + k - a[i]) % k)) {
            cout << -(i + 1) << sp;
            trace(i + 1, (mod + k - a[i]) % k);
            return;
        }
    }
}
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////
    cin >> n >> k;
    Rep(i, n) a.push_back(inp<ll>());
    
    memset(dp, -1, sizeof(dp));
    
    if (solve(0, 0)) {
        trace(0, 0);
    } else {
        cout << 0;
    }
    ////////////////
    return 0;
}