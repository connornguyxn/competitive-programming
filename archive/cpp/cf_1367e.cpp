#include "bits/stdc++.h"
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
#define FOR(i, l, r) for (int i = (l), _r = (r); i <= _r; i++)
#define FORD(i, r, l) for (int i = (r), _l = (l); i >= _l; i--)
#define FORIN(it, a) for (auto& it : a)
#define bmask(i) (1LL << (i))
#define bget(i, n) ((n) >> (i) & 1)
#define bon(i, n) ((n) | bmask(i))
#define boff(i, n) ((n) & ~bmask(i))
const ll MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ull N = 1e6 + 3;
template <class T>
using vector2 = vector<vector<T>>;
template <class T>
using vector3 = vector<vector2<T>>;
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

// https://codeforces.com/problemset/problem/1367/E
// dp

int n, k;
str s;
////////////////////////////////////////////////////////////////////////////////
void solve() {
    cin >> n >> k;
    cin >> s;
    
    n = 26;
    vector<int> a(n + 1);
    FORIN(it, s) a[it - 'a' + 1]++;
    // print(a);
    
    vector2<int> dp(n + 1, vector<int>(k + 1));
    dp[0][0] = INF;
    
    FOR(i, 1, n) {
        FOR(len, 0, k) {
            dp[i][len] = dp[i - 1][len];
            FOR(cnt, 1, min(a[i], len)) {
                dp[i][len] = max(dp[i][len], min(dp[i - 1][len - cnt], a[i] / cnt));
            }
        }
    }
    
    // FORIN(it, dp) print(it);
    
    int ans = 0;
    FOR(i, 1, k) {
        if (k % i) continue;
        FORIN(it, dp) {
            ans = max({ans, i * it[i], k / i * it[k / i]});
        }
    }
    cout << ans << nl;
}
////////////////////////////////////////////////////////////////////////////////
int main() {
    #define TASK "test"
    // #define TASK "1367e"
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    ////////////////////////////////////////
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    ////////////////////////////////////////
}