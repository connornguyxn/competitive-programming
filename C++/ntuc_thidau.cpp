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

// http://ntucoder.net/Problem/Details/2250
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
        vector<ll> a(n + 1), v(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        };
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
        };
        vector<vector<ll>> dp(n + 1, vector<ll> (366, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 365; j++) {
                if (a[i] > j) {
                    dp[i][j] = dp[i - 1][j];
                    continue;
                };
                ll last;
                if (a[i] < k) {
                    last = 0;
                } else {
                    last = dp[i - 1][a[i] - k];
                };
                dp[i][j] = max(dp[i - 1][j], last + v[i]);
            };
        };
        //vdb(dp);
        cout << dp[n][365];
        /////////////////
        cout << nl;
    };
    return 0;
};