#ifdef local_debug
#include "include/debugging.h"
#define log(...) logger(#__VA_ARGS__, __VA_ARGS__)
#define init_ifstream() ifstream cin("input.inp")
#define init_ofstream() ofstream cout("output.out")
#else
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

// http://ntucoder.net/Problem/Details/101
// easy

///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init_ifstream();
    //init_ofstream();
    int t = 1;
    //cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << ((i % 2 == j % 2) ? "W" : "B");
            };
            cout << nl;
        };
        /////////////////
        cout << nl;
    };
    return 0;
}