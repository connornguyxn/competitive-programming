#if DEBUG
    #include "lib/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "planet"
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
#define blog2(n) (63 - __builtin_clzll(n))
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
bool mxmz(T &a, T b) { return (b > a ? a = b, 1 : 0); }
template <class T>
bool mnmz(T &a, T b) { return (b < a ? a = b, 1 : 0); }
void add(ll &a, ll b) { a = (a + b) % MOD; }
void sub(ll &a, ll b) { a = (a + MOD - b) % MOD; }
void mul(ll &a, ll b) { a = a * (b % MOD) % MOD; }

// hnoj_planet
// <tags>

int n;
vector<int> a, st;
////////////////////////////////////////
void build(int tl = 1, int tr = n, int tv = 1) {
    if (tl == tr) {
        st[tv] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(tl, tm, tv * 2);
        build(tm + 1, tr, tv * 2 + 1);
        st[tv] = __gcd(st[tv * 2], st[tv * 2 + 1]);
    }
}
////////////////////
int query(int l, int r, int tl = 1, int tr = n, int tv = 1) {
    if (tr < l || r < tl) return 0;
    if (l <= tl && tr <= r) return st[tv];
    int tm = (tl + tr) / 2;
    return __gcd(query(l, r, tl, tm, tv * 2), query(l, r, tm + 1, tr, tv * 2 + 1));
}
////////////////////
void update(int p, int v, int tl = 1, int tr = n, int tv = 1) {
    if (p < tl || tr < p) return;
    if (tl == tr) {
        st[tv] = v;
    } else {
        int tm = (tl + tr) / 2;
        update(p, v, tl, tm, tv * 2);
        update(p, v, tm + 1, tr, tv * 2 + 1);
        st[tv] = __gcd(st[tv * 2], st[tv * 2 + 1]);
    }
}
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////////
    cin >> n;
    a.resize(n + 1);
    For(i, 1, n) cin >> a[i];
    
    st.resize(n * 4 + 4);
    build();
    
    vector<ll> dp(n + 1), sum(n + 1);
    dp[0] = sum[0] = 1;
    ll ans = 0;
    
    int cur = a[1], j = n;
    while (j > 1 && cur > 1) {
        cur = __gcd(cur, a[j--]);
        while (j > 1 && cur > 1 && __gcd(cur, a[j]) == cur) j--;
        
        // print(cur, j);
        
        // sum.assign(a.size(), 0);
        // sum[0] = 1;
        
        For(i, 1, a.size() - 1) {
            int l = 1, r = i;
            while (l < r) {
                int m = (l + r) / 2;
                if (query(m, i) > 1) r = m;
                else l = m + 1;
            }
            dp[i] = sum[i - 1] - (l > 1 ? sum[l - 2] : 0) + MOD;
            dp[i] %= MOD;
            sum[i] = (sum[i - 1] + dp[i]) % MOD;
        }
        // print(dp);
        
        while (a.size() - 1 > j) {
            ans = (ans + dp[a.size() - 1]) % MOD;
            a[1] = __gcd(a[1], a.back());
            a.pop_back();
        }
        update(1, a[1]);
        // print(a);
    }
    
    cout << ans;
    ////////////////////
    return 0;
}