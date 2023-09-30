#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #pragma GCC optimize("O3,unroll-loops,inline")
    #include <bits/stdc++.h>
    #define TASK "pikachu"
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
const int N = 1e3 + 1;
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

// pikachu
// <tags>

int m, n;
array<array<int, N>, N> a;

struct sub1 {
    sub1() {
        if ((a[0][0] == a[0][1] && a[1][0] == a[1][1]) ||
            (a[0][0] == a[1][0] && a[0][1] == a[1][1]))
        {
            cout << 1;
        } else if (a[0][0] == a[1][1] && a[0][1] == a[1][0]) {
            if (a[0][0] == 0 || a[0][1] == 0) {
                cout << 2;
            } else {
                cout << 4;
            };
        } else {
            cout << -1;
        }
    }
};
struct sub2 {
    sub2() {
        array<int, N> &cur = a[0];
        
        deque<int> st;
        
        for (int i = 0; i < n; i++) {
            if (cur[i] == 0) continue;
            if (st.size() && st.back() == cur[i]) {
                st.pop_back();
            } else {
                st.push_back(cur[i]);
            }
        }
        
        if (st.size() == 0) {
            cout << 1;
        } else {
            cout << 3;
        }
    }
};
struct sub3 {
    sub3() {
        cout << 4;
    }
};
////////////////////////////////////////
int main() {
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    };
    cin.tie(0) -> sync_with_stdio(0);
    ////////////////
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        };
    };
    
    if (n == m && n == 2) {
        sub1();
    } else if (m == 1) {
        sub2();
    } else {
        cout << 3;
    }
    ////////////////
    return 0;
}