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
#define dec_point(n) fixed << showpoint << setprecision(n)
#define mp_optimize(mp) mp.reserve(4096); mp.max_load_factor(0.1);
#define for_in(a) for (auto& i : a)
const int LIM = 1e6;
const ull MOD = 1e9 + 7;

// https://codeforces.com/contest/1706/problem/C
// dp

///////////////////////////////////////
vector<int> c(LIM, -1);
int n, mn = INFINITY, mx = 0;
///////////////////////////////////////
void solve(int p, int s, int cnt) {
    if (p >= n - 1) {
        return;
    };
    if (cnt >= mx) {
        mx = cnt;
        mn = min(mn, s);
    };
    for (int i = p; i < n - 1; i++) {
        solve(i + 2, s + c[i], cnt++);
    };
}
///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init_ifstream();
    //init_ofstream();
    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> h(n);
        for (int i = 0; i < n; i++) {
            cin >> h[i];
        };
        for (int i = 1; i < n - 1; i++) {
            c[i] = max(h[i + 1], h[i - 1]) + 1 - h[i];
        };
        solve(1, c[1], 1);
        vdb(mx, mn);
        /////////////////
        cout << nl;
    };
    return 0;
}