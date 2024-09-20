#ifdef local_debug
#include "../include/debugging.h"

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
#define all(a) a.begin(), a.end()
#define dec_point(n) fixed << showpoint << setprecision(n)
#define mp_optimize(mp) mp.reserve(4096); mp.max_load_factor(0.1);
#define for_in(a) for (auto& it : a)
const int LIM = 1e6;
const ull MOD = 1e9 + 7;

// https://usaco.guide/silver/more-prefix-sums?lang=cpp
// Example implementation of a 2D prefix sum array
// 2d, prefsum

///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init_ifs();
    /////////////////
    int tc = 1;
    //cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        // using 1-indexed arrays
        vector<vector<int>> a(n + 1, vector<int> (n + 1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> a[i][j];
                // current = input + top + right - top_left
                a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
                cout << a[i][j] << sp;
            };
            cout << nl;
        };
        auto sum = [=](int xl, int yl, int xr, int yr) {
            ll res = a[xr][yr];
            res -= a[xl - 1][yr] + a[xr][yl - 1];
            res += a[xl - 1][yl - 1];
            return res;
        };
        cout << sum(1, 1, n, n);
        /////////////////
        cout << nl;
    };
    return 0;
};