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

// https://codeforces.com/contest/1701/problem/A
// easy

///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //ifstream cin("cf_grassfield.inp");
    //ofstream cout("cf_grassfield.out");
    int t = 1;
    cin >> t;
    while (t--) {
        int cnt = 0, a;
        for (int i = 0; i < 4; i++) {
            cin >> a;
            cnt += a;
        };
        if (cnt == 0) {
            cout << 0;
        } else if (cnt == 4) {
            cout << 2;
        } else {
            cout << 1;
        };
        /////////////////
        cout << nl;
    };
    return 0;
}