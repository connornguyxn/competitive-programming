
#if DEBUG
    #include "include/debug.h"
    #pragma GCC optimize("trapv")
    #define TASK "test"
#else
    #pragma GCC optimize("O3,unroll-loops,inline")
    #pragma GCC target("avx2")
    #include <bits/stdc++.h>
    #define db(...)
    #define TASK "chain2"
#endif
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define str string
#define nl '\n'
#define sp ' '
#define mask(POS) (1ULL << (POS))
#define bitcnt(MASK) __builtin_popcountull(MASK)
#define getbit(MASK, POS) ((MASK >> POS) & 1)
#define all(VAR) (VAR).begin(), (VAR).end()
#define point(CNT) fixed << showpoint << setprecision(CNT)
const int MAXN = 1e6;
const ull MOD = 1e9 + 7;

// https://oj.vnoi.info/problem/chain2
// strings, searching, data structure

struct trie {
    struct node {
        int next[26];
        int cnt;
        node() {
            memset(next, 0, sizeof(next));
            cnt = 0;
        }
    };
    vector<node> t;
    
    trie() : t(1) {};
    
    void insert(const str &s) {
        int cur = 0;
        for (char c : s) {
            if (t[cur].next[c - 'a'] == 0) {
                t[cur].next[c - 'a'] = t.size();
                t.push_back(node());
            }
            cur = t[cur].next[c - 'a'];
        };
        t[cur].cnt++;
    }
};
trie t;

// count max number of strings that have the same prefix
int mx = 0;
void dfs(int u, int cnt) {
    mx = max(mx, cnt);
    for (int i = 0; i < 26; i++) {
        if (t.t[u].next[i] != 0) {
            dfs(t.t[u].next[i], cnt + t.t[t.t[u].next[i]].cnt);
        }
    }
}

///////////////////////////////////////
int main() {
    if (fopen(TASK".inp", "r")) freopen(TASK".inp", "r", stdin);
    if (fopen(TASK".out", "r")) freopen(TASK".out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(0);
    /////////////////
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        str s;
        cin >> s;
        t.insert(s);
    };
    
    dfs(0, 0);
    cout << mx << nl;
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