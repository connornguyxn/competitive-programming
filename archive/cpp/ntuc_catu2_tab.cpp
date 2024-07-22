#ifdef local_debug
#include "include/debugging.h"
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

// http://ntucoder.net/Problem/Details/1148
// dp (tab)
// https://www.youtube.com/watch?v=xCbYmUPvc2Q

///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init_ifs();
    /////////////////
    int tc = 1;
    //cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<ll> w(n + 1), v(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> w[i] >> v[i];
        };
        vector<vector<ll>> dp(n + 1, vector<ll> (m + 1));
        // for every item upto index i
        for (int i = 0; i <= n; i++) {
            // for each weight limit
            for (int j = 0; j <= m; j++) {
                // fill up base case with 0:
                // if no item to choose or limit = 0 then value = 0
                if ((i == 0) || (j == 0)) {
                    dp[i][j] = 0;
                    continue;
                };
                if (w[i] > j) { // if item larger than weight limit
                    // skip this item by keeping the previous value
                    dp[i][j] = dp[i - 1][j];
                    continue;
                };
                // current = max(skipping, choosing this item)
                dp[i][j] = max(
                    dp[i - 1][j], // previous value
                    // value of weight without item
                    // + value of current item
                    dp[i - 1][j - w[i]] + v[i]
                );
            };
        };
        // for (int i = 0; i <= n; i++) {
        //     for (int j = 0; j <= m; j++) {
        //         cout << dp[i][j] << sp;
        //     };
        //     cout << nl;
        // };
        // print out best case
        cout << dp[n][m] << nl;

        // print out the items we took
        int i = n, j = m;
        while (dp[i][j] != 0) {
            if (dp[i][j] == dp[i - 1][j - w[i]] + v[i]) {
                cout << i << sp;
                j -= w[i];
            };
            i--;
        };
        /////////////////
        cout << nl;
    };
    return 0;
};