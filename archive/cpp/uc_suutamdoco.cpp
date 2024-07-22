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

// https://ucode.vn/problems/117670
// <techniques used>

///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //ifstream cin("ucode_suutamdoco.inp");
    //ofstream cout("ucode_suutamdoco.out");

    int n;
    cin >> n;
    string s;
    cin >> s;

    set<int> ss;
    map<char, int> mp;

    for(int i = 0; i < n; i++)
        ss.insert(s[i]);

    int l = 0, r = 0;
    int ans = n, t = 0;

    while (l <= r) {
        if (t == ss.size()) {
            ans = min(ans, r - l);
            mp[s[l]]--;
            if(!mp[s[l]]){
                t--;
            };
            l++;
        } else if (r < n) {
            if(!mp[s[r]]) {
                t++;
            };
            mp[s[r]]++;
            r++;
        } else {
            break;
        };
    }
    cout << ans;
}