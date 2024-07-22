#undef _GLIBCXX_DEBUG
#pragma GCC optimize("O3,unroll-loops,inline")
#pragma GCC target("avx,avx2,f16c,fma,sse3,ssse3,sse4,sse4.1,sse4.2")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define max_size 100000
#define nl '\n'
#define sp ' '
#define dec_point(n) fixed << showpoint << setpreciscion(n)

// https://ucode.vn/problems/117682
// <techniques used>

///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //ifstream cin("ucode_datvaso0.inp");
    //ofstream cout("ucode_datvaso0.out");
    /////////////////
    int tc = 1;
    cin >> tc;
    //cout << tc << endl;
    while (tc--) {
        //cout << "newtc" << endl;
        int n;
        cin >> n;
        int steps = 0;
        bool broke;
        while (n != 0) {
            broke = false;
            steps++;
            //cout << "cnt" << steps << nl;
            for (int i = 2; i <= sqrt(n); i++) {
                if (n % i == 0) {
                    n = max(i, n / i);
                    //cout << "div" << i << " n" << n << endl;
                    broke = true;
                    break;
                };
            };
            if (broke) continue;
            //cout << "sub n" << n << endl;
            n--;
        };
        cout << steps << nl;
    };
}
