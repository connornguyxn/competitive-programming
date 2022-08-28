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

// https://ucode.vn/problems/117629
// maps

///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //ifstream cin("ucode_socodon.inp");
    //ofstream cout("ucode_socodon.out");
    int n;
    cin >> n;
    int a;
    unordered_map<int, int> m;
    // count number of each number
    for (int i = 0; i < n; i++) {
        cin >> a;
        m[a]++;
    };
    int cnt = 0;
    for (auto it : m) {
        if (it.second == 1)
            cnt++;
    };
    cout << cnt;
}