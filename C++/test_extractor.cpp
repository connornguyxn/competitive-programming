#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #pragma GCC optimize("O3,unroll-loops,inline")
    #include <bits/stdc++.h>
    #define TASK "oly"
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

int main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    int n, k;
    cin >> n >> k;
    vector<int> a(n * k);
    vector<int> b(n * k);
    for (int i = 0; i < n * k; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n * k; i++) {
        cin >> b[i];
    }
    for (int i = n; i < n * 2; i++) {
        cout << b[i];
    }
    
}