#undef _GLIBCXX_DEBUG
#pragma GCC optimize("Ofast,unroll-loops,inline")
#pragma GCC target("avx,avx2,f16c,fma,sse3,ssse3,sse4,sse4.1,sse4.2")
//#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
using namespace std;
#define ll long long
#define ld long double
#define max_size 100000
#define nl '\n'
#define sp(n) fixed << showpoint << setpreciscion(n)

// https://ucode.vn/problems/117626
// math, string

///////////////////////////////////////
int sumdigits(int n) {
    int s = 0;
    while (n) {
        s += n % 10;
        n /= 10;
    }
    return s;
}
///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //ifstream cin("ucode_uocsototnhat.inp");
    //ofstream cout("ucode_uocsototnhat.out");
    int n;
    cin >> n;
    int mx, si, smx = 0;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            //cout << i << " " << n / i << nl;
            si = sumdigits(i);
            if (si > smx) {
                smx = si;
                mx = i;
            } else if (si == smx && i < mx) {
                mx = i;
            };
            si = sumdigits(n / i);
            if (si > smx) {
                smx = si;
                mx = n / i;
            } else if (si == smx && n / i < mx) {
                mx = n / i;
            };
        };
    };
    cout << mx;
}