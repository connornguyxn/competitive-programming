#ifdef local_debug
#include "include/debugging.h"

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

// https://oj.vnoi.info/problem/fct034_coltri
// math, sieve, combnatorics

///////////////////////////////////////
int cnt_prime;
vector<int> prime(LIM), isprime(LIM);
vector<int> lpf(LIM + 1);
/////////////////
void init_sieve(int n) {
    cnt_prime = 0;
    prime[cnt_prime++] = 2;
    fill_n(lpf.begin(), n + 1, 2);
    fill_n(isprime.begin(), n + 1, 0);
    for (int x = 3; x <= n; x += 2) {
        if (lpf[x] == 2) {
            lpf[x] = x;
            prime[cnt_prime++] = x;
            isprime[x] = 1;
        };
        for (int i = 0; (i < cnt_prime) &&
                        (prime[i] <= lpf[x]) &&
                        (prime[i] * x <= n); i++)
        {
            lpf[prime[i] * x] = prime[i];
        };
    };
    prime.resize(cnt_prime);
}
///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init_ifs();
    init_sieve(LIM);
    /////////////////
    int tc = 1;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        // for (int i = 0; i < cnt_prime + 1; i++) {
        //     cout << prime[i] << nl;
        // };
        int cnt_p = lower_bound(all(prime), n) - prime.begin() + 1;
        vdb(cnt_p);
        vdb(n - cnt_p);
        auto cmb3 = [](int cnt) {
            return cnt * (cnt - 1) * (cnt - 2) / 6;
        };
        cout << cmb3(cnt_p) + cmb3(n - cnt_p);
        /////////////////
        cout << nl;
    };
    return 0;
};