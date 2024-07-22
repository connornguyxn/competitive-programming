#undef _GLIBCXX_DEBUG
#pragma GCC optimize("Ofast,unroll-loops,inline")
#pragma GCC target("avx,avx2,f16c,fma,sse3,ssse3,sse4,sse4.1,sse4.2")
//#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
#define nl '\n'
#define sp(n) fixed << showpoint << setpreciscion(n)

// https://oj.vnoi.info/problem/qt_thungxop
// <techniques used>
// <summary of how to solve the problem>

///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream cin("vnoj_qt_box.inp");
    //ofstream cout("vnoj_qt_box.out");
    int n;
    cin >> n;
    vector<int> boxes;
    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        for (int j = 0; j < boxes.size(); j++) {
            if (a < boxes[j]) {
                boxes[j] = a;
                a = -1;
                break;
            };
        };
        if (a != -1) {
            boxes.push_back(a);
        };
    };
    cout << boxes.size() << nl;
}
