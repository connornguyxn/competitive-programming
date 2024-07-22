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
#define dec_point(n) fixed << showpoint << setpreciscion(n)
#define mp_optimize(mp) mp.reserve(4096); mp.max_load_factor(0.1);
#define for_in(a) for (auto& i : a)
const ull MOD = 1e9 + 7;

// https://oj.vnoi.info/problem/tht21_skc_brick
// sieve, searching

///////////////////////////////////////
const int LIM = 1e6;
int cnt_prime;
array<int, LIM> prime, isprime;
array<int, LIM + 1> lpf;
/////////////////
void init_sieve(int n) {
    cnt_prime = 0;
    prime[cnt_prime++] = 2;
    fill_n(lpf.begin(), n + 1, 2);
    fill(isprime.begin(), isprime.end(), 0);
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
}
///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init_ifstream();
    //init_ofstream();
    init_sieve(LIM);
    vector<ll> mul(cnt_prime - 1);
    for (int i = 0; i < mul.size(); i++) {
        mul[i] = 1LL * prime[i] * prime[i + 1];
    };
    //vdb(mul);
    int t = 1;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        cout << n - *(--upper_bound(all(mul), n));
        /////////////////
        cout << nl;
    };
    return 0;
}