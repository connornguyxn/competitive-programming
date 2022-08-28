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

// https://ucode.vn/problems/117612
// math
// O(1), Theta(log n)

///////////////////////////////////////
string valid(int n) {
    if (n % 2 == 0 && floor(sqrt(n / 2)) == sqrt(n / 2))
        return "YES";
    if (n % 4 == 0 && floor(sqrt(n / 4)) == sqrt(n / 4))
        return "YES";
    return "NO";
}
///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream cin("ucode_xephinh.inp");
    //ofstream cout("ucode_xephinh.out");
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        cout << valid(n) << nl;
    };
}