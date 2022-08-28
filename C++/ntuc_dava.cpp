#ifdef local_debug
#include "include/debugging.h"
#define init_ifs() ifstream cin("input.inp")
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

// http://ntucoder.net/Problem/Details/76
// 2d, prefixsum (fuck dp)

///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init_ifs();
    /////////////////
    int tc = 1;
    //cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<vector<ll>> a(n + 1, vector<ll> (n + 1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> a[i][j];
                a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
                //cout << a[i][j] << sp;
            };
            //cout << nl;
        };
        auto sum = [=](int xl, int yl, int xr, int yr) {
            ll res = a[xr][yr];
            res -= a[xl - 1][yr] + a[xr][yl - 1];
            res += a[xl - 1][yl - 1];
            return res;
        };
        ll mx = 0;
        for (int i = 1; i <= n - k + 1; i++) {
            for (int j = 1; j <= n - k + 1; j++) {
                //vdb(i, j, i + k - 1, j + k - 1);
                //vdb(sum(i, j, i + k - 1, j + k - 1));
                mx = max(mx, sum(i, j, i + k - 1, j + k - 1));
            };
        };
        cout << mx;
        /////////////////
        cout << nl;
    };
    return 0;
};