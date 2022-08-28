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
#define for_in(i, a) for (auto& i : a)
#define for_to(l, r) for (int i = l; i <= r; i++)
#define fm(val) "["#val" = "<<(val)<<"] "
const unsigned long long MOD = 1e5 + 3;

// http://ntucoder.net/Problem/Details/5657
// math

///////////////////////////////////////
ll binpow(ll a, ll b) {
    a %= MOD;
    ll res = 1;
    while (b > 0) {
        if (b % 2 == 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b /= 2;
    };
    return res % MOD;
}
///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //ifstream cin("ntucoder_candy1.inp");
    //ofstream cout("ntucoder_candy1.out");
    int t = 1;
    cin >> t;
    while (t--) {
        ll m, n, k;
        cin >> m >> n >> k;
        m -= k * n;
        if (m < 0) {
            cout << 0 << nl;
            continue;
        };
        //cout << fm(m) << fm(n) << fm(k) << nl;
        cout << binpow(n, m);
        cout << nl;
    };
    return 0;
}