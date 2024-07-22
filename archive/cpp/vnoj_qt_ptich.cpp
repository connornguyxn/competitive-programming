#undef _GLIBCXX_DEBUG
#pragma GCC optimize("Ofast,unroll-loops,inline")
#pragma GCC target("avx,avx2,f16c,fma,sse3,ssse3,sse4,sse4.1,sse4.2")
//#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;
#define nl '\n'
#define sp(n) fixed << showpoint << setpreciscion(n)

// https://oj.vnoi.info/problem/qt_ptt
// <techniques used>
// <summary of how to solve the problem>

///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream cin("vnoj_qt_ptich.inp");
    //ofstream cout("vnoj_qt_ptich.out");
    int t;
    cin >> t;
    while (t--) {
        string n;
        cin >> n;
        int cnt = 0;
        string res = "";
        for (int i = 0; i < n.length(); i++) {
            if (n[i] != '0') {
                cnt++;
                res += n[i];
                for (int j = 1; j <= n.length() - (i + 1); j++) {
                    res += "0";
                };
                res += ' ';
            };
        };
        cout << cnt << nl;
        cout << res << nl;
    };
}