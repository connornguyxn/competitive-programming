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

// http://ntucoder.net/Problem/Details/3350
// recursion

str a;
unordered_set<int> cnt;
///////////////////////////////////////
void gen(ull n, int s, int i, int ck) {
    if (i == a.length() && ck == 1 && s == 0) {
        return;
    };
    if (i == a.length()) {
        vdb(n, s, i, ck);
        if (s % 3 == 0) {
            cnt.insert(n);
        };
        return;
    };
    
    if (ck == 0) {
        gen(n, s, i + 1, 1);
        gen(n * 10 + (a[i] - '0'), s + (a[i] - '0'), i + 1, 0);
    } else if (ck == 1) {
        gen(n, s, i + 1, 1);
        gen(n * 10 + (a[i] - '0'), s + (a[i] - '0'), i + 1, 2);
    } else {
        gen(n * 10 + (a[i] - '0'), s + (a[i] - '0'), i + 1, 2);
    };
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
        cin >> a;
        gen(0, 0, 0, 0);
        vdb(cnt);
        cout << cnt.size();
        /////////////////
        cout << nl;
    };
    return 0;
};