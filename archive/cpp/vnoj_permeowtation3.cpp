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

// https://oj.vnoi.info/problem/vnoicup22_r1_a
// strings

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
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        };
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        };
        if (a.back() != b.front()) {
            for (int i = 0; i < n; i++) {
                cout << "a";
            };
            for (int i = 0; i < n; i++) {
                cout << "b";
            };
        } else {
            cout << "b";
            for (int i = 0; i < n; i++) {
                cout << "a";
            };
            for (int i = 0; i < n - 1; i++) {
                cout << "b";
            };
        };
        /////////////////
        cout << nl;
    };
    return 0;
}