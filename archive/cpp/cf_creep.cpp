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

// https://codeforces.com/contest/1694/problem/A
// <techniques used>

///////////////////////////////////////
void solve() {
    //ifstream cin("cf_creep.inp");
    //ofstream cout("cf_creep.out");
    /////////////////
    int a, b;
    cin >> a >> b;
    for (int i = 0; i < min(a, b); i++) {
        cout << "10";
        a--;
        b--;
    };
    if (a > b) {
        for (int i = 0; i < a; i++) {
            cout << "0";
        };
    } else {
        for (int i = 0; i < b; i++) {
            cout << "1";
        };
    };
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