// #pragma GCC optimize("O3") // safest optimization
// #pragma GCC target("sse4.2") // SIMD instruction optimization
// include headers after compile options
#include <bits/stdc++.h> // replaced with custom header, see `templates/stdc++.h`
using namespace std;
using ll = long long;
using ull = unsigned long long;
// using db = double;
using str = string;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template <class T>
using vector2 = vector<vector<T>>;
template <class T>
using vector3 = vector<vector2<T>>;
#define fi first
#define se second
#define nl '\n' // saving time by not flushing cout buffer
#define sp ' '
#define all(a) (a).begin(), (a).end()
#define tvl (tv * 2)
#define tvr (tv * 2 + 1)
#define FOR(i, l, r) for (ll i = (l), _r = (r); i <= _r; i++)
#define FORD(i, r, l) for (ll i = (r), _l = (l); i >= _l; i--)
#define FORIN(it, a) for (auto& it : a)
#define bmask(i) (1LL << (i))
#define bget(i, n) ((n) >> (i) & 1)
const ll MOD = 1e9 + 7; // common modulo
// maximum values for common data types
// INFINITY cannot be used when combining multiple max values
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
// parameter pack expansion: https://stackoverflow.com/a/25683817
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
// void add(ll& a, ll b) { a = (a + b) % MOD; }
// void sub(ll& a, ll b) { a = (a + MOD * MOD - b) % MOD; }
// void mul(ll& a, ll b) { a = a * (b % MOD) % MOD; }
////////////////////////////////////////!
// debug printing
template <class... T>
void print(T&&... a) {
    cout << "[debug] ";
    using e = int[];
    e{(cout << a << sp, 0)...};
    cout << endl;
}
// container printing: https://codeforces.com/blog/entry/68920
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


//! <problem link>
//! <tags>

int n;
vector<ll> a;
////////////////////////////////////////////////////////////////////////////////!
namespace subf {
    ////////////////////////////////////////!
    void main() {
        
    }
}
////////////////////////////////////////////////////////////////////////////////!
int main() {
    // #define TASK "test"
    #define TASK "<task>"
    freopen(TASK".inp", "r", stdin);
    //! freopen(TASK".out", "w", stdout);
    // desync cin from cout and C++ from C input
    cin.tie(nullptr)->sync_with_stdio(false);
    // cout << fixed << setprecision(12); // set floating point precision
    atexit(logtime); // log time at exit
    ////////////////////////////////////////!
    cin >> n;
    
    resize(n + 1, a);
    FOR(i, 1, n) cin >> a[i];
    
    return subf::main(), 0;
    ////////////////////////////////////////!
    // for good measure :)
    // return 0+0-0*0/~0&0|0^0;
}
