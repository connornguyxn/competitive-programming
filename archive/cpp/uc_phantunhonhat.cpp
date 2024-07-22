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

// https://ucode.vn/problems/117638
// maps

///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //ifstream cin("ucode_phantunhonhat.inp");
    //ofstream cout("ucode_phantunhonhat.out");
    int n;
    cin >> n;
    unordered_map<int, bool> in_arr;
    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        in_arr[a] = true;
    };
    for (int i = 0; i <= max_size; i++) {
        if (!in_arr[i]) {
            cout << i;
            return 0;
        };
    };
}