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

// https://ucode.vn/problems/117603
// <techniques used>

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
    int cnt = chr_cnt[a[0]];
    bool valid = true;
    for (auto i : chr_cnt) {
        if (i.second != cnt) {
            if ((i.second - cnt > 1 & i.second != 1) || !valid) {
                cout << "NO";
                return 0;
            };
            valid = false;
        };
    };
    cout << "YES";
}