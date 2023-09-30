#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "c11comp"
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
#define bmask(i) (1ULL << (i))
#define bget(mask, i) ((mask >> (i)) & 1)
#define blog(n) (63 - __builtin_clzll(n))
template <class T = int>
T inp() { T x; cin >> x; return x; }
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
const ull MOD = 1e9 + 7;
const ull BASE = 311;
const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
const int dx[8] = {0, -1, 0, 1, -1, -1, 1, 1};
const int dy[8] = {-1, 0, 1, 0, -1, 1, 1, -1};

// https://oj.vnoi.info/problem/c11comp
// graph, dfs, decomposition, offline

struct query {
    int l, r, p;
};
int n, m, k;
vector<vector<int>> adj;
vector<int> val, pl, pr, pos;
////////////////////////////////////////
void dfs(int cur) {
    pl[cur] = pos.size();
    pos.push_back(cur);
    Forin(nxt, adj[cur]) dfs(nxt);
    pr[cur] = pos.size() - 1;
}
////////////////////////////////////////
int main() {
    // freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////
    cin >> n >> m >> k;
    
    adj.resize(n + 1);
    Fore(i, 2, n) {
        int u;
        cin >> u;
        adj[u].push_back(i);
    }
    
    val.resize(n + 1);
    Fore(i, 1, n) cin >> val[i];
    
    pos.reserve(n + 1);
    pl.resize(n + 1);
    pr.resize(n + 1);
    dfs(1);
    
    int q;
    cin >> q;
    vector<query> queries;
    Rep(i, q) {
        int u;
        cin >> u;
        queries.push_back({pl[u], pr[u], i});
    }
    
    int blk = sqrt(n);
    sort(all(queries), [&](query a, query b) {
        if (a.l / blk != b.l / blk) return a.l < b.l;
        return a.r < b.r;
    });
    
    vector<int> ans(q);
    int cur = 0;
    unordered_map<int, int> cnt;
    
    int l = 1, r = 0;
    Forin(qr, queries) {
        // print(qr.l, qr.r, qr.p);
        while (l > qr.l) {
            l--;
            cnt[val[pos[l]]]++;
            if (cnt[val[pos[l]]] == 1) cur++;
            if (cnt[val[pos[l]]] == k + 1) cur--;
        }
        while (r < qr.r) {
            r++;
            cnt[val[pos[r]]]++;
            if (cnt[val[pos[r]]] == 1) cur++;
            if (cnt[val[pos[r]]] == k + 1) cur--;
        }
        while (l < qr.l) {
            cnt[val[pos[l]]]--;
            if (cnt[val[pos[l]]] == 0) cur--;
            if (cnt[val[pos[l]]] == k) cur++;
            l++;
        }
        while (r > qr.r) {
            cnt[val[pos[r]]]--;
            if (cnt[val[pos[r]]] == 0) cur--;
            if (cnt[val[pos[r]]] == k) cur++;
            r--;
        }
        ans[qr.p] = cur;
    }
    
    Forin(x, ans) cout << x << nl;
    ////////////////
    return 0;
}