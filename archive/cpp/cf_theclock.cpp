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
#define mp_optimize(mp) mp.reserve(4096); mp.max_load_factor(0.1);


// <problem link>
// <techniques used>

///////////////////////////////////////
void reformat(int &h, int &m) {
    h += m % 60;
    h %= 24;
    m %= 60;
}
///////////////////////////////////////
string strip(string s) {
    return to_string(stoi(s));
}
///////////////////////////////////////
bool is_palin(int a, int b) {
    string as = strip(to_string(a));
    reverse(as.begin(), as.end());
    return as == strip(to_string(b));
};
///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream cin("cf_theclock.inp");
    //ofstream cout("cf_theclock.out");
    /////////////////
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int h = stoi(s.substr(0, 2));
        int m = stoi(s.substr(3, 2));
        int x;
        cin >> x;
        unordered_map<string, bool> seen;
        mp_optimize(seen);
        int cnt = 0;
        while (true) {
            if (is_palin(h, m)) cnt++;
            if (!seen[to_string(h) + sp + to_string(m)]) {
                seen[to_string(h) + sp + to_string(m)] = true;
            } else {
                break;
            };
            m += x;
            reformat(h, m);
        };
        cout << cnt;
    };
}