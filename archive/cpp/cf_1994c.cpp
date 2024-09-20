#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using str = string;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define fi first
#define se second
#define nl '\n'
#define sp ' '
#define all(a) (a).begin(), (a).end()
#define FOR1(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FOR2(i, l, r) for (int i = (l), _r = (r); i <= _r; i++)
#define FOR3(i, r, l, sp) for (int i = (r), _l = (l); i >= _l; i--)
#define OVERLOAD(a, b, c, d, e, ...) e
#define FOR(...) OVERLOAD(__VA_ARGS__, FOR3, FOR2, FOR1)(__VA_ARGS__)
#define FORIN(it, a) for (auto& it : a)
#define bmask(i) (1LL << (i))
#define bget(i, n) ((n) >> (i) & 1)
#define bon(i, n) ((n) | bmask(i))
#define boff(i, n) ((n) & ~bmask(i))
const ll MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
template <class T, class... C>
void assign(int n, T v, C&&... a) {
    using e = int[];
    e{(a.assign(n, v), 0)...};
}
template <class... C>
void resize(int n, C&&... a) {
    using e = int[];
    e{(a.resize(n), 0)...};
}
template <class... T>
void print(T&&... a) {
    cout << "[debug] ";
    using e = int[];
    e{(cout << a << sp, 0)...};
    cout << endl;
}
template <class Ch, class Tr, class C>
basic_ostream<Ch, Tr>& operator<<(basic_ostream<Ch, Tr>& cout, C& a) {
    cout << "{ ";
    FORIN(it, a) cout << it << sp;
    return cout << "}";
}
template <class T1, class T2>
ostream& operator<<(ostream& cout, pair<T1, T2>& a) {
    return cout << '(' << a.fi << sp << a.se << ')';
}

// https://codeforces.com/problemset/problem/1994/C
// dp, binsearch

////////////////////////////////////////
void solve() {
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n + 1);
    
    FOR(i, 1, n) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    
    
    vector<ll> dp(n + 3);
    FOR(i, n, 1, sp) {
        int lo = i - 1, hi = n + 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (a[mid] - a[i - 1] <= k) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        
        dp[i] = dp[hi + 1] + (hi - i);
    };
    
    ll ans = 0;
    FOR(i, 1, n) ans += dp[i];
    cout << ans << nl;
}
////////////////////////////////////////
int main() {
    #define TASK "test"
    // freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    ////////////////////////////////////////
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    ////////////////////////////////////////
}