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

// <problem link>
// <tags>

///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init_ifstream();
    //init_ofstream();
    int t = 1;
    //cin >> t;
    while (t--) {
        int n;
        cin >> n;
        // designed to be extensible :)
        int k = 3;

        vector<vector<int>> dp(n + 1, vector<int> (k, 0));
        vector<int> h(k);

        // for each day
        for (int i = 1; i <= n; i++) {
            // for each action in current day
            for (int j = 0; j < k; j++) {
                cin >> h[j];
                // for each action in previous day
                for (int l = 0; l < k; l++) {
                    // if not similar action
                    if (l != j) {
                        // find current day max value for this action
                        dp[i][j] = max(dp[i][j], dp[i - 1][l] + h[j]);
                    };
                };
            };
        };
        int mx = 0;
        // find max value for each action in last day
        for (int i = 0; i < k; i++) {
            mx = max(mx, dp[n][i]);
        };
        cout << mx;
        /////////////////
        cout << nl;
    };
    return 0;
}