#if DEBUG
    #include "lib/debug.h"
    #define TASK "test"
#else
    #pragma GCC optimize("O3")
    #pragma GCC target("sse4.2")
    #include <bits/stdc++.h>
    #define TASK "leasing"
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

// https://oj.vnoi.info/problem/chvpt_dtqg23_leasing
// dp

int n;
struct Job {
    int l = -1, r = -1, id = 0;
    ll w = 0;
    bool operator < (const Job& oth) const {
        return r < oth.r;
    }
};
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////////
    cin >> n;
    
    vector<Job> a(n + 1);
    For(i, 1, n) {
        cin >> a[i].l >> a[i].r >> a[i].w;
        a[i].id = i;
    }
    sort(1 + all(a));
    
    vector<pair<ll, int>> dp(n + 1);
    vector<int> trace(n + 1);
    
    For(i, 1, n) {
        pair<ll, int> cur = dp[upper_bound(all(a), Job{0, a[i].l}) - a.begin() - 1];
        
        dp[i].fi = cur.fi + a[i].w;
        trace[i] = cur.se;
        dp[i].se = i;
        
        mxmz(dp[i], dp[i - 1]);
    }
    
    int pos = dp[n].se;
    vector<int> ans;
    
    while (pos) {
        ans.push_back(a[pos].id);
        pos = trace[pos];
    }
    reverse(all(ans));
    
    cout << ans.size() << sp << dp[n].fi << nl;
    Forin(it, ans) cout << it << sp;
    ////////////////////
    return 0;
}