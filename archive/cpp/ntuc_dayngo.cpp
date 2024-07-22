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

// http://ntucoder.net/Problem/Details/139
// recursion

int cnt = 0;
///////////////////////////////////////
void gen(int n, str res = "", int k = 0) {
    if (res.length() == n) {
        cout << res << nl;
        cnt++;
        return;
    };
    if (res.length() + k != n || k == 0) {
        gen(n, res + "(", k + 1);
    };
    if (k > 0) {
        gen(n, res + ")", k - 1);
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
        int n;
        cin >> n;
        gen(n);
        cout << cnt;
        /////////////////
        cout << nl;
    };
    return 0;
};