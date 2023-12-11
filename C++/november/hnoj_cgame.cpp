#if DEBUG
    #include "lib/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "cgame"
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

// hnoj_cgame
// <tags>

int n, ans;
vector<vector<int>> a;
vector<int> dst;
////////////////////////////////////////
int find_dst(int cur, int pre) {
    if (a[cur].size() == 1) return dst[cur] = 0;
    for (int nxt : a[cur]) if (nxt != pre) {
        mnmz(dst[cur], find_dst(nxt, cur) + 1);
    }
    return dst[cur];
}
////////////////////////////////////////
int solve(int cur, int pre, int cst) {
    if (cst == dst[cur]) {
        // print(cur);
        return 1;
    }
    int res = 0;
    Forin(nxt, a[cur]) if (nxt != pre) {
        res += solve(nxt, cur, cst + 1);
    }
    return res;
}
////////////////////////////////////////
int main() {
    // freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////////
    cin >> n;
    
    a.resize(n + 1);
    Rep(i, n - 1) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    
    dst.assign(n + 1, INF);
    find_dst(1, 1);
    
    // print(dst);
    cout << solve(1, 1, 0);
    ////////////////////
    return 0;
}