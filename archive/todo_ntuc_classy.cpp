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

// http://ntucoder.net/Problem/Details/4496
// strings

///////////////////////////////////////
int parse(str a) {
    a += '-';
    int cnt = 0;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] == '-') {
            if (a[i - 3] == 'p') {
                cnt++;
            } else if (a[i - 3] == 'w') {
                cnt--;
            };
        };
    };
    return cnt;
};
///////////////////////////////////////
bool comp(pair<int, str> a, pair<int, str> b) {
    if (a.first == b.first) {
        if (a.second.length() == b.second.length()) {
            return a.second > b.second;
        };
        return a.second.length() < b.second.length();
    };
    return a.first > b.first;
};
///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init_ifs();
    /////////////////
    int tc = 1;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<pair<int, str>> a(n);
        str tmp;
        for (int i = 0; i < n; i++) {
            cin >> a[i].second;
            cin >> tmp;
            a[i].first = parse(tmp);
            cin >> tmp;
        };
        sort(all(a), comp);
        for (int i = 0; i < n; i++) {
            //vdb(a[i]);
            cout << a[i].second.substr(0, a[i].second.length() - 1) << nl;
        };
        for (int i = 0; i < 30; i++) {
            cout << '=';
        };
        /////////////////
        cout << nl;
    };
    return 0;
};