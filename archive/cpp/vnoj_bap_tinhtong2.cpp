#undef _GLIBCXX_DEBUG
#pragma GCC optimize("Ofast,unroll-loops,inline")
#pragma GCC target("avx,avx2,f16c,fma,sse3,ssse3,sse4,sse4.1,sse4.2")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define max_size 100000
#define nl '\n'
#define sp(n) fixed << showpoint << setpreciscion(n)

// https://oj.vnoi.info/problem/bap_tinhtong2
// math

///////////////////////////////////////
unsigned ll calc(int n) {
    unsigned ll s = 0;
    for (int i = 1; i <= n; i++) {
        s += (i + 1) * i / 2;
    };
    return s;
}
///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //ifstream cin("vnoj_bap_tinhtong2.inp");
    //ofstream cout("vnoj_bap_tinhtong2.out");
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        cout << calc(n) << nl;
    }
}