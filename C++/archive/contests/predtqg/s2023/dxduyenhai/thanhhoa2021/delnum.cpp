#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #pragma GCC optimize("O3,unroll-loops,inline")
    #include <bits/stdc++.h>
    #define TASK "delnum"
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
#define b_mask(POS) (1ULL << (POS))
#define b_get(MASK, POS) ((MASK >> (POS)) & 1)
#define all(VAR) (VAR).begin(), (VAR).end()
const int N = 1e5;
const ll MOD = 1e9 + 7;
const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
// directions = left, up, right, down, upper_l, upper_r, lower_r, lower_l
const int dx[8] = {0, -1, 0, 1, -1, -1, 1, 1};
const int dy[8] = {-1, 0, 1, 0, -1, 1, 1, -1};
template<typename tVar, typename tVal>
void mnmz(tVar &var, tVal val) { if (val < var) var = val; }
template<typename tVar, typename tVal>
void mxmz(tVar &var, tVal val) { if (val > var) var = val; }

// delnum
// <tags>

int n, res;
array<int, N * 2 + 1> spf;
array<int, N + 1> a, mk;
////////////////////////////////////////
void sieve() {
    for (int i = 2; i * i <= N; i++) {
        if (spf[i]) continue;
        for (int j = i * i; j < N; j += i) {
            spf[j] = i;
        }
    }
}
bool ok() {
    for (int i = 0; i < n - 1; i++) {
        if (mk[i]) continue;
        for (int j = i + 1; j < n; j++) {
            if (mk[j]) continue;
            if (a[i] + a[j] > 1 && spf[a[i] + a[j]] == 0) {
                return false;
            };
        }
    }
    return true;
}
////////////////////////////////////////
void gen(int i, int cnt) {
    if (i == n + 1) {
        if (ok()) mnmz(res, cnt);
    } else {
        mk[i] = 1;
        gen(i + 1, cnt + 1);
        mk[i] = 0;
        gen(i + 1, cnt);
    }
}
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(0);
    ////////////////
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    sieve();
    
    res = n;
    gen(0, 0);
    
    cout << res;
    ////////////////
    return 0;
}
