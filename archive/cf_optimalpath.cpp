#undef _GLIBCXX_DEBUG
#pragma GCC optimize("Ofast,unroll-loops,inline")
#pragma GCC target("avx,avx2,f16c,fma,sse3,ssse3,sse4,sse4.1,sse4.2")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define max_size 100000
#define nl cout << '\n'
#define sp ' '
#define dec_point(n) fixed << showpoint << setpreciscion(n)
#define mp_optimize(mp) mp.reserve(4096); mp.max_load_factor(0.1);

// https://codeforces.com/contest/1700/problem/A
// dp, backtrack

///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream cin("cf_optimalpath.inp");
    //ofstream cout("cf_optimalpath.out");
    /////////////////
    int t = 1;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int sum = m * (m + 1) / 2;
        cout << "msum " << sum;
        nl;
        //sum -= m ;
        int cnt = (m * n - n) / n + 1;
        sum += (n + m * n) * cnt / 2;
        cout << sum;
        nl;
    };
    return 0;
}