#undef _GLIBCXX_DEBUG
#pragma GCC optimize("Ofast,unroll-loops,inline")
#pragma GCC target("avx,avx2,f16c,fma,sse3,ssse3,sse4,sse4.1,sse4.2")
#include <bits/stdc++.h>
//#include "helper/debug.h"
using namespace std;
#define ll long long
#define ld long double
#define max_size 100000
#define nl cout << '\n'
#define sp ' '
#define dec_point(n) fixed << showpoint << setpreciscion(n)
#define mp_optimize(mp) mp.reserve(4096); mp.max_load_factor(0.1);

// https://codeforces.com/contest/1692/problem/F
// hashmap, constructive algorithm

///////////////////////////////////////
vector<vector<int>> combs;
///////////////////////////////////////
void gen_combs() {
    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k <= 9; k++) {
                if ((i + j + k) % 10 == 3) {
                    combs.push_back({i, j, k});
                };
            };
        };
    };
}
///////////////////////////////////////
bool check(unordered_map<int, int> mp, vector<int> comb) {
    for (int i : comb) {
        if (mp[i] > 0) {
            mp[i]--;
            //cout << mp;
            //nl;
        } else {
            //cout << "false";
            //nl;
            return false;
        };
    };
    //cout << "true";
    //nl;
    return true;
}
///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //ifstream cin("cf_3sum.inp");
    //ofstream cout("cf_3sum.out");
    /////////////////
    gen_combs();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        unordered_map<int, int> mp;
        mp_optimize(mp);
        int a;
        for (int i = 0; i < n; i++) {
            cin >> a;
            mp[a % 10]++;
        };
        //cout << mp;
        bool valid = false;
        for (vector<int> comb : combs) {
            //cout << comb;
            valid = check(mp, comb);
            if (valid) break;
        };
        if (valid) {
            cout << "YES";
        } else {
            cout << "NO";
        };
        nl;
    };
}