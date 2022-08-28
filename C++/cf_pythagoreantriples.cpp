#undef _GLIBCXX_DEBUG
#pragma GCC optimize("Ofast,unroll-loops,inline")
#pragma GCC target("avx,avx2,f16c,fma,sse3,ssse3,sse4,sse4.1,sse4.2")
#include <bits/stdc++.h>
using namespace std;
#define nl '\n'

//https://codeforces.com/problemset/problem/1487/D
//https://ucode.vn/problems/117595

///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //ifstream cin("codeforces_pythagoreantriples.inp");
    //ofstream cout("codeforces_pythagoreantriples.out");
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int cnt = 0;
        int a = 1;
        while (a * a <= 2 * n - 1) {
            int b = ((a * a) - 1) / 2;
            int c = ((a * a) + 1) / 2;
            if (c * c == ((a * a) + (b * b)) &&
                c == (a * a - b) && b != 0 &&
                c != 0 && b <= n && c <= n)
            {
                cnt++;
            }
            a += 2;
        }
        cout << cnt << nl;
    }
}