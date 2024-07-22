#undef _GLIBCXX_DEBUG
#pragma GCC optimize("Ofast,unroll-loops,inline")
#pragma GCC target("avx,avx2,f16c,fma,sse3,ssse3,sse4,sse4.1,sse4.2")
//#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
#define nl '\n'

// https://ucode.vn/problems/117594
// brute force

///////////////////////////////////////
int cross_size(vector<string> a, int x, int y) {
    int s = 1;
    int i = 1;
    //cout << "x" << x << " y" << y << endl;
    while (true) {
        //cout << "loop" << endl;
        if (x + i > a.size() - 1 || // fuck 0-based index
            x - i < 0 ||
            y + i > a[0].length() ||
            y - i < 0)
        {
            break;
        }
        //cout << "loop2" << endl;
        if (a[x + i][y] == 'G' &&
            a[x - i][y] == 'G' &&
            a[x][y + i] == 'G' &&
            a[x][y - i] == 'G')
        {
            s += 4;
        } else {
            break;
        }
        i++;
    };
    //cout << "s" << s << endl;
    return s;
}
///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream cin("ucode_daucong.inp");
    //ofstream cout("ucode_daucong.out");
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    };
    int c_size, mx2 = 0, mx = 0;
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            //cout << "X = " << x << endl;
            //cout << "Y = " << y << endl;
            if (a[x][y] == 'G') {
                c_size = cross_size(a, x, y);
                if (c_size >= mx) {
                    mx2 = mx;
                    mx = c_size;
                };
            };
        };
    };
    cout << mx * mx2;
}
