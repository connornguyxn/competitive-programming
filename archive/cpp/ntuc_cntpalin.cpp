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
ll genmax(ll pref, int l) {
    str s = to_string(pref);
    if (l % 2 == 1) {
        s = s.substr(0, s.size() - 1);
    };
    for (int i = s.length() - 1; i >= 0 ; i--) {
        pref = pref * 10 + (s[i] - 48);
    };
    //vdb(pref);
    return pref;
}
///////////////////////////////////////
ll cntpalin (ll num) {
    // took to long to find this :D
    if (num < 0) {
        return 0;
    };
    int n = to_string(num).length();
    ll pref = num;
    // get prefix
    for (int i = 0; i < n - (n + 1) / 2; i++) {
        pref /= 10;
    };
    // subtract 1 from result if prefix palin is greater than num
    //vdb(genmax(pref), num);
    if (genmax(pref, n) > num) {
        pref--;
    };
    // each val of prefix = 2 state: with or without pivot
    pref *= 2;
    // adjust result for 2 state:
    // if odd: result is larger than number due to pivot
    if (n % 2 == 1) {
        // subtract to adjust
        int adj = 1;
        for (int i = 1; i < (n + 1) / 2; i++) {
            adj *= 10;
        };
        pref -= pref / 2 - adj + 1;
    } else { // if even: result is snaller than number due to missing pivot
        // add to adjust
        int adj = 1;
        for (int i = 0; i < (n + 1) / 2; i++) {
            adj *= 10;
        };
        pref += adj - 1 - pref / 2;
    };
    // +1 for 0
    pref++;
    return pref;
}
///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init_ifs();
    int t = 1;
    cin >> t;
    while (t--) {
        ll l, r;
        cin >> l >> r;
        if (r < l) {
            swap(l, r);
        };
        //cout << genmax(1);
        cout << cntpalin(r) - cntpalin(l - 1);
        /////////////////
        cout << nl;
    };
    return 0;
}