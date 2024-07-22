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

// http://ntucoder.net/Submission/Mine/44
// prime

///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init_ifstream();
    //init_ofstream();
    int t = 1;
    //cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        if (n == 1) {
            cout << "NO";
            return 0;
        };
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                cout << "NO";
                return 0;
            };
        };
        cout << "YES";
        /////////////////
        cout << nl;
    };
    return 0;
}