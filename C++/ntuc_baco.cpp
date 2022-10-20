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

// http://ntucoder.net/Problem/Details/5
// 2d

// messy and unnecessary but it works, so... :D
///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init_ifs();
    /////////////////
    int tc = 1;
    //cin >> tc;
    while (tc--) {
        vector<vector<bool>> a(8, vector<bool> (8));
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--;
        y1--;
        x2--;
        y2--;
        for (int i = 0; i < 8; i++) {
            a[i][y1] = true;
        };
        for (int i = 0; i < 8; i++) {
            a[x1][i] = true;
        };
        int cnt = 8 * 2 - 1;
        // top left
        for (int i = x2, j = y2; (i >= 0) && (j >= 0); i--, j--) {
            if (!a[i][j]) cnt++;
            a[i][j] = true;
        };
        // bottom left
        for (int i = x2, j = y2; (i < 8) && (j >= 0); i++, j--) {
            if (!a[i][j]) cnt++;
            a[i][j] = true;
        };
        // top right
        for (int i = x2, j = y2; (i >= 0) && (j < 8); i--, j++) {
            if (!a[i][j]) cnt++;
            a[i][j] = true;
        };
        // bottom right
        for (int i = x2, j = y2; (i < 8) && (j < 8); i++, j++) {
            if (!a[i][j]) cnt++;
            a[i][j] = true;
        };
        cout << cnt;
        /////////////////
        cout << nl;
    };
    return 0;
};