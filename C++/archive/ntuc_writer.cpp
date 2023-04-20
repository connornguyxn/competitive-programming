#ifdef local_debug
#include "include/debugging.h"

#define init_ofs() ofstream cout("output.out")
#else
#include <bits/stdc++.h>
#define init_ifs()
#define init_ofs()
#define vdb(...)
#define db(...)
#endif
using namespace std;
#define ll long long
#define ull unsigned long long
#define ld long double
#define str string
#define nl '\n'
#define sp ' '
#define all(a) a.begin(), a.end()
#define dec_point(n) fixed << showpoint << setprecision(n)
#define mp_optimize(mp) mp.reserve(4096); mp.max_load_factor(0.1);
#define for_in(a) for (auto& it : a)
const int LIM = 1e6;
const ull MOD = 1e9 + 7;

// http://ntucoder.net/Problem/Details/3255
// string, map

///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init_ifs();
    map<char, pair<int, int>> v;
    str spec = ".,?!";
    for (int i = 0; i < 4; i++) {
        v[spec[i]] = {i + 1, 1};
    };
    for (char i = 'a'; i <= 'o'; i++) {
        v[i].first = (toascii(i) - 97) % 3 + 1;
        v[i].second = (toascii(i) - 97) / 3 + 2;
    };
    for (int i = 1; i <= 4; i++) {
        v[char('o' + i)] = {i, 7};
    };
    for (int i = 1; i <= 3; i++) {
        v[char('s' + i)] = {i, 8};
    };
    for (int i = 1; i <= 4; i++) {
        v[char('v' + i)] = {i, 9};
    };
    v['_'] = {1, 10};
    for (int i = 0; i <= 10; i++) {
        v[char(48 + i)] = {4, i};
    };
    v['1'].first = 5;
    v['7'].first = 5;
    v['9'].first = 5;
    v['0'] = {2, 10};
    /////////////////
    int tc = 1;
    cin >> tc;
    while (tc--) {
        str a;
        cin >> a;
        a = '.' + a;
        int cnt = 0;
        for (int i = 1; i < a.length(); i++) {
            if (v[a[i - 1]].second != v[a[i]].second) {
                cnt++;
            };
            cnt += v[a[i]].first;
        };
        cout << cnt;
        /////////////////
        cout << nl;
    };
    return 0;
};