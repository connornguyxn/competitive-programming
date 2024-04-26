// note: include headers *after* compile options
#include "bits/stdc++.h"
#ifdef LOCAL
    #define TASK "test" // define local task name
#else
    // #pragma GCC optimize("O3") // safest optimization
    // #pragma GCC target("sse4.2") // SIMD instruction optimization
    #define TASK "<task name>"
#endif
//* aliases
using namespace std; // use standard namespace for faster access
using ll = long long;
using ull = unsigned long long;
using str = string;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define fi first
#define se second
#define nl '\n' // saving time by not flushing cout buffer
#define sp ' '
#define dr(a) (*(a)) // dereferencing a variable, reduce clutter
#define all(a) (a).begin(), (a).end()
//* functions and macros
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; i++) // repeat from 0 to n - 1
#define Repd(i, n) for (int i = (n); i--; ) // decreasing
#define For(i, l, r) for (int i = (l), _r = (r); i <= _r; i++) // for l to r
#define Ford(i, r, l) for (int i = (r), _l = (l); i >= _l; i--) // decreasing
#define Forin(it, var) for (auto& it : var)
// bitwise macros
#define bmask(i) (1ULL << (i)) // bitmask
#define bget(mask, i) ((mask >> (i)) & 1) // get bit
//* common constants
const int N = 1e6; // array limit
const ll MOD = 1e9 + 7;// common modulo
// maximum values for common data types
// INFINITY cannot be used when combining multiple max values
const int INF = 1e9 + 10;
const ll INFLL = 1e18 + 10;
//! right, down, left, up, lower right, lower left, upper left, upper right
const int dv[] = {0, 1, 0, -1, 1, 1, -1, -1};
const int dh[] = {1, 0, -1, 0, 1, -1, -1, 1};
// maximize and minimize
template <class T>
bool mxmz(T &a, T b) { return a < b ? a = b, 1 : 0; }
template <class T>
bool mnmz(T &a, T b) { return b < a ? a = b, 1 : 0; }
// math functions with modulo
void add(ll &a, ll b) { a = (a + b) % MOD; }
void sub(ll &a, ll b) { a = (a + MOD - b) % MOD; }
void mul(ll &a, ll b) { a = a * (b % MOD) % MOD; }
// multiple dimensions vector template
// https://codeforces.com/blog/entry/76149
template <typename T, int D = 1>
struct vec : vector<vec<T, D - 1>> {
    template <typename... Args>
    vec(int n = 0, Args... args) : vector<vec<T, D - 1>>(n, vec<T, D - 1>(args...)) {}
};
template <typename T>
struct vec<T, 1> : vector<T> {
    vec(int n = 0, const T& val = T()) : vector<T>(n, val) {}
};
// python print() using parameter pack
// https://stackoverflow.com/a/25683817
template <class... T>
void print(T&&... n) {
    using exp = int[];
    exp{0, (cout << n << sp, 0)...};
    cout << endl;
}

//! <problem link>
//! <tags>

////////////////////////////////////////!
////////////////////////////////////////!
int main() {
    // assign standard input/output to file streams
    freopen(TASK".inp", "r", stdin);
    #ifndef LOCAL
        freopen(TASK".out", "w", stdout);
    #endif
    // desync cin from cout and C++ from C input
    cin.tie(0)->sync_with_stdio(0); // new and shorter version
    ////////////////////!
    
    
    
    
    ////////////////////!
    // for good measure :)
    // return 0+0-0*0/~0&0|0^0;
    return 0;
}
