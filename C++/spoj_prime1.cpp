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
const int LIM = 1e3;
const ull MOD = 1e9 + 7;

// https://www.spoj.com/problems/PRIME1/
// sieve

///////////////////////////////////////
int cnt_prime;
vector<int> prime(LIM);
vector<short int> isprime(LIM);
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
};
/////////////////
void printq(int l, int r) {
    for (int i : prime) {
        int lower = (l / i);     
        if (lower <= 1) {
            lower = i + i;
        } else if (l % i) {
            lower = (lower * i) + i;
        } else {
            lower = (lower * i);
        };
        for (int j = lower; j <= r; j += i) {
            prime[j - l] = false;
        }
    }
   
    for (int i = l; i <= r; i++) {
        if (isprime[i - l]) {
            cout << (i) << " ";
        }
    }
}
///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init_ifs();
    init_sieve(LIM);

    /////////////////
    int tc = 1;
    //cin >> tc;
    while (tc--) {

        /////////////////
        cout << nl;
    };
    return 0;
};