#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "castle"
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
#define For(i, l, r) for (int i = (l), _r = (r); i <= _r; i++)
#define Ford(i, r, l) for (int i = (r) + 1, _l = (l); --i >= _l; )
#define Forin(it, var) for (auto it : var)
#define bmask(i) (1ULL << (i))
#define bget(mask, i) ((mask >> (i)) & 1)
#define blog2(n) (63 - __builtin_clzll(n))
template <class... T>
void print(T&&... n) {
    using exp = int[];
    exp{0, (cout << n << sp, 0)...};
    cout << endl;
}
template <class T>
void mxmz(T &a, T b) { a = max(a, b); }
template <class T>
void mnmz(T &a, T b) { a = min(a, b); }
const int N = 1e6;
const ll MOD = 1e9 + 7;
const ull BASE = 311;
const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
const int dx[8] = {0, -1, 0, 1, -1, -1, 1, 1};
const int dy[8] = {-1, 0, 1, 0, -1, 1, 1, -1};

//incomplete

int n, m, amx;
vector<vector<int>> a;
////////////////////////////////////////
struct sub2 {
    sub2(){
        vector<vector<int>> mx(n + 1, vector<int>(m + 1));
        For(i, 1, n) {
            mx[i][m] = m;
            Ford(j, m - 1, 1) {
                if (a[i][j] == a[i][j + 1]) {
                    mx[i][j] = mx[i][j + 1];
                } else {
                    mx[i][j] = j;
                }
            }
        }
        
        ll ans = 0;
        For(i, 1, n) {
            For(j, 1, m) {
                int mn = m;
                For(k, i, n) {
                    if (a[i][j] != a[k][j]) break;
                    mnmz(mn, mx[k][j]);
                    ans += mn - j + 1;
                }
            }
        }
        
        cout << ans;
    }
};
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////
    cin >> n >> m;
    a.resize(n + 1, vector<int>(m + 1));
    For(i, 1, n) For(j, 1, m) {
        cin >> a[i][j];
        amx = max(amx, a[i][j]);
    }
    
    sub2();
    ////////////////
    return 0;
}