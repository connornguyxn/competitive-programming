#undef _GLIBCXX_DEBUG
#pragma GCC optimize("Ofast,unroll-loops,inline")
#pragma GCC target("avx,avx2,f16c,fma,sse3,ssse3,sse4,sse4.1,sse4.2")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define max_size 100000
#define nl cout << '\n'
#define sp ' '
#define dec_point(n) fixed << showpoint << setpreciscion(n)
#define mp_optimize(mp) mp.reserve(4096); mp.max_load_factor(0.1);

// https://codeforces.com/contest/1695/problem/A
// <techniques used>

///////////////////////////////////////
void solve() {
    //ifstream cin("cf_subrectangle_guess.inp");
    //ofstream cout("cf_subrectangle_guess.out");
    /////////////////   
    int n, m;
    cin >> n >> m;
    int area = INT_MAX, mx = INT_MIN;
    int a;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a;
            if (a > mx || (a = mx && max(n - i, i + 1) * max(m - j, j + 1) < area)) {
                area = max(n - i, i + 1) * max(m - j, j + 1);
                mx = a;
            };
        };
    };
    cout << area;
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