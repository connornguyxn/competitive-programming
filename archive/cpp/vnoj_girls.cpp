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

// https://oj.vnoi.info/problem/bedao_m06_girls
// sorting, prefsum

///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init_ifstream();
    //init_ofstream();
    int t = 1;
    //cin >> t;
    while (t--) {
        int m, n, k;
        cin >> m >> n >> k;
        vector<int> a(m);
        for (int i = 0; i < m; i++) {
            cin >> a[i];
        };
        sort(a.begin(), a.end());
        vdb(a);
        unordered_map<int, ll> s;
        mp_optimize(s);
        s[-1] = 0;
        for (int i = 0; i < m; i++) {
            s[i] = s[i - 1] + a[i];
        };
        vdb(s);
        ll mx = -2;
        for (int i = 0; i <= m - n; i++) {
            if (a[i + n - 1] - a[i] <= k) {
                db(i - 1, i + n - 1);
                mx = max(mx, s[i + n - 1] - a[i - 1]);
            };
        };
        cout << mx;
        /////////////////
        cout << nl;
    };
    return 0;
}