#ifdef local_debug
#include "include/debugging.h"
#define init_ifs() ifstream cin("input.inp")
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

// http://ntucoder.net/Problem/Details/3364
// string (hashmap)

///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init_ifs();
    /////////////////
    int tc = 1;
    //cin >> tc;
    while (tc--) {
        unordered_map<char, int> v;
        v['I'] = 1;
        v['V'] = 5;
        v['X'] = 10;
        v['L'] = 50;
        v['C'] = 100;
        v['D'] = 500;
        v['M'] = 1000;
        str a;
        cin >> a;
        ll s = 0;
        for (int i = 0; i < a.length(); i++) {
            if (v[a[i]] < v[a[i + 1]]) {
                s -= v[a[i]];
            } else {
                s += v[a[i]];
            };
        };
        cout << s;
        /////////////////
        cout << nl;
    };
    return 0;
};