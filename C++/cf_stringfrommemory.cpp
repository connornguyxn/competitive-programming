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

// https://codeforces.com/contest/1702/problem/B
// string

///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init_ifstream();
    //init_ofstream();
    int t = 1;
    cin >> t;
    while (t--) {
        str a;
        cin >> a;
        unordered_set<char> s;
        int cnt = 0;
        for (int i = 0; i < a.length(); i++) {
            if (s.find(a[i]) == s.end()) {
                if (s.size() == 3) {
                    //log("dayat", i);
                    s.clear();
                    cnt++;
                };
                s.insert(a[i]);
                //log("insert", i + 1);
            };
        };
        //log(s);
        if (!s.empty()) {
            cnt++;
        };
        cout << cnt;
        /////////////////
        cout << nl;
    };
    return 0;
}