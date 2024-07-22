#ifdef local_debug
#include "include/debugging.h"
#define log(...) logger(#__VA_ARGS__, __VA_ARGS__)
#define init_ifstream() ifstream cin("_input.inp")
#define init_ofstream() ofstream cout("_output.out")
#else
#pragma GCC optimize("O3,unroll-loops,inline")
#pragma GCC target("avx,avx2,f16c,fma,sse3,ssse3,sse4,sse4.1,sse4.2")
#include <bits/stdc++.h>
#define log(...)
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
#define dec_point(n) fixed << showpoint << setpreciscion(n)
#define mp_optimize(mp) mp.reserve(4096); mp.max_load_factor(0.1);
#define for_in(a) for (auto& i : a)
const ull MOD = 1e9 + 7;

// https://oj.vnoi.info/problem/fct025_dance
// searching

///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init_ifstream();
    //init_ofstream();
    int t = 1;
    //cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> m, f;
        int a;
        for (int i = 0; i < n; i++) {
            cin >> a;
            if (a > 0) {
                m.push_back(a);
            } else {
                f.push_back(abs(a));
            };
        };
        sort(m.begin(), m.end());
        sort(f.begin(), f.end());
        log(m);
        log(f);
        int cnt = 0;
        for_in(m){
            log(i);
            int l = lower_bound(f.begin(), f.end(), i - k) - f.begin();
            int r = upper_bound(f.begin(), f.end(), i) - f.begin();
            l %= n; // reset count to 0 if not found
            log(l, r);
            cnt += r - l;
        };
        cout << cnt;
        /////////////////
        cout << nl;
    };
    return 0;
}