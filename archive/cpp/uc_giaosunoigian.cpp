#undef _GLIBCXX_DEBUG
#pragma GCC optimize("Ofast,unroll-loops,inline")
#pragma GCC target("avx,avx2,f16c,fma,sse3,ssse3,sse4,sse4.1,sse4.2")
//#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;
#define nl '\n'
#define sp(n) fixed << showpoint << setpreciscion(n)

// https://ucode.vn/problems/117602
// brute force

///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream cin("ucode_giaosunoigian.inp");
    //ofstream cout("ucode_giaosunoigian.out");
    int cases;
    cin >> cases;
    while (cases--) {
        int n, k;
        cin >> n >> k;
        int t;
        for (int i = 0; i < n; i++) {
            cin >> t;
            if (t > 0) {
                k--;
            };
            //cout << 'k' << k << nl;
        };
        if (k > 0) {
            cout << "YES";
        } else {
            cout << "NO";
        };
        cout << nl;
    };
}