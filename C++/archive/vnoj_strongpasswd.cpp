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
#define fm(val) "["#val" = "<<(val)<<"] "
const ull MOD = 1e9 + 7;

// https://oj.vnoi.info/problem/fc140_strongpasswd
// strings

///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //ifstream cin("vnoj_strongpasswd.inp");
    //ofstream cout("vnoj_strongpasswd.out");
    int t = 1;
    //cin >> t;
    while (t--) {
        str a;
        cin >> a;
        bool ck_u = false, ck_l = false,
            ck_n = false, ck_s = false, ck_d = false;
        for (int i = 0; i < a.length(); i++) {
            if (i > 0) {
                ck_d = ck_d || (a[i] == a[i - 1]);
            };
            ck_u = ck_u || isupper(a[i]);
            ck_l = ck_l || islower(a[i]);
            ck_n = ck_n || isdigit(a[i]);
            ck_s = ck_s || !isalpha(a[i]);
        };
        if (ck_u && ck_l && ck_n &&
            ck_s && !ck_d && a.length() >= 8)
        {
            cout << "YES";
        } else {
            cout << "NO";
        };
        /////////////////
        cout << nl;
    };
    return 0;
}