#pragma GCC optimize("Ofast,unroll-loops,inline")
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
#define for_to(l, r) for (long long i = l; i <= r; i++)
#define fm(val) "["#val" = "<<(val)<<"] "
const ull MOD = 1e9 + 7;

// http://vinhdinhcoder.net/Problem/Details/5308
// sorting, greedy

///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //ifstream cin("vdcoder_bus.inp");
    //ofstream cout("vdcoder_bus.out");
    int t = 1;
    //cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        };
        sort(a.begin(), a.end());
        ull s = 0;
        for (int i = 0; i < k; i++) {
            s += a[i];
        };
        cout << s;
        /////////////////
        //endc:
        cout << nl;
    };
    return 0;
}