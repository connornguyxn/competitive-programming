#ifdef local_debug
#include "include/debugging.h"
#define log(...) logger(#__VA_ARGS__, __VA_ARGS__)
#else
#pragma GCC optimize("O3,unroll-loops,inline")
#pragma GCC target("avx,avx2,f16c,fma,sse3,ssse3,sse4,sse4.1,sse4.2")
#include <bits/stdc++.h>
#define log(...)
#endif
using namespace std;
#define ll long long
#define ull unsigned long long
#define ld long double
#define str string
#define nl '\n'
#define sp ' '
#define dec_point(n) fixed << showpoint << setpreciscion(n)
#define mp_optimize(mp) mp.reserve(4096); mp.max_load_factor(0.1);
#define for_in(a) for (auto& i : a)
const ull MOD = 1e9 + 7;

// https://oj.vnoi.info/problem/fct033_absmax
// math

///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream cin("_input.inp");
    //ofstream cout("_output.out");
    int t = 1;
    //cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll a;
        cin >> a;
        ll mx1 = a, mx2 = a, mn1 = a, mn2 = a;
        for (int i = 0; i < n - 1; i++) {
            cin >> a;
            if (a >= mx1) {
                mx2 = mx1;
                mx1 = a;
            } else if (a > mx2) {
                mx2 = a;
            };
            if (a <= mn1) {
                mn2 = mn1;
                mn1 = a;
            } else if (a < mn2) {
                mn2 = a;
            };
        };
        log(mx1, mx2, mn1, mn2);
        cout << max(abs(mx1 + mx2), abs(mn1 + mn2));
        /////////////////
        cout << nl;
    };
    return 0;
}