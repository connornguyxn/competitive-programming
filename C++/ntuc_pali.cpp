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
#define for_in(a) for (auto& it : a)
const int LIM = 1e6;
const ull MOD = 1e9 + 7;

// http://ntucoder.net/Problem/Details/41
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
        int a;
        cin >> a;
        str s = to_string(a);
        bool ok = true;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != s[s.length() - i - 1]) {
                ok = false;
                break;
            };
        };
        if (ok) {
            cout << a << sp;
        };
        /////////////////
        //cout << nl;
    };
    return 0;
}