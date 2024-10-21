#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using str = string;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template <class T>
using vector2 = vector<vector<T>>;
template <class T>
using vector3 = vector<vector2<T>>;
#define fi first
#define se second
#define nl '\n'
#define sp ' '
#define all(a) (a).begin(), (a).end()
#define tvl (tv * 2)
#define tvr (tv * 2 + 1)
#define FOR(i, l, r) for (ll i = (l), _r = (r); i <= _r; i++)
#define FORD(i, r, l) for (ll i = (r), _l = (l); i >= _l; i--)
#define FORIN(it, a) for (auto& it : a)
#define bmask(i) (1LL << (i))
#define bget(i, n) ((n) >> (i) & 1)
const ll MOD = 998244353;
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
////////////////////////////////////////
template <class... T>
void print(T&&... a) {
    cout << "[debug] ";
    using e = int[];
    e{(cout << a << sp, 0)...};
    cout << endl;
}
template <class Ch, class Tr, class C>
basic_ostream<Ch, Tr>& operator<<(basic_ostream<Ch, Tr>& cout, C a) {
    cout << "{ ";
    FORIN(it, a) cout << it << sp;
    return cout << "}";
}
template <class T1, class T2>
ostream& operator<<(ostream& cout, pair<T1, T2> a) {
    return cout << '(' << a.fi << sp << a.se << ')';
}
void logtime() {
    cout << flush;
    clog << nl << "[time] " << clock() * 1.0 / CLOCKS_PER_SEC << nl;
}


// https://dmoj.ca/problem/coci22c3p4
// dp, math

int n;
ll k;
vector2<ll> a;
////////////////////////////////////////////////////////////////////////////////
namespace subf {
    ////////////////////////////////////////
    vector2<unordered_map<ll, ll>> dp;
    ////////////////////////////////////////
    ll solve(int r, int c, int gcd) {
        if (r == n && c == n) return gcd == k;
        
        if (dp[r][c].count(gcd)) return dp[r][c][gcd];
        ll& res = dp[r][c][gcd];
        res = 0;
        
        if (r < n && a[r + 1][c] != -1) {
            res = (res + solve(r + 1, c, gcd * __gcd(k, a[r + 1][c]))) % MOD;
        }
        if (c < n && a[r][c + 1] != -1) {
            res = (res + solve(r, c + 1, gcd * __gcd(k, a[r][c + 1]))) % MOD;
        }
        
        return res;
    }
    ////////////////////////////////////////
    void main() {
        dp.resize(n + 1, vector<unordered_map<ll, ll>>(n + 1));
        cout << solve(1, 1, __gcd(a[1][1], k));
    }
}
////////////////////////////////////////////////////////////////////////////////
int main() {
    #define TASK "dmoj_coci22c3p4"
    // freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    atexit(logtime);
    ////////////////////////////////////////
    cin >> n >> k;
    
    a.resize(n + 1, vector<ll>(n + 1));
    FOR(i, 1, n) {
        FOR(j, 1, n) {
            cin >> a[i][j];
        }
    }
    
    return subf::main(), 0;
    ////////////////////////////////////////
}