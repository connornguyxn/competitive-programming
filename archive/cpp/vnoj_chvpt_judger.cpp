#if localdb
    #include "include/debug.h"
    #define TASK "test"
#else
    #pragma GCC optimize("O3,unroll-loops,inline")
    #include <bits/stdc++.h>
    #define db(...)
    #define TASK "judger"
#endif
using namespace std;
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int, int>
#define fi first
#define se second
#define str string
#define nl '\n'
#define sp ' '
#define mask(BI) (1LL << (BI))
#define bitcnt(BM) __builtin_popcountll(BM)
#define getbit(BM, BI) ((BM >> BI) & 1)
#define all(A) (A).begin(), (A).end()
#define point(N) fixed << showpoint << setprecision(N)
const int MAXN = 1e6;
const ull MOD = 1e9 + 7;

// <problem link>
// <tags>

///////////////////////////////////////
int main() {
    if (fopen(TASK".inp", "r")) freopen(TASK".inp", "r", stdin);
    if (fopen(TASK".out", "r")) freopen(TASK".out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(0);
    /////////////////
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    
    set<pii, greater<pii>> st;
    unordered_set<int> mk;
    
    for (int i = 1; i <= n; i++) {
        st.insert({0, i});
        mk.insert(i);
    };
    
    int p, v;
    for (int tc = 1; tc <= q; tc++) {
        // db(tc);
        
        int inp;
        cin >> inp;
        // db(inp);
        
        if (inp == 1) {
            cin >> p;
            // db(p);
            if (!mk.count(p)) {
                // cout << "valid" << nl;
                a[p] = 0;
                mk.insert(p);
                st.insert({0, p});
            };
        };
        
        if (inp == 2) {
            cin >> p;
            // db(p);
            if (mk.count(p)) {
                // cout << "valid" << nl;
                mk.erase(p);
                st.erase({a[p], p});
            };
        };
        
        if (inp == 3) {
            cin >> p >> v;
            // db(p, v);
            if (mk.count(p)) {
                // cout << "valid" << nl;
                st.erase({a[p], p});
                a[p] += v;
                st.insert({a[p], p});
            };
        };
        
        if (inp == 4) {
            if (st.empty()) {
                cout << "EMPTY";
            } else if (st.size() < 3) {
                for (auto &it : st) {
                    cout << it.fi << sp;
                };
            } else {
                auto it = st.begin();
                for (int i = 0; i < 3; i++) {
                    cout << (*(it++)).fi << sp;
                };
            };
            cout << nl;
        };
        // for (auto &it : st) {
        //     cout << it << sp;
        // };
        // cout << nl;
        // cout << nl;
    };

    /////////////////
    return 0;
};
/*
000000000000000000000000000000000000000000011111111100000000000000000000000000000000000000
0000000000000000000000000000000000001111.............1111111000000000000000000000000000000
00000000000000000000000000000000011.. .....11111111.........111000000000000000000000000000
000000000000000000000000000000011.  .1111111111111111111111.. .110000000000000000000000000
0000000000000000000000000000001. ..111111111111111111111111111. .1100000000000000000000000
000000000000000000000000000001. .111111111111111111111111111111. .110000000000000000000000
00000000000000000000000000001. .111111.............11111111111111. .1000000000000000000000
00000000000000000000000000001  111.   ..............   ...11111111. .100000000000000000000
0000000000000000000000000001. .11.  ..11111111111111111..  .1111111. .10000000000000000000
0000000000000000000000000001  111. ..11111111111111111111.  .1111111. .1000000000000000000
000000000000000000000000001. .111.  ..1111111111111111111.. .11111111. .100000000000000000
000000000000000000000000001. 11111.   ...11111111111111...  .11111111. .100000000000000000
000000000000000000000000011 .1111111..   ..............   .11111111111. 110000000000000000
00000000000000000000000001. .1111111111.................11111111111111. .10000000000000000
00000000000000000000000001 .1111111111111111111111111111111111111111111  10000000000000000
0000000000000000000000001. .1111111111111111111111111111111111111111111. .1000000000000000
0000000000000000000000001. 11111111111111111111111111111111111111111111. .1000000000000000
000000000000000000000001. .11111111111111111111111111111111111111111111. .1000000000000000
000000000000000000000001. .111111111111111111111111111111111111111111111 .1000000000000000
000000000000000000000011 .1111111111111111111111111111111111111111111111 .1000000000000000
00000000000000000000001. .1111111111111111111111111111111111111111111111. 1000000000000000
00000000000000000000001. 11111111111111111111111111111111111111111111111. 1000000000000000
0000000000000000000001. .11111111111111111111111111111111111111111111111. 1100000000000000
0000000000000000000001. .11111111111111111111111111111111111111111111111. 1100000000000000
0000000000000000000011 .111111111111111111111111111111111111111111111111. 1100000000000000
000000000000000000001. .111111111111111111111111111111111111111111111111. 1100000000000000
000000000000000000001 .1111111111111111111111111111111111111111111111111  1000000000000000
00000000000000000001. .1111111111111111111111111111111111111111111111111 .1000000000000000
00000000000000000001. 11111111111111111111.........11111111111111111111. .1000000000000000
0000000000000000001. .111111111111................... .1111111111111111. .1000000000000000
0000000000000000001. .111111111....111111111111111111. .111111111111111. .1000000000000000
0000000000000000011 .111111111. .100000000000000000001  111111111111111. .1000000000000000
000000111111111111. .111111111. .100000000000000000001  111111111111111. .1000000000000000
00111...............11111111111 .100000000000000000001 .111111111111111. .1000000000000000
001. ..111111111111111111111111. 110000000000000000001  111111111111111. .1000000000000000
001. 11111111111111111111111111. .10000000000000000001  111111111111111. .1000000000000000
001. .1111111111111111111111111. .10000000000000000001 .111111111111111. .1000000000000000
00011. ..11111111111111111111..  .1000000000111111111. .111111111111111 .10000000000000000
0000011.. ................. ...11100000111........... ..11111111111111. .10000000000000000
0000000111111...........111111000000011. ...11111111111111111111111111  110000000000000000
00000000000000000000000000000000000001. .111111111111111111111111111.  .100000000000000000
000000000000000000000000000000000000011. .11111111111111111111111.. ..11000000000000000000
00000000000000000000000000000000000000111.. ......111111111.... ...11000000000000000000000
00000000000000000000000000000000000000000111111...............1111000000000000000000000000
000000000000000000000000000000000000000000000000011111111111100000000000000000000000000000
*/