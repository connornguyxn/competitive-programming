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

// https://atcoder.jp/contests/dp/tasks/dp_a
// dp

///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //init_ofs();
    int t = 1;
    //cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        };
        vector<int> dp(LIM, INFINITY);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            // people make it simple, I make it komplikated :D
            for (int j = 1; j <= 2; j++) {
                if (i + j < n) {
                    dp[i + j] = min(dp[i + j], dp[i] + abs(a[i] - a[i + j]));
                };
            };
        };
        cout << dp[n - 1];
        /////////////////
        cout << nl;
    };
    return 0;
}