#undef _GLIBCXX_DEBUG
#pragma GCC optimize("Ofast,unroll-loops,inline")
#pragma GCC target("bmi,bmi2,lzcnt,avx,avx2,f16c,fma,sse2,sse3,ssse3,sse4,sse4.1,sse4.2")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define max_size 100000
#define nl '\n'
#define sp(n) fixed << showpoint << setpreciscion(n)

// http://vinhdinhcoder.net/Problem/Details/5291
// sorting, 2pointers

///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //ifstream cin("vdcoder_quatang.inp");
    //ofstream cout("vdcoder_quatang.out");
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int l = 0, r = n - 1, ans = 0;
    while (l < r) {
        if (a[l] + a[r] < k) {
            if (a[l] + a[r] > ans)
                ans = a[l] + a[r];
            l++;
        } else {
            r--;
        }
    }
    cout << ans;
}