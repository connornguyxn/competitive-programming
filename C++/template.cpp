// #pragma GCC optimize("trapv") // abort() on integer overflow
                                // increase runtime by ~10%(?)
// note: include headers *after* compile options
#ifdef local_debug // if local debug flag is set
#include "helper/debugging.h" // include local debugging header
#else // if not on local machine
// GCC optimization flags
#pragma GCC optimize("O3,unroll-loops,inline")
// SIMD optimization
#pragma GCC target("avx,avx2,f16c,fma,sse3,ssse3,sse4,sse4.1,sse4.2")
#include <bits/stdc++.h> // include everything
#endif // end
using namespace std; // use standard namespace for faster access
// aliases
#define ll long long // -(2^63) to (2^63)-1 (approx -1e18 to 1e18)
#define ull unsigned long long // 0 to approx 1e19
#define ld long double // -1e308 to 1e308
#define str string // python :D
#define nl '\n' // saving time by not flushing buffer
#define sp ' ' // writing this is faster
// macro for functions
// set decimal precision
#define dec_point(n) fixed << showpoint << setpreciscion(n)
// dynamic container optimization, eg: map, vector
#define mp_optimize(mp) mp.reserve(4096); mp.max_load_factor(0.1);
#define for_in(a) for (auto& i : a) // python :D
#define fm(val) "["#val" = "<<(val)<<"] " // format output
// #define flog(val) clog << val << flush;
// #define flogln(val) clog << val << endl;
const ull MOD = 1e9 + 7; // common modular

// <problem link>
// <tags>

///////////////////////////////////////
int main() {
    // i/o optimization
    ios_base::sync_with_stdio(false); // desyncronize standard c and c++ streams
    cin.tie(nullptr); // turn off automatic output flushing
    // file stream objects
    //ifstream cin("template.inp");
    //ofstream cout("template.out");
    // ofstream clog("template.log");
    // test case handler
    int t = 1;
    //cin >> t;
    while (t--) {
        // code goes here
        
        /////////////////
        cout << nl;
    };
    return 0; // for good measure :)
}
// refer to ascii_art.txt
// *removed due to space constraints
