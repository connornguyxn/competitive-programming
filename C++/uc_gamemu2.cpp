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

// https://ucode.vn/problems/117702
// <techniques used>

///////////////////////////////////////
ll gen_max(ll n) {
    ll res = 2;
    while (res < n) res *= 2;
    return res / 2;
}
///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //ifstream cin("ucode_gamemu2.inp");
    //ofstream cout("ucode_gamemu2.out");
    /////////////////
    ll n;
    cin >> n;
    int cnt = 0;
    ll mx;
    while (n != 1) {
        mx = gen_max(n);
        //cout << mx << endl;
        if (mx == n) {
            n /= 2;
        } else {
            n -= mx;
        };
        cnt++;
    };
    string res = (cnt / 2 == 0) ? "A" : "B";
    cout << "Ucoder" << res;
}