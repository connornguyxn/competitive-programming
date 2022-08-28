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
#define dec_point(n) fixed << showpoint << setpreciscion(n)
#define mp_optimize(mp) mp.reserve(4096); mp.max_load_factor(0.1);
#define for_in(a) for (auto& i : a)
const ull MOD = 1e9 + 7;

// https://codeforces.com/contest/1705/problem/A
// <tags>

///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init_ifstream();
    //init_ofstream();
    int t = 1;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n * 2);
        for_in(a) {
            cin >> i;
        };
        sort(a.begin(), a.end());
        bool sk = false;
        for (int i = 0; i < n; i++) {
            if (a[i] + k > a[n + i]) {
                cout << "NO";
                sk = true;
                break;
            };
        };
        if (!sk) {
            cout << "YES";
        };
        /////////////////
        cout << nl;
    };
    return 0;
}