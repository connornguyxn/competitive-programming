#ifdef local_debug
#include "include/debugging.h"
#define init_ifs() ifstream cin("input.inp")
#define init_ofs() ofstream cout("output.out")
#else
#include <bits/stdc++.h>
#define init_ifs()
#define init_ofs()
#define vdb(...)
#define db(...)
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

// http://ntucoder.net/Problem/Details/45
// math, prime, sieve

///////////////////////////////////////
int cnt_prime;
array<bool, 10000000> notprime;
/////////////////
void init_sieve(int n, int p) {
    if (p == 1) {
        cout << 2;
        return;
    };
    cnt_prime = 1;
    for (ll x = 3; x <= n; x += 2) {
        if (!notprime[x]) {
            cnt_prime++;
            if (cnt_prime == p) {
                cout << x << nl;
                return;
            };
            for (int i = 2; i <= n / x; i++) {
                notprime[x * i] = true;
            };
        };
    };
};
///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init_ifs();
    init_ofs();
    /////////////////
    int tc = 1;
    //cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        //mp_optimize(lpf);
        init_sieve(10000000, n);
        // for (int i = 0; i < 10000; i++) {
        //     cout << prime[i] << nl;
        // };
        /////////////////
        cout << nl;
    };
    return 0;
};