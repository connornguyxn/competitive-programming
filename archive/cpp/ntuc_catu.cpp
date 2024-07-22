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

// http://ntucoder.net/Problem/Details/1147
// recursion

int n, m, mx = 0;
str mxr;
vector<int> w(100), v(100);
///////////////////////////////////////
void solve(int i = 0, int ws = 0, int vs = 0, str res = "") {
    vdb(res);
    if (ws > m) {
        return;
    };
    if (vs > mx) {
        vdb(res);
        mx = vs;
        mxr = res;
    };
    if (i == n) {
        return;
    };
    for (i; i < n; i++) {
        solve(i + 1, ws + w[i], vs + v[i], res + to_string(i + 1) + sp);
    };
}
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
            cin >> w[i] >> v[i];
        };
        solve();
        cout << mx << nl;
        if (mx != 0) {
            cout << mxr;
        };
        /////////////////
        cout << nl;
    };
    return 0;
};