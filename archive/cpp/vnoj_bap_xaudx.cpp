#undef _GLIBCXX_DEBUG
#pragma GCC optimize("Ofast,unroll-loops,inline")
#pragma GCC target("avx,avx2,f16c,fma,sse3,ssse3,sse4,sse4.1,sse4.2")
//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
#define nl '\n'
#define sp(n) fixed << showpoint << setpreciscion(n)

// hhttps://oj.vnoi.info/problem/nan_xaudx
// strings, map

///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //ifstream cin("ucode_chuoihople.inp");
    //ofstream cout("ucode_chuoihople.out");
    string a;
    cin >> a;
    unordered_map<char, int> chr_cnt;
    for (char c : a) {
        chr_cnt[c]++;
    };
    int cnt = 0;
    for (auto i : chr_cnt) {
        if (i.second % 2 == 1)
            cnt++;
    };
    if (cnt <= 1) {
        cout << 0;
    } else {
        cout << cnt - 1;
    };
}