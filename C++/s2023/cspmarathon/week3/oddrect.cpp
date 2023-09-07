#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #pragma GCC optimize("O3,unroll-loops")
    #include <bits/stdc++.h>
    #define TASK "oddrect"
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
#define all(var) (var).begin(), (var).end()
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define Repd(i, n) for (int i = (n); i--; )
#define For(i, l, r) for (int i = (l), _r = (r); i < _r; i++)
#define Ford(i, r, l) for (int i = (r), _l = (l); --i >= _l; )
#define Fore(i, l, r) for (int i = (l), _r = (r); i <= _r; i++)
#define Forde(i, r, l) for (int i = (r) + 1, _l = (l); --i >= _l; )
#define Forin(it, var) for (auto it : var)
#define Bmask(i) (1ULL << (i))
#define Bget(mask, i) ((mask >> (i)) & 1)
#define Blog(n) (63 - __builtin_clzll(n))
template <class T = int>
T inp() { T x; cin >> x; return x; }
template <class... T>
void print(T&&... n) {
    using exp = int[];
    exp{0, (cout << n << sp, 0)...};
    cout << nl;
}
template <class T>
void mxmz(T &d, T b) { d = max(d, b); }
template <class T>
void mnmz(T &d, T b) { d = min(d, b); }
const int N = 1e3 + 2;
// const int N = 5;
const ll MOD = 1e9 + 7;
const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
const int dx[8] = {0, -1, 0, 1, -1, -1, 1, 1};
const int dy[8] = {-1, 0, 1, 0, -1, 1, 1, -1};

// oddrect
// <tags>

////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////
    int n;
    cin >> n;
    
    vector<vector<int>> d(N + 1, vector<int>(N + 1));
    Rep(i, n) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        r1++; c1++; r2++; c2++;
        
        d[r1][c1]++;
        d[r2 + 1][c2 + 1]++;
        d[r1][c2 + 1]--;
        d[r2 + 1][c1]--;
    }
    
    ll ans = 0;
    vector<vector<int>> a(N + 1, vector<int>(N + 1));
    Fore(i, 1, N) {
        Fore(j, 1, N) {
            a[i][j] = d[i][j] + a[i][j - 1] + a[i - 1][j] - a[i - 1][j - 1];
            ans += a[i][j] % 2;
        }
    }
    
    cout << ans;
    ////////////
    return 0;
}