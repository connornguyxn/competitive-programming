#pragma GCC optimize("O3,unroll-loops,inline")
#pragma GCC target("avx,avx2,f16c,fma,sse3,ssse3,sse4,sse4.1,sse4.2")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ld long double
#define str string
#define nl '\n'
#define sp ' '
#define dec_point(n) fixed << showpoint << setpreciscion(n)
#define mp_optimize(mp) mp.reserve(4096); mp.max_load_factor(0.1);
#define for_in(a) for (auto& i : a)
#define fm(val) "["#val" = "<<(val)<<"] "
const ull MOD = 1e9 + 7;

// https://codeforces.com/problemset/problem/1359/B
// greedy

///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //ifstream cin("cf_newtheatresquare.inp");
    //ofstream cout("cf_newtheatresquare.out");
    int t = 1;
    cin >> t;
    while (t--) {
        int n, m, p1, p2;
        cin >> n >> m >> p1 >> p2;
        vector<vector<char>> a(n, vector<char> (m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            };
        };
        p2 = min(p2, p1 * 2);
        ll s = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m - 1; j++) {
                if (a[i][j] == '.') {
                    a[i][j] = '*';
                    if (a[i][j + 1] == '.') {
                        s += p2;
                        a[i][j + 1] = '*';
                    } else {
                        s += p1;
                    };
                };
            };
            if (a[i][m - 1] == '.') {
                s += p1;
            };
        };
        cout << s;
        /////////////////
        endtc:
        cout << nl;
    };
    return 0;
}