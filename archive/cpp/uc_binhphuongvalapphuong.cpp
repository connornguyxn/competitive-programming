#undef _GLIBCXX_DEBUG
#pragma GCC optimize("O3,unroll-loops,inline")
#pragma GCC target("avx,avx2,f16c,fma,sse3,ssse3,sse4,sse4.1,sse4.2")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define max_size 100000
#define nl '\n'
#define sp ' '
#define dec_point(n) fixed << showpoint << setpreciscion(n)

// https://ucode.vn/problems/117669
// <techniques used>

///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream cin("ucode_binhphuongvalapphuong.inp");
    //ofstream cout("ucode_binhphuongvalapphuong.out");
    /////////////////
    int tests;
    cin >> tests;
    while (tests--) {
        int n;
        cin >> n;
        unordered_map<int, bool> cnt;
        for (int i = 1; i * i <= n; i++) {
            cnt[i * i] = true;
        };
        for (int i = 1; i * i * i <= n; i++) {
            cnt[i * i * i] = true;
        };
        cout << cnt.size() << nl;
    };
}