#ifdef local_debug
#include "include/debugging.h"
#define log(...) logger(#__VA_ARGS__, __VA_ARGS__)
#define init_ifstream() ifstream cin("_input.inp")
#define init_ofstream() ofstream cout("_output.out")
#else
#pragma GCC optimize("O3,unroll-loops,inline")
#pragma GCC target("avx,avx2,f16c,fma,sse3,ssse3,sse4,sse4.1,sse4.2")
#include <bits/stdc++.h>
#define log(...)
#define init_ifstream()
#define init_ofstream()
#endif
using namespace std;
#define ll long long
#define ull unsigned long long
#define ld long double
#define str string
#define nl '\n'
#define sp ' '
#define dec_point(n) fixed << showpoint << setpreciscion(n)
#define mp_optimize(mp) mp.reserve(4096); mp.max_load_factor(0.1);
#define for_in(a) for (auto& i : a)
const ull MOD = 1e9 + 7;

// https://codeforces.com/contest/1702/problem/C
// map

///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init_ifstream();
    //init_ofstream();
    int t = 1;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        unordered_map<int, pair<int, int>> m;
        mp_optimize(m);
        int a;
        for (int i = 0; i < n; i++) {
            cin >> a;
            if (m.find(a) == m.end()) {
                m[a].first = i;
            };
            m[a].second = i;
            //log(a, m[a]);
        };
        int l, r;
        for (int i = 0; i < q; i++) {
            cin >> l >> r;
            if (m.find(l) == m.end() ||
                m.find(r) == m.end())
            {
                cout << "NO";
            } else if (m[l].first <= m[r].second) {
                cout << "YES";
            } else {
                cout << "NO";
            };
            cout << nl;
        };
        /////////////////
        //cout << nl;
    };
    return 0;
}