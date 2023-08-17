// note: include headers *after* compile options
#if DEBUG // if debug flag is set to true
    #include "lib/include/debug.h" // include local debugging header
    // #pragma GCC optimize("trapv") // abort() on integer overflow, increases runtime
    // replaced with a sanitizer instead, see tasks.json
    #define TASK "test" // define local task name
#else
    // GCC optimization flags
    #pragma GCC optimize("O3,unroll-loops") // safest optimizations
    #pragma GCC target("sse4.2") // SIMD instruction optimization
    #include <bits/stdc++.h> // include everything
    #define TASK "<task name>" // define task name
#endif
//
//* aliases
using namespace std; // use standard namespace for faster access
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define str string // python :D
#define nl '\n' // saving time by not flushing buffer
#define sp ' '
#define all(var) (var).begin(), (var).end()
//* functions and macros
// functions with "d" suffix runs in reverse("d" = "decrease")
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; i++) // repeat from 0 to n - 1
#define Repd(i, n) for (int i = (n); i--; )
#define For(i, l, r) for (int i = (l), _r = (r); i < _r; i++) // for l to r - 1
#define Ford(i, r, l) for (int i = (r), _l = (l); --i >= _l; )
#define Fore(i, l, r) for (int i = (l), _r = (r); i <= _r; i++) // for l to r
#define Forde(i, r, l) for (int i = (r) + 1, _l = (l); --i >= _l; )
#define Forin(it, var) for (auto it : var)
// bitwise macros
#define Bmask(i) (1ULL << (i)) // bitmask
#define Bget(mask, i) ((mask >> (i)) & 1) // get bit of mask
#define Blog(n) (63 - __builtin_clzll(n)) // constant-time log2
// python input()
template <class T = int>
T inp() { T x; cin >> x; return x; }
// python print() using parameter pack
// https://stackoverflow.com/a/25683817
template <typename... T>
void print(T&&... n) {
    using exp = int[];
    exp{0, (cout << n << sp, 0)...};
    cout << nl;
}
template <class T>
void mxmz(T &a, T b) { a = max(a, b); }
template <class T>
void mnmz(T &a, T b) { a = max(a, b); }
//* common constants
const int N = 1e6; // array limit
const ll MOD = 1e9 + 7; // common modulo
// maximum values for common data types
// INFINITY cannot be used when combining multiple max values
const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
// directions = left, up, right, down, upper_l, upper_r, lower_r, lower_l
const int dx[8] = {0, -1, 0, 1, -1, -1, 1, 1};
const int dy[8] = {-1, 0, 1, 0, -1, 1, 1, -1};

//! <problem link>
//! <tags>

////////////////////////////////////////!
int main() {
    // assign standard input/output to file streams
    freopen(TASK".inp", "r", stdin);
    //! freopen(TASK".out", "w", stdout);
    // desync cin from cout and C++ from C input
    cin.tie(0)->sync_with_stdio(0); // new and shorter version
    ////////////////!
    
    
    
    
    ////////////////!
    // for good measure :)
    // return 0+0-0*0/~0&0|0^0;
    return 0;
}
