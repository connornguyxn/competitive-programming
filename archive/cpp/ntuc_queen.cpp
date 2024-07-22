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

// http://ntucoder.net/Problem/Details/115
// recursion

///////////////////////////////////////
int x, y;
array<array<char, 8>, 8> a;
///////////////////////////////////////
bool safe(int x, int y) {
    // left
    for (int i = y - 1; i >= 0; i--){
        if (a[x][i] == 'w') return false;
    };
    // right
    for (int i = y + 1; i < 8; i++){
        if (a[x][i] == 'w') return false;
    };
    // top left
    for (int i = x, j = y; (i >= 0) && (j >= 0); i--, j--) {
        if (a[i][j] == 'w') return false;
    };
    // bottom left
    for (int i = x, j = y; (i < 8) && (j >= 0); i++, j--) {
        if (a[i][j] == 'w') return false;
    };
    // top right
    for (int i = x, j = y; (i >= 0) && (j < 8); i--, j++) {
        if (a[i][j] == 'w') return false;
    };
    // bottom right
    for (int i = x, j = y; (i < 8) && (j < 8); i++, j++) {
        if (a[i][j] == 'w') return false;
    };
    return true;
};
///////////////////////////////////////
bool solve(int yc = 0) {
    if (yc == 8) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                cout << a[i][j];
            };
            cout << nl;
        };
        return true;
    };
    if (yc == y) {
        if (solve(yc + 1)) {
            return true;
        };
    } else {
        for (int i = 0; i < 8; i++) {
            if (safe(i, yc)) {
                a[i][yc] = 'w';
                if (solve(yc + 1)) {
                    return true;
                };
                a[i][yc] = '.';
            };
        };
    };
    return false;
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
        cin >> x >> y;
        x--;
        y--;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                a[i][j] = '.';
            };
        };
        a[x][y] = 'w';
        solve();
        /////////////////
        cout << nl;
    };
    return 0;
};