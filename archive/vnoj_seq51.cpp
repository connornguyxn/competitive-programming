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

// https://oj.vnoi.info/problem/fct020_seq51
// sliding_windows

///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //ifstream cin("vnoj_seq51.inp");
    //ofstream cout("vnoj_seq51.out");
    int t = 1;
    //cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a, mx = 0, len = 0;
        for (int i = 0; i < n; i++) {
            cin >> a;
            if (a >= len) {
                len++;
            } else {
                len = 1;
            };
            mx = max(mx, len);
        };
        cout << mx;
        /////////////////
        cout << nl;
    };
    return 0;
}