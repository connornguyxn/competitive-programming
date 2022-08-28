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
#define dec_pre(n) fixed << showpoint << setpreciscion(n)

// https://ucode.vn/problems/117656
// string

///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //ifstream cin("ucode_palindrome.inp");
    //ofstream cout("ucode_palindrome.out");
    int q;
    cin >> q;
    while (q--) {
        string inp;
        cin >> inp;
        string a;
        for (char c : inp) {
            if (c != 'a') {
                a += c;
            };
        };
        for (int i = 0; i < a.length() / 2; i++) {
            if (a[i] != a[a.length() - 1 - i]) {
                cout << "NO";
                return 0;
            };
        };
        cout << "YES";
    };

}