#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #pragma GCC optimize("O3,unroll-loops,inline")
    #include <bits/stdc++.h>
    #define TASK "nkpalin"
#endif
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define str string
#define nl '\n'
#define sp ' '
#define mask(POS) (1ULL << (POS))
#define getbit(MASK, POS) ((MASK >> POS) & 1)
#define all(VAR) (VAR).begin(), (VAR).end()
const int N = 1e6;
const ull MOD = 1e9 + 7;
template<typename tVar, typename tVal>
void mnmi(tVar &var, tVal val) { if (val < var) var = val; }
template<typename tVar, typename tVal>
void mxmi(tVar &var, tVal val) { if (val > var) var = val; }
const int offx[8] = {0, 0, -1, 1, -1, 1, -1, 1};
const int offy[8] = {1, -1, 0, 0, 1, 1, -1, -1};

// oj.vnoi.info/problem/nkpalin
// dp, strings, easy

////////////////////////////////////////
int main() {
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        // freopen(TASK".out", "w", stdout);
    };
    cin.tie(0) -> sync_with_stdio(0);
    ////////////////
    str a;
    cin >> a;
    int n = a.size();
    
    str b = a;
    reverse(all(b));
    // db(a, b);
    
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        };
    };
    
    str res = "";
    int i = n, j = n;
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            res += a[i - 1];
            i--;
            j--;
        }
        else {
            if (dp[i - 1][j] > dp[i][j - 1])
                i--;
            else
                j--;
        }
    };
    
    reverse(all(res));
    cout << res;
    ////////////////
    return 0;
}
/*
000000000000000000000000000000000000000000011111111100000000000000000000000000000000000000
0000000000000000000000000000000000001111.............1111111000000000000000000000000000000
00000000000000000000000000000000011.. .....11111111.........111000000000000000000000000000
000000000000000000000000000000011.  .1111111111111111111111.. .110000000000000000000000000
0000000000000000000000000000001. ..111111111111111111111111111. .1100000000000000000000000
000000000000000000000000000001. .111111111111111111111111111111. .110000000000000000000000
00000000000000000000000000001. .111111.............11111111111111. .1000000000000000000000
00000000000000000000000000001  111.   ..............   ...11111111. .100000000000000000000
0000000000000000000000000001. .11.  ..11111111111111111..  .1111111. .10000000000000000000
0000000000000000000000000001  111. ..11111111111111111111.  .1111111. .1000000000000000000
000000000000000000000000001. .111.  ..1111111111111111111.. .11111111. .100000000000000000
000000000000000000000000001. 11111.   ...11111111111111...  .11111111. .100000000000000000
000000000000000000000000011 .1111111..   ..............   .11111111111. 110000000000000000
00000000000000000000000001. .1111111111.................11111111111111. .10000000000000000
00000000000000000000000001 .1111111111111111111111111111111111111111111  10000000000000000
0000000000000000000000001. .1111111111111111111111111111111111111111111. .1000000000000000
0000000000000000000000001. 11111111111111111111111111111111111111111111. .1000000000000000
000000000000000000000001. .11111111111111111111111111111111111111111111. .1000000000000000
000000000000000000000001. .111111111111111111111111111111111111111111111 .1000000000000000
000000000000000000000011 .1111111111111111111111111111111111111111111111 .1000000000000000
00000000000000000000001. .1111111111111111111111111111111111111111111111. 1000000000000000
00000000000000000000001. 11111111111111111111111111111111111111111111111. 1000000000000000
0000000000000000000001. .11111111111111111111111111111111111111111111111. 1100000000000000
0000000000000000000001. .11111111111111111111111111111111111111111111111. 1100000000000000
0000000000000000000011 .111111111111111111111111111111111111111111111111. 1100000000000000
000000000000000000001. .111111111111111111111111111111111111111111111111. 1100000000000000
000000000000000000001 .1111111111111111111111111111111111111111111111111  1000000000000000
00000000000000000001. .1111111111111111111111111111111111111111111111111 .1000000000000000
00000000000000000001. 11111111111111111111.........11111111111111111111. .1000000000000000
0000000000000000001. .111111111111................... .1111111111111111. .1000000000000000
0000000000000000001. .111111111....111111111111111111. .111111111111111. .1000000000000000
0000000000000000011 .111111111. .100000000000000000001  111111111111111. .1000000000000000
000000111111111111. .111111111. .100000000000000000001  111111111111111. .1000000000000000
00111...............11111111111 .100000000000000000001 .111111111111111. .1000000000000000
001. ..111111111111111111111111. 110000000000000000001  111111111111111. .1000000000000000
001. 11111111111111111111111111. .10000000000000000001  111111111111111. .1000000000000000
001. .1111111111111111111111111. .10000000000000000001 .111111111111111. .1000000000000000
00011. ..11111111111111111111..  .1000000000111111111. .111111111111111 .10000000000000000
0000011.. ................. ...11100000111........... ..11111111111111. .10000000000000000
0000000111111...........111111000000011. ...11111111111111111111111111  110000000000000000
00000000000000000000000000000000000001. .111111111111111111111111111.  .100000000000000000
000000000000000000000000000000000000011. .11111111111111111111111.. ..11000000000000000000
00000000000000000000000000000000000000111.. ......111111111.... ...11000000000000000000000
00000000000000000000000000000000000000000111111...............1111000000000000000000000000
000000000000000000000000000000000000000000000000011111111111100000000000000000000000000000
*/