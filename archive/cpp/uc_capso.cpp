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
#define dec_point(n) fixed << showpoint << setpreciscion(n)

// https://ucode.vn/problems/117693?challenge-id=837
// hashmap

///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //ifstream cin("ucode_capso.inp");
    //ofstream cout("ucode_capso.out");
    /////////////////
    int n, k;
    cin >> n >> k;
    unordered_map<int, bool> m;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (m[x - k]) {
            cnt++;
        };
        if (m[x + k]) {
            cnt++;
        };
        m[x] = true;
    };
    cout << cnt;
}