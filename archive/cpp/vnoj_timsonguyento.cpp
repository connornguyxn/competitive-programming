#pragma GCC optimize("O3,unroll-loops,inline")
#pragma GCC target("avx,avx2,f16c,fma,sse3,ssse3,sse4,sse4.1,sse4.2")
#include <bits/stdc++.h>
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
#define fm(val) "["#val" = "<<(val)<<"] "
const ull MOD = 1e9 + 7;

// https://oj.vnoi.info/problem/pnumber
// prime

///////////////////////////////////////
array<bool, 1000000> sieve;
///////////////////////////////////////
void init_sieve(int n) {
    sieve[1] = false;
    sieve[2] = true;
    for (int i = 2; i <= sqrt(n); i++) {
        for (int j = 2; j <= n / i; j++) {
            
        };
    };
};
///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //ifstream cin("vnoj_timsonguyento.inp");
    //ofstream cout("vnoj_timsonguyento.out");
    int t = 1;
    //cin >> t;
    while (t--) {

        /////////////////
        cout << nl;
    };
    return 0;
}