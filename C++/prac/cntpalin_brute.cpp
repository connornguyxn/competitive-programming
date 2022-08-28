#ifdef local_debug
#include "../include/debugging.h"
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

// <problem link>
// <tags>

///////////////////////////////////////
bool ispalin(int n) {
    str s = to_string(n);
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != s[s.length() - 1 - i]) {
            return false;
        };
    };
    return true;
}
///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init_ifs();
    int t = 1;
    //cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        str s;
        int cnt = 0;
        for (int i = l; i <= r; i++) {
            if (ispalin(i)) {
                cnt++;
            };
        };
        cout << cnt;
        /////////////////
        cout << nl;
    };
    return 0;
}