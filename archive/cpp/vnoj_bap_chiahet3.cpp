#undef _GLIBCXX_DEBUG
#pragma GCC optimize("O3,unroll-loops,inline")
#pragma GCC target("avx,avx2,f16c,fma,sse3,ssse3,sse4,sse4.1,sse4.2")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define max_size 100000
#define nl '\n'
#define sp(n) fixed << showpoint << setpreciscion(n)

// https://oj.vnoi.info/problem/nan_scrcb02
// <techniques used>

///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //ifstream cin("vnoj_bap_chiahet3.inp");
    //ofstream cout("vnoj_bap_chiahet3.out");
    ll a, b;
    cin >> a >> b;
    cout << b / 3 - (a - 1) / 3;
}