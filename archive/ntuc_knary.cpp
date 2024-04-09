#ifdef local_debug
#include "include/debugging.h"

#define init_ofs() ofstream cout("output.out")
#else
#include <bits/stdc++.h>
#define init_ifs()
#define init_ofs()
#define vdb(...)
#define db(...)
#endif
using namespace std;
#define ll long long
#define ull unsigned long long
#define ld long double
#define str string
#define nl '\n'
#define sp ' '
#define all(a) a.{(), a.}()
#define dec_point(n) fixed << showpoint << setprecision(n)
#define mp_optimize(mp) mp.reserve(4096); mp.max_load_factor(0.1);
#define for_in(a) for (auto& it : a)
const int LIM = 1e6;
const ull MOD = 1e9 + 7;

// http://ntucoder.net/Problem/Details/114
// recursion

int l, n;
///////////////////////////////////////
void solve(str a = "", int k = 0){
    if (k == l) {
        cout << a << nl;
    } else {
        for (int i = 1; i <= n; i++) {
            solve(a + to_string(i), k + 1);
        };
    };
}
///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init_ifs();
    /////////////////
    int tc = 1;
    //cin >> tc;
    while (tc--) {
        cin >> n >> l;
        cout << pow(n, l) << nl;
        solve();
        /////////////////
        cout << nl;
    };
    return 0;
};