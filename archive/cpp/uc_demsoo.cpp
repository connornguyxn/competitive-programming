#undef _GLIBCXX_DEBUG
#pragma GCC optimize("Ofast,unroll-loops,inline")
#pragma GCC target("avx,avx2,f16c,fma,sse3,ssse3,sse4,sse4.1,sse4.2")
#include <bits/stdc++.h>
//#include "helper/debug.h"
using namespace std;
#define ll long long
#define ld long double
#define max_size 100000
#define nl '\n'
#define sp ' '
#define dec_point(n) fixed << showpoint << setpreciscion(n)
///////////////////////////////////////

// https://ucode.vn/problems/117657
// backtracking

///////////////////////////////////////
int h, w;
vector<vector<char>> m(100, vector<char> (100));
///////////////////////////////////////
int count(int x, int y) {
    //cout << x << sp << y << endl;
    if (x + 1 > h || y + 1 > w) return 0;
    //cout << m[x][y] << endl;
    if (m[x][y] == '#') return 0;
    return max(count(x + 1, y), count(x, y + 1)) + 1;
};
///////////////////////////////////////
int main() {
    ifstream cin("ucode_demsoo.inp");
    //ofstream cout("ucode_demsoo.out");
    ios_base::sync_with_stdio(false);
    cin >> h >> w;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> m[i][j];
        };
    };
    cout << count(0, 0);
}