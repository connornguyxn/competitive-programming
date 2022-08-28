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

// http://ntucoder.net/Problem/Details/4394
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
        int n;
        cin >> n;
        vector<pair<int, ll>> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i].second >> a[i].first;
        };
        sort(a.begin() + 1, a.end());
        vdb(a);
        int m = a.back().first; // maximum time
        vector<vector<ll>> dp(n + 1, vector<ll> (m + 1));
        for (int i = 1; i <= n; i++) {
            dp[i][0] = max(dp[i - 1][0], a[i].second);
            for (int j = 1; j <= a[i].first; j++) {
                dp[i][j] = max({
                    dp[i - 1][j],
                    dp[i][j - 1],
                    dp[i - 1][j - 1] + a[i].second
                });
            };
        };
        // after many stupid mistakes:
        // for (int i = 0; i <= n; i++) {
        //     for (int j = 0; j <= m; j++) {
        //         cout << dp[i][j] << sp;
        //     };
        //     cout << nl;
        // };
        cout << dp[n][m];
        /////////////////
        cout << nl;
    };
    return 0;
};
    