#ifdef local_debug
#include "include/debugging.h"
#define log(...) logger(#__VA_ARGS__, __VA_ARGS__)
#else
#pragma GCC optimize("O3,unroll-loops,inline")
#pragma GCC target("avx,avx2,f16c,fma,sse3,ssse3,sse4,sse4.1,sse4.2")
#include <bits/stdc++.h>
#define log(...)
#endif
using namespace std;
#define ll long long
#define ull unsigned long long
#define ld long double
#define str string
#define nl '\n'
#define sp ' '
#define dec_point(n) fixed << showpoint << setpreciscion(n)
#define mp_optimize(mp) mp.reserve(4096); mp.max_load_factor(0.1);
#define for_in(a) for (auto& i : a)
const ull MOD = 1e9 + 7;

// http://ntucoder.net/Problem/Details/2245
// math

///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init_ifstream();
    //init_ofstream();
    int t = 1;
    //cin >> t;
    while (t--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        // if not on same color
        if ((x1 + y1) % 2 != (x2 + y2) % 2) {
            cout << -1;
        } else {
            // distance of each axis
            int dx = abs(x1 - x2);
            int dy = abs(y1 - y2);
            if ((dx == dy) && (dx % 2 == 0)) {
                cout << dx / 2;
            } else if ((dx % 2 == 0) && (dy % 2 == 0)) {
                cout << dx / 2 + dy / 2;
            } else {
                cout << -1;
            }
        };
        ///////////////////////////////////////
        cout << nl;
    };
    return 0;
}