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

// https://oj.vnoi.info/problem/fc132_exponential
// math, bruteforce

///////////////////////////////////////
int logn(int n, int a) {
    return log2(a) / log2(n);
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
        int n;
        cin >> n;
        int mx = 0;
        for (int i = 2; i <= sqrt(n); i++) {
            int a = pow(i, (int)logn(i, n));
            vdb(i, a, (int)logn(i, n));
            mx = max(mx, a);
        };
        db(logn(10, 1000));
        cout << mx;
        /////////////////
        cout << nl;
    };
    return 0;
};