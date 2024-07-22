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

// https://oj.vnoi.info/problem/power
// math

///////////////////////////////////////
ll logn(ll n, ll a) {
    return log2(a) / log2(n);
};
///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init_ifs();
    /////////////////
    int tc = 1;
    cin >> tc;
    for (int test = 1; test <= tc; test++) {
        cout << "Case #" << test << ": ";
        ll l, r;
        cin >> l >> r;
        ll p;
        for (int i = logn(2, r); i >= 1; i--) {
            
        };
        /////////////////
        cout << nl;
    };
    return 0;
};