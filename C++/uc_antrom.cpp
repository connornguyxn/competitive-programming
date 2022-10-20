#undef _GLIBCXX_DEBUG
#pragma GCC optimize("Ofast,unroll-loops,inline")
#pragma GCC target("avx,avx2,f16c,fma,sse3,ssse3,sse4,sse4.1,sse4.2")
//#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;
#define nl '\n'

// https://ucode.vn/problems/117601
// greedy, brute force

///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream cin("ucode_antrom.inp");
    //stream cout("ucode_antrom.out");
    clog << "aaaaa" << endl;
    int t;
    cin >> t;
    while (t--) {
        int p, f;
        cin >> p >> f;
        int cnt_s, cnt_w;
        cin >> cnt_s >> cnt_w;
        int s, w;
        cin >> s >> w;
        if (s > w) {
            swap(s, w);
            swap(cnt_s, cnt_w);
        };
        int cnt_t = 0;
        int s2, w1, w2;
        for (int s1 = 0; s1 <= min((p / s), s1); s1++) {
            w1 = min(cnt_w, (p - s * s1) / w);
            s2 = min(cnt_s - s1, f / s);
            w2 = min(cnt_w - w1, (f - s * s2) / w);
            cnt_t = max(cnt_t, s1 + s2 + w1 + w2);
        };
        cout << cnt_t << nl;
    }
}