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

// http://ntucoder.net/Problem/Details/5678
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
        int k, n;
        cin >> k >> n;
        vector<vector<int>> a(k + 1, vector<int> (n + 1));
        for (int i = 1; i <= k; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> a[i][j];
            };
        };
        vector<vector<int>> dp(k + 1, vector<int> (n + 1, 0));
        for (int i = 1; i <= k; i++) {
            for (int j = i; j <= n; j++) {
                dp[i][j] = max(dp[i][j - 1],
                                dp[i - 1][j - 1] + a[i][j]);
            };
        };
        cout << dp[k][n];
        /////////////////
        cout << nl;
    };
    return 0;
};