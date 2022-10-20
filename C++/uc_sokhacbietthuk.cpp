#undef _GLIBCXX_DEBUG
#pragma GCC optimize("Ofast,unroll-loops,inline")
#pragma GCC target("avx,avx2,f16c,fma,sse3,ssse3,sse4,sse4.1,sse4.2")
#include <bits/stdc++.h>
#include "helper/debug.h"
using namespace std;
#define ll long long
#define ld long double
#define max_size 100000
#define nl cout << '\n'
#define sp ' '
#define dec_point(n) fixed << showpoint << setpreciscion(n)
#define umap_optimize(mp) mp.reserve(4096); mp.max_load_factor(0.1);

// https://ucode.vn/problems/117705
// <techniques used>

///////////////////////////////////////
void solve() {
    ifstream cin("ucode_sokhacbietthuk.inp");
    //ofstream cout("ucode_sokhacbietthuk.out");
    /////////////////
    int n, q;
    cin >> n >> q;
    set<ll> mk;
    mk.insert(0);
    ll inp;
    for (int i = 0; i < n; i++) {
        cin >> inp;
        mk.insert(inp);
    };
    n++;
    vector<ll> a(n);
    int p = 0;
    for (auto i : mk) {
        a[p] = i;
        p++;
    };
    while (q--) {
        ll k;
        cin >> k;
        bool ck = false;
        for (int i = 0; i < n - 1; i++) {
            //cout << a[i] << sp << k;
            //nl;
            if (k - (a[i + 1] - a[i] - 1) <= 0) {
                cout << a[i] + k; //<< " case 1";
                ck = true;
                break;
            };
            k -= a[i + 1] - a[i] - 1;
        };
        if (!ck) cout << a[n - 1] + k; //<< " case 2";
        nl;
    };

}
///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    };
    return 0;
}