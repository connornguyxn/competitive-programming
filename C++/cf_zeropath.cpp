#undef _GLIBCXX_DEBUG
#pragma GCC optimize("Ofast,unroll-loops,inline")
#pragma GCC target("avx,avx2,f16c,fma,sse3,ssse3,sse4,sse4.1,sse4.2")
#include <bits/stdc++.h>
#include "helper/debug.h"
using namespace std;
#define ll long long
#define ld long double
#define max_size 100000
#define nl cout << '\n'
#define sp ' '
#define dec_point(n) fixed << showpoint << setpreciscion(n)
#define mp_optimize(mp) mp.reserve(4096); mp.max_load_factor(0.1);

// https://codeforces.com/contest/1695/problem/C
// dp, brute force

///////////////////////////////////////
int n, m;
array<array<int, 1000>, 1000> a, dp;
///////////////////////////////////////
bool can_sum(int x, int y, int s) {
    s += a[x][y];
    if (x == n - 1 && y == m - 1) {
        cout << "with " << n << sp << m;
        nl;
        cout << (s == 0) << " at base case " << x << sp << y << " with s = " << s;
        nl;
        return s == 0;
    }
    if (x < n - 1) return can_sum(x + 1, y, s);
    if (y < m - 1) return can_sum(x, y + 1, s);
    cout << "False at case " << x << sp << y << " due to unknown";
    nl;
    return false;
}
///////////////////////////////////////
void solve() {
    ifstream cin("cf_zeropath.inp");
    //ofstream cout("cf_zeropath.out");
    /////////////////
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            //cout << a[i][j] << sp;
            dp[i][j] = -1;
        };
        //nl;
    };
    string res = (can_sum(0, 0, 0)) ? "YES" : "NO";
    cout << res;
    nl;
}
///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    };
    return 0;
}