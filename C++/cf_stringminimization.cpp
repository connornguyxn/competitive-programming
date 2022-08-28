#ifdef local_debug
#include "include/debugging.h"
#else
#include <bits/stdc++.h>
#define vdb(...)
#define db(...)
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
#define all(a) a.begin(), a.end()
#define dec_point(n) fixed << showpoint << setprecision(n)
#define mp_optimize(mp) mp.reserve(4096); mp.max_load_factor(0.1);
#define for_in(a) for (auto& i : a)
const int LIM = 1e6;
const ull MOD = 1e9 + 7;

// https://codeforces.com/contest/1706/problem/A
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
        int n, m;
        str s;
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            s += "B";
        };
        int a;
        for (int i = 0; i < n; i++) {
            cin >> a;
            a--;
            int b = m - 1 - a;
            //vdb(a, b);
            if (s[min(a, b)] == 'B') {
                //db("mn");
                s[min(a, b)] = 'A';
            } else {
                //db("mx");
                s[max(a, b)] = 'A';
            };
        };
        cout << s;
        /////////////////
        cout << nl;
    };
    return 0;
}