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
const ull MOD = 1e9 + 7;

// https://codeforces.com/contest/1705/problem/B
// <tags>

///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //ifstream cin("input.inp");
    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ull cnt = 0, a;
        bool ck = false;
        for (int i = 0; i < n - 1; i++) {
            cin >> a;
            cnt += a;
            ck = ck || (a != 0);
            if ((a == 0) && (ck)) {
                cnt++;
            };
        };
        cin >> a;
        cout << cnt;
        /////////////////
        cout << nl;
    };
    return 0;
}