// #pragma GCC optimize("O3") // safest optimization
// #pragma GCC target("sse4.2") // SIMD instruction optimization
#include "bits/stdc++.h" // include headers *after* compile options
using namespace std;
using ll = long long;
// using db = double;
using str = string;
using pii = pair<int, int>;
#define fi first
#define se second
#define nl '\n' // saving time by not flushing cout buffer
#define sp ' '
// #define DR(a) (*(a))
#define ALL(a) (a).begin(), (a).end()
// #define BMASK(i) (1LL << (i))
// #define BGET(n, i) (((n) >> (i)) & 1)
#define FOR1(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FOR2(i, l, r) for (int i = (l), _r = (r); i <= _r; i++)
#define FOR3(i, l, r, a1) for (int i = (r), _l = (l); i >= _l; i--)
#define OVERLOAD(a, b, c, d, e, ...) e
#define FOR(...) OVERLOAD(__VA_ARGS__, FOR3, FOR2, FOR1)(__VA_ARGS__)
#define FORIN(it, a) for (auto& it : a)
const ll MOD = 1e9 + 7;// common modulo
// maximum values for common data types
// INFINITY cannot be used when combining multiple max values
const int INF = 1e9 + 9;
const ll INFLL = 1e18 + 9;
// container printing: https://codeforces.com/blog/entry/68920
template <class Ch, class Tr, class C>
basic_ostream<Ch, Tr>& operator<<(basic_ostream<Ch, Tr>& cout, const C& a) {
    cout << "{ ";
    FORIN(it, a) cout << it << sp;
    return cout << "}";
}
// python print() using parameter pack: https://stackoverflow.com/a/25683817
template <class... T>
void print(T&&... n) {
    using e = int[];
    e{(cout << n << sp, 0)...};
    cout << endl;
}

//! <problem link>
//! <tags>

////////////////////////////////////////!
////////////////////////////////////////!
int main() {
    #define TASK "test"
    // assign standard input/output to file streams
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    // desync cin from cout and C++ from C input
    cin.tie(nullptr)->sync_with_stdio(false);
    // cout << fixed << setprecision(12); // set floating point precision
    ////////////////////////////////////////!
    
    
    
    
    ////////////////////////////////////////!
    // for good measure :)
    // return 0+0-0*0/~0&0|0^0;
    return 0;
}
