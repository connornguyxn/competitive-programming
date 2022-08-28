#undef _GLIBCXX_DEBUG
#pragma GCC optimize("Ofast,unroll-loops,inline")
#pragma GCC target("avx,avx2,f16c,fma,sse3,ssse3,sse4,sse4.1,sse4.2")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define max_size 100000
#define nl '\n'
#define sp ' '
#define preciscion(n) fixed << showpoint << setpreciscion(n)

// https://ucode.vn/problems/117631
// brute force

///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream cin("ucode_daycondainhat.inp");
    //ofstream cout("ucode_daycondainhat.out");
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    };
    int ans = 1;
    vector<int> rg(n, 1);
    for (int i = n - 2; i >= 0; i--) {
        if (a[i + 1] > a[i])
            rg[i] = rg[i + 1] + 1;
        ans = max(ans, rg[i]);
    };
    vector<int> lf(n, 1);
    for (int i = 1; i < n; i++) {
        if (a[i - 1] < a[i])
            lf[i] = lf[i - 1] + 1;
        ans = max(ans, lf[i]);
    };
    for (int i = 0; i < n - 2; i++) {
        if (a[i] < a[i + 2])
            ans = max(ans, lf[i] + rg[i + 2]);
    };
    cout << ans;
}