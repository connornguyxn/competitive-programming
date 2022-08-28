
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
#define for_to(l, r) for (int i = l; i <= r; i++)
#define fm(val) "["#val" = "<<(val)<<"] "
// #define flog(val) clog << val << flush
// #define flogln(val) clog << val << endl
const ull MOD = 1e9 + 7;

// https://oj.vnoi.info/problem/vnoicup22_r3_b
// stack

///////////////////////////////////////
str s;
///////////////////////////////////////
int solve(int l, int r) {
    //cout << fm(l) << fm(r) << nl;
    int cnt = 0;
    bool ck = false;
    for_to(l - 1, r - 1) {
        if (s[i] == '(') {
            ck = true;
        } else {
            if (ck) {
                cnt++;
                //cout << fm(i);
                ck = false;
            };
        };
    };
    return cnt;
}
///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream cin("vnoj_xoachuoingoac.inp");
    //ofstream cout("vnoj_xoachuoingoac.out");
    // ofstream clog("vnoj_xoachuoingoac.log");
    int t = 1;
    cin >> t >> t;
    cin >> s;
    //cout << fm(s) << nl;
    while (t--) {
        int l, r;
        cin >> l >> r;
        cout << solve(l, r); // 0based index
endc:
        cout << nl;
    };
    return 0;
}