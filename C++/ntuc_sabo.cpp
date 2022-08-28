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
const ull MOD = 1e6;

// http://ntucoder.net/Problem/Details/74
// dp

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
        vector<vector<ll>> dp(2, vector<ll> (n + 1));
        // set 2 first row to 1
        dp[0][1] = dp[1][1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[0][i] = (dp[0][i - 1] + dp[1][i - 1]) % MOD;
            if (i <= k) {
                dp[1][i] = 1;
            } else {
                dp[1][i] = dp[0][i - k];
            };
        };

        // for (int i = 0; i <= 1; i++) {
        //     for (int j = 0; j <= n; j++) {
        //         cout << dp[i][j] << sp;
        //     };
        //     cout << nl;
        // };
        cout << (dp[0][n] + dp[1][n]) % MOD;
        /////////////////
        cout << nl;
    };
    return 0;
};