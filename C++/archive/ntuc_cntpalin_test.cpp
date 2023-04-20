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

// http://ntucoder.net/Problem/Details/5600
// math

///////////////////////////////////////
int to_int(char a) {
    return (a - 48);
}
///////////////////////////////////////
ll cnt(ll num) {
    str a = to_string(num);
    int n = a.length();
    ll cnt = 0;
    for (int i = 1; i <= n - 1; i++) {
        cnt += 9 * pow(10, (i / 2 - 1) + (i % 2));
    };
    vdb(cnt);
    int pivot = (n % 2 == 1) ? to_int(a[n / 2 - 1 + 1]) : 1;
    vdb(pivot);
    for (int i = 1; i <= n / 2 - 1; i++) {
        cnt += to_int(a[i - 1]) * pow(10, n / 2 - i) * pivot;
    };
    vdb(cnt);
    int l = to_int(a[n / 2 - 1]);
    int r = to_int(a[n / 2 + 1 + n % 2 - 1]);
    cnt += min(l, r) * pivot;
    return cnt;
}
///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init_ifs();
    int t = 1;
    //cin >> t;
    while (t--) {
        ll l, r;
        cin >> l >> r;
        cout << cnt(r);
        /////////////////
        cout << nl;
    };
    return 0;
}