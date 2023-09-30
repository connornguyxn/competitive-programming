#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #pragma GCC optimize("O3,unroll-loops,inline")
    #include <bits/stdc++.h>
    #define TASK "yard"
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
#define getbit(MASK, POS) ((MASK >> POS) & 1)
#define all(VAR) (VAR).begin(), (VAR).end()
const int N = 1e6;
const ull MOD = 1e9 + 7;
const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
// directions = left, up, right, down, upper_l, upper_r, lower_r, lower_l
const int dx[8] = {0, -1, 0, 1, -1, -1, 1, 1};
const int dy[8] = {-1, 0, 1, 0, -1, 1, 1, -1};
template<typename tVar, typename tVal>
void mnmz(tVar &var, tVal val) { if (val < var) var = val; }
template<typename tVar, typename tVal>
void mxmz(tVar &var, tVal val) { if (val > var) var = val; }

// yard
// <tags>

int n, m;
int cnt = 0;

str spre, scur;
unordered_map<str, unordered_map<str, bool>> match;

bool valid(str cur) {
    if (cur[0] == '5' || cur[m - 1] == '5') return false;
    if (cur[0] == '6' || cur[m - 1] == '4') return false;
    return true;
}

void process() {
    // db(spre, scur);
    cnt++;
    
    // for (int i = 0; i < m; i++) {
        
    // }
}

void gen_scur(int p) {
    if (p == m) {
        process();
    } else {
        for (int i = 0; i < 7; i++) {
            if (p == 0 && i > 4) break;
            if (p == m - 1 && (i == 5 || i == 4)) continue;
            
            scur[p] = '0' + i;
            gen_scur(p + 1);
        }
    }

}

void gen_spre(int p) {
    if (p == m) {
        gen_scur(0);
    } else {
        for (int i = 0; i < 7; i++) {
            if (p == 0 && i > 4) break;
            if (p == m - 1 && (i == 5 || i == 4)) continue;
            
            spre[p] = '0' + i;
            gen_spre(p + 1);
        }
    }
}
////////////////////////////////////////
int main() {
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        // freopen(TASK".out", "w", stdout);
    };
    cin.tie(0) -> sync_with_stdio(0);
    ////////////////
    cin >> n >> m;
    
    spre.resize(m, '0');
    scur.resize(m, '0');
    
    gen_spre(0);
    
    cout << cnt;
    ////////////////
    return 0;
}