#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #pragma GCC optimize("O3,unroll-loops,inline")
    #pragma GCC target("avx2")
    #include <bits/stdc++.h>
    #define db(...)
    #define TASK "latgach4"
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
#define bitcnt(MASK) __builtin_popcountull(MASK)
#define getbit(MASK, POS) ((MASK >> POS) & 1)
#define all(VAR) (VAR).begin(), (VAR).end()
#define point(CNT) fixed << showpoint << setprecision(CNT)
const int MAXN = 1e6;
const ull MOD = 111539786;

// https://oj.vnoi.info/problem/latgach4
// math, matrix, basic

struct Matrix {
    int nr, nc;
    vector<vector<ll>> x;
    
    Matrix(int _n_row, int _n_col) : nr(_n_row), nc(_n_col), x(_n_row, vector<ll>(_n_col)) {
        nr = _n_row;
        nc = _n_col;
    }
    
    Matrix operator*(Matrix other) {
        Matrix res(nr, nr);
        
        for (int i = 0; i < nr; i++) {
            for (int j = 0; j < other.nc; j++) {
                for (int k = 0; k < nc; k++) {
                    res.x[i][j] = res.x[i][j] + (x[i][k] * other.x[k][j] % MOD) % MOD;
                };
            };
        };
        
        return res;
    }
    
    Matrix& operator*=(Matrix other) {
        return *this = *this * other;
    }
    
    Matrix pow(ll k) {
        Matrix a = *this;
        Matrix res(nr, nr);
        for (int i = 0; i < nr; i++) res.x[i][i] = 1;
        
        while (k > 0) {
            if (k % 2) res *= a;
            a *= a;
            k /= 2;
        };
        
        return res;
    }
};
///////////////////////////////////////
int main() {
    // if (fopen(TASK".inp", "r")) freopen(TASK".inp", "r", stdin);
    if (fopen(TASK".out", "r")) freopen(TASK".out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(0);
    /////////////////
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        
        Matrix base(2, 2);
        base.x = {
            {0, 1},
            {1, 1}
        };
        
        base = base.pow(n);
        
        Matrix res(2, 2);
        res.x = {
            {0, 1},
            {1, 2}
        };
        
        res *= base;
        
        cout << res.x[0][1] << nl;
    };
    /////////////////
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