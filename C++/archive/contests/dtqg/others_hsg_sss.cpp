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
const int LIM = 1e5;
const ull MOD = 1e9 + 7;

// https://drive.google.com/file/d/1ZR1DWKL1IWg2DIH5dHlTDDr3Ijb7b3VR/view
// dp

int n, m;
vector<int> a(LIM);
unordered_set<int> mk;
vector<vector<int>> dp(LIM, vector<int> (LIM, -1));
///////////////////////////////////////
void solve(int i = 0, int s = 0) {
    if (i == n + 1) {
        return;
    };
    if (s > m) {
        return;
    };
    mk.insert(s);
    solve(i + 1, s);
    solve(i + 1, s + a[i]);
};
///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init_ifs();
    /////////////////
    int tc = 1;
    //cin >> tc;
    while (tc--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        };
        solve();
        cout << mk.size();
        /////////////////
        cout << nl;
    };
    return 0;
};