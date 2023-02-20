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

// http://ntucoder.net/Problem/Details/52
// recursion

vector<vector<int>> a(20, vector<int> (20));
int n, m;
///////////////////////////////////////
bool solve(int x, int y, int k = 0, str p = "") {
    if ((x == n - 1) && (y == n - 1)) {
        if (k == -1) {
            cout << p;
            return true;
        };
        return false;
    };
    if (k == 0) {
        k = a[x][y];
    } else if (a[x][y] != k) {
        k = -2;
    };
    str res;
    if (x < n) {
        res = p + to_string(x + 1) + sp + to_string(y) + nl;
        if (solve(x + 1, y, k, res)) return true;
    };
    if (y < m) {
        res = p + to_string(x) + sp + to_string(y + 1) + nl;
        if (solve(x, y + 1, k, res)) return true;
    };
    return false;
}
///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init_ifs();
    /////////////////
    int tc = 1;
    //cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            };
        };
        if (!solve(0, 0)) {
            cout << -1;
        };
        /////////////////
        cout << nl;
    };
    return 0;
};