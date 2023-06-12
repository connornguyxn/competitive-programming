// note: include headers *after* compile options
#if DEBUG // if debug flag is set to true
    #include "lib/include/debug.h" // include local debugging header
    // #pragma GCC optimize("trapv") // abort() on integer overflow, increases runtime
    // replaced wih a sanitizer instead, see tasks.json
    #define TASK "test" // define local task name
#else // if not on local machine
    // GCC optimization flags
    #pragma GCC optimize("O3,unroll-loops,inline") // safest optimizations
    // #pragma GCC optimize("Ofast,unroll-loops,inline") // faster but less accurate
    // SIMD optimization flags
    #include <bits/stdc++.h> // include everything
    #define TASK "<task name>" // define task name
#endif
using namespace std; // use standard namespace for faster access
// aliases
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define str string // python :D
#define nl '\n' // saving time by not flushing buffer
#define sp ' '
// bit manipulation
#define mask(POS) (1ULL << (POS))
#define getbit(MASK, POS) ((MASK >> POS) & 1)
#define all(VAR) (VAR).begin(), (VAR).end() // iterator macro
const int N = 1e6; // common array limit
const ull MOD = 1e9 + 7; // common modulo
// maximum values for common data types
// builtin limit cannot be used when combining multiple max values
const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
//! directions = left, up, right, down, upper_l, upper_r, lower_r, lower_l
const int dx[8] = {0, -1, 0, 1, -1, -1, 1, 1};
const int dy[8] = {-1, 0, 1, 0, -1, 1, 1, -1};
template<typename tVar, typename tVal>
void mnmz(tVar &var, tVal val) { if (val < var) var = val; }
template<typename tVar, typename tVal>
void mxmz(tVar &var, tVal val) { if (val > var) var = val; }

//! <problem link>
//! <tags>

////////////////////////////////////////!
int main() {
    // file stream objects
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        //! freopen(TASK".out", "w", stdout);
    };
    // i/o optimization
    cin.tie(0) -> sync_with_stdio(0); // new and shorter version
    ////////////////!
    
    
    
    
    ////////////////!
    return 0; // for good measure :)
}