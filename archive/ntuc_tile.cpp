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

// http://ntucoder.net/Problem/Details/3323
// math

///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init_ifs();
    int t = 1;
    //cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        };
        sort(a.begin(), a.end(), [](int a, int b) { return a > b; });
        int mn = a[0], cnt = 1;
        for (int i = 1; (i < n) && (mn > 0); i++) {
            cnt++;
            mn--;
            if (a[i] < mn) {
                mn = a[i];
            };
        };
        cout << cnt;
        /////////////////
        cout << nl;
    };
    return 0;
}