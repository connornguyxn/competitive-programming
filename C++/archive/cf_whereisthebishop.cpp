#undef _GLIBCXX_DEBUG
#pragma GCC optimize("Ofast,unroll-loops,inline")
#pragma GCC target("avx,avx2,f16c,fma,sse3,ssse3,sse4,sse4.1,sse4.2")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define max_size 100000
#define nl '\n'
#define sp ' '
#define dec_point(n) fixed << showpoint << setpreciscion(n)

// <problem link>
// <techniques used>

///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //ifstream cin("cf_whereisthebishop.inp");
    //ofstream cout("cf_whereisthebishop.out");
    /////////////////
        int t;
    cin >> t;
    while (t--) {
        vector<vector<char>> a(8, vector<char> (8)); 
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                cin >> a[i][j];
            };
        };
        int r, c;
        for (int i = 1; i < 7; i++) {
            for (int j = 1; j < 7; j++) {
                if (a[i][j] == '#' &&
                    a[i + 1][j + 1] == '#' &&
                    a[i - 1][j - 1] == '#' &&
                    a[i + 1][j - 1] == '#' &&
                    a[i - 1][j + 1] == '#')
                {
                    r = i + 1;
                    c = j + 1;
                    break;
                }
            };
        };
        cout << r << sp << c << nl;
}