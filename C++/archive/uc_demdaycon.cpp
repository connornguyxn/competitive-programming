#undef _GLIBCXX_DEBUG
#pragma GCC optimize("Ofast,unroll-loops,inline")
#pragma GCC target("avx,avx2,f16c,fma,sse3,ssse3,sse4,sse4.1,sse4.2")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define max_size 100000
#define nl '\n'
#define sp(n) fixed << showpoint << setpreciscion(n)

// https://ucode.vn/problems/117630
// combinatory, math

///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //ifstream cin("ucode_demdaycon.inp");
    //ofstream cout("ucode_demdaycon.out");
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    };
    // count product = 0 subsegments
    ll pos = -1, cnt_0 = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            pos = i;
        };
        if (pos != -1) {
            cnt_0 += pos + 1;
        };
    };
    ll cnt_neg_even = 0, cnt_neg_odd = 0;
    ll cnt_neg = 0;
    ll pro_cnt_pos = 0;
    for (ll i = 0; i < n; i++) {
        if (a[i] == 0) {
            cnt_neg_even = 0, cnt_neg_odd = 0, cnt_neg = 0;
            continue;
        };
        if (cnt_neg % 2 == 0) {    
            cnt_neg_even++;
        } else {
            cnt_neg_odd++;
        };
        if (a[i] < 0) {
            cnt_neg++;
        };
        // if cnt_neg is even, any r = i and negative count = even
        // will begin in a pos where cnt_neg is even
        if (cnt_neg % 2 == 0) {
            pro_cnt_pos += cnt_neg_even;
        } else {
            // the same for odd
            pro_cnt_pos += cnt_neg_odd;
        };
    };
    // pro_cnt_neg = total_cnt - cnt_0 - pro_cnt_pos
    // use 1ll to avoid overflow, refer to NOTES.md
    cout << 1ll * n * (n + 1) / 2 - cnt_0 - pro_cnt_pos << ' ' << pro_cnt_pos;
}