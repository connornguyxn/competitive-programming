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

// http://vinhdinhcoder.net/Problem/Details/4708
// string

///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //ifstream cin("vdc_brupalin.inp");
    //ofstream cout("vdc_brupalin.out");
    /////////////////
    string a;
    cin >> a;
    bool changed = false;
    for (int i = 0; i < a.length() / 2; i++) {
        if (a[i] != a[a.length() - 1 - i]) {
            if (changed) {
                cout << "NO";
                return 0;
            } else {
                changed = true;
            };
        };
    };
    if (a.length() % 2 == 0 and !changed) {
        cout << "NO";
    } else {
        cout << "YES";
    };
};
