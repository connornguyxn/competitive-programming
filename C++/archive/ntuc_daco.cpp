#ifdef local_debug
#include "include/debugging.h"

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

// http://ntucoder.net/Problem/Details/78
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
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        };
        vector<vector<int>> dp(n);
        dp[0].push_back(a[0]);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if ((a[i] > a[j]) &&
                    (dp[j].size() + 1 > dp[i].size()))
                {
                    dp[i] = dp[j];
                };
            };
            dp[i].push_back(a[i]);
        };
        auto mx = dp[0];
        for_in(dp) {
            if (it.size() > mx.size()) {
                mx = it;
            };
        };
        cout << mx.size() << nl;
        for_in(mx) {
            cout << it << sp;
        };
        ////
        cout << nl;
    };
    return 0;
};