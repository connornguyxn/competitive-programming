#if DEBUG
    #include "lib/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "temple"
#endif
using namespace std;
using ll = long long;
using ull = unsigned long long;
using str = string;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define fi first
#define se second
#define nl '\n'
#define sp ' '
#define all(a) (a).begin(), (a).end()
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define Repd(i, n) for (int i = (n); i--; )
#define For(i, l, r) for (int i = (l), _r = (r); i <= _r; i++)
#define Fors(i, l, r) for (int i = (l), _r = (r); i < _r; i++)
#define Ford(i, r, l) for (int i = (r) + 1, _l = (l); --i >= _l; )
#define Forin(it, var) for (auto& it : var)
#define bmask(i) (1ULL << (i))
#define bget(mask, i) ((mask >> (i)) & 1)
const int N = 1e6;
const ll MOD = 1e9 + 7;
const ull BASE = 311;
const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
const int dx[8] = {0, -1, 0, 1, -1, -1, 1, 1};
const int dy[8] = {-1, 0, 1, 0, -1, 1, 1, -1};
template <class... T>
void print(T&&... n) {
    using exp = int[];
    exp{0, (cout << n << sp, 0)...};
    cout << endl;
}
template <class T>
bool mxmz(T &a, T b) { return a < b ? a = b, 1 : 0; }
template <class T>
bool mnmz(T &a, T b) { return b < a ? a = b, 1 : 0; }
void add(ll &a, ll b) { a = (a + b) % MOD; }
void sub(ll &a, ll b) { a = (a + MOD - b) % MOD; }
void mul(ll &a, ll b) { a = a * (b % MOD) % MOD; }

// https://oj.vnoi.info/problem/chvpt_temple
// math, bruteforce, 2d, geometry

////////////////////////////////////////
////////////////////////////////////////
int main() {
    // freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////////
    int n;
    cin >> n;
    
    vector<pii> a(n);
    vector<vector<bool>> mark(5001, vector<bool>(5001));
    
    Rep(i, n) {
        cin >> a[i].fi >> a[i].se;
        mark[a[i].fi][a[i].se] = 1;
    }
    
    int ans = 0;
    Rep(i, n - 1) {
        Fors(j, i + 1, n) {
            int x1 = a[i].fi, y1 = a[i].se;
            int x2 = a[j].fi, y2 = a[j].se;
            int dx = x2 - x1, dy = y2 - y1;
            if (x1 - dy >= 0 && x1 - dy <= 5000 && y1 + dx >= 0 && y1 + dx <= 5000 && mark[x1 - dy][y1 + dx]
            && x2 - dy >= 0 && x2 - dy <= 5000 && y2 + dx >= 0 && y2 + dx <= 5000 && mark[x2 - dy][y2 + dx]) {
                mxmz(ans, dx * dx + dy * dy);
            }
        }
    }
    
    cout << ans;
    ////////////////////
    return 0;
}