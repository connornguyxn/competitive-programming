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
#define sp ' '
#define nl '\n'
#define fi first
#define se second
#define size(a) ((int)(a).size())
#define all(a) begin(a), end(a)
#define tvl (tv * 2)
#define tvr (tv * 2 + 1)
#define FOR(i, l, r) for (int i = (l), _r = (r); i <= _r; i++)
#define FORD(i, r, l) for (int i = (r), _l = (l); i >= _l; i--)
#define FORIN(it, a) for (auto& it : a)
#define bmask(i) (1LL << (i))
#define bget(i, n) ((n) >> (i) & 1)
const ll MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
void addmod(ll& a, ll b) { a = (a + b % MOD) % MOD; }
void submod(ll& a, ll b) { a = (a + MOD - b % MOD) % MOD; }
void mulmod(ll& a, ll b) { a = a * (b % MOD) % MOD; }
template <class T, class... C>
void minimize(T& a, C&&... v) {
    a = min<T>({a, v...});
}
template <class T, class... C>
void maximize(T& a, C&&... v) {
    a = max<T>({a, v...});
}
template <class T, class... C>
void assign(int n, const T& v, C&&... a) {
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
    cout << flush;
    clog << "\n[debug] ";
    using e = int[];
    e{(clog << a << sp, 0)...};
    clog << endl;
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
    print("[time]", clock() * 1.0 / CLOCKS_PER_SEC);
}


// cf_2033c
// dp, easy



////////////////////////////////////////////////////////////////////////////////
namespace sub1 {
    ////////////////////////////////////////
    ////////////////////////////////////////
    void main() {
        int n;
        cin >> n;
        vector<int> a(n + 2);
        FOR(i, 1, n) {
            cin >> a[i];
        }
        
        vector2<ll> dp(n / 2 + 1, vector<ll>(2));
        FOR(i, 1, n / 2) {
            dp[i][0] = min(
                dp[i - 1][0] + (a[i - 1] == a[i]) + (a[n - i + 1] == a[n - i + 2]),
                dp[i - 1][1] + (a[n - i + 2] == a[i]) + (a[n - i + 1] == a[i - 1])
            );
            dp[i][1] = min(
                dp[i - 1][1] + (a[i - 1] == a[i]) + (a[n - i + 1] == a[n - i + 2]),
                dp[i - 1][0] + (a[n - i + 2] == a[i]) + (a[n - i + 1] == a[i - 1])
            );
        }
        
        cout << min(dp[n / 2][0], dp[n / 2][1]) + (a[n / 2] == a[n / 2 + 1]) + (n % 2 ? a[n / 2 + 2] == a[n / 2 + 1] : 0) << nl;
    }
    void run() {
        main();
        // exit(0);
    }
}
////////////////////////////////////////////////////////////////////////////////
int main() {
    #define TASK "cf_2033c"
    freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    atexit(logtime);
    ////////////////////////////////////////
    int tc;
    cin >> tc;
    
    FOR(i, 1, tc) {
        sub1::run();
    }
    ////////////////////////////////////////
    return 0;
}