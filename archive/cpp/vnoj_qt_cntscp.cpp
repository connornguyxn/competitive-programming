#undef _GLIBCXX_DEBUG
#pragma GCC optimize("Ofast,unroll-loops,inline")
#pragma GCC target("avx,avx2,f16c,fma,sse3,ssse3,sse4,sse4.1,sse4.2")
#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
#define sp(n) fixed << showpoint << setpreciscion(n)

// https://oj.vnoi.info/problem/qt_cntscp
// <techniques used>

///////////////////////////////////////
bool is_sqr(long double x) {
    if (x >= 0) {
        long long sr = sqrt(x);
        return (sr * sr == x);
    };
    return false;
}
///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //ifstream cin("vnoj_qt_cntscp.inp");
    //ofstream cout("vnoj_qt_cntscp.out");
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (is_sqr(i * j)) {
                cnt++;
                //cout << i << " " << j << endl;
            };
        };
    };
    cout << cnt;
}