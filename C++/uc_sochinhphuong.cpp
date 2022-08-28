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

// https://ucode.vn/problems/117611
// math

///////////////////////////////////////
ll count(ll a, ll b) {
    return floor(sqrt(b)) - ceil(sqrt(a)) + 1;
} 
///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //ifstream cin("ucode_sochinhphuong.inp");
    //ofstream cout("ucode_sochinhphuong.out");
    ll q;
    cin >> q;
    while (q--) {
        ll a, b;
        cin >> a >> b;
        cout << count(a, b) << nl;
    };
}