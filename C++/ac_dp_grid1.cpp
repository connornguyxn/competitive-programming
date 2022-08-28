#ifdef local_debug
#include "include/debugging.h"
#else
#include <bits/stdc++.h>
#define vdb(...)
#define db(...)
#define init_ifstream()
#define init_ofstream()
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
#define for_in(a) for (auto& i : a)
const int LIM = 1e6;
const ull MOD = 1e9 + 7;

// https://atcoder.jp/contests/dp/tasks/dp_h
// dp

///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init_ifstream();
    //init_ofstream();
    int t = 1;
    //cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> a(n, vector<char> (m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            };
        };
        vector<vector<ll>> dp(n, vector<ll> (m));
        dp[0][0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == '.') {
                    // a bit dirty but it does the job :v
                    if(i > 0) {
                        dp[i][j] = dp[i - 1][j];
                    };
                    if(j > 0) {
                        dp[i][j] += dp[i][j - 1];
                    };
                    dp[i][j] %= MOD;
                } else {
                    dp[i][j] = 0;
                };
            };
        };
        cout << dp[n - 1][m - 1] % MOD;
        /////////////////
        cout << nl;
    };
    return 0;
}