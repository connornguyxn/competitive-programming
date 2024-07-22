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
#define for_to(l, r) for (long long i = l; i <= r; i++)
#define fm(val) "["#val" = "<<(val)<<"] "
const ull MOD = 1e9 + 7;

// https://oj.vnoi.info/problem/vnoicup22_r3_a
// math
// https://www.facebook.com/photo?fbid=376775044549347

///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //ifstream cin("vnoj_vnoicup_quantuong.inp");
    //ofstream cout("vnoj_vnoicup_quantuong.out");
    int t, n;
    cin >> n >> t;
    while (t--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2 && y1 == y2) {
            cout << 0 << nl;
        } else if ((x1 + y1) % 2 != (x2 + y2) % 2) {
            cout << -1 << nl;
        } else if (abs(x1 - x2) == abs(y1 - y2)) {
            cout << 1 << nl;
            cout << x2 << sp << y2 << nl;
        } else {
            cout << 2 << nl;
            // cross-section based on sum and diff
            auto solve = [](int diff, int sum) { // lambda function
                return make_pair((sum + diff) / 2, (sum - diff) / 2);
            };
            { // declare varable scope to avoid confilct
                auto [a, b] = solve(x1 - y1, x2 + y2); // structured binding
                if (1 <= a && a <= n && 1 <= b && b <= n) {
                    cout << a << sp << b << nl;
                    cout << x2 << sp << y2 << nl;
                    continue;
                };
            };
            {
                auto [a, b] = solve(x2 - y2, x1 + y1);
                if (1 <= a && a <= n && 1 <= b && b <= n) {
                    cout << a << sp << b << nl;
                    cout << x2 << sp << y2 << nl;
                };
            };
        };
        /////////////////
        //cout << nl;
    };
    return 0;
}