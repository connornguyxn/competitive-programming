#if DEBUG
    #include "lib/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "abjob"
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

// https://hnoj.edu.vn/contest/lqtbr2/
// graph, bimatching

struct Job {
    int s, a, b;
};
int n, m;
vector<Job> job;
vector<vector<int>> adj;
vector<int> mat;
vector<bool> vis;
////////////////////////////////////////
bool try_kuhn(int cur) {
    if (vis[cur]) return false;
    vis[cur] = true;
    Forin(nxt, adj[cur]) {
        if (mat[nxt] == -1 || try_kuhn(mat[nxt])) {
            mat[nxt] = cur;
            return true;
        }
    }
    return false;
}
////////////////////////////////////////
bool check(int e) {
    adj.assign(n, {});
    Rep(i, n) {
        Rep(j, n) {
            if (i == j) continue;
            if (job[i].b <= job[j].a && abs(job[i].s - job[j].s) <= e) adj[i].push_back(j);
        }
    }
    // print(adj);
    
    mat.assign(n, -1);
    Rep(i, n) {
        vis.assign(n, false);
        try_kuhn(i);
    }
    
    int res = 0;
    Rep(i, n) res += (mat[i] != -1);
    // print(res);
    return (m + res) >= n;
}
////////////////////////////////////////
int main() {
    // freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////////
    cin >> n >> m;
    
    job.resize(n);
    Rep(i, n) {
        cin >> job[i].s >> job[i].a >> job[i].b;
    }
    
    int al = 0, ar = INF;
    while (al < ar) {
        int am = (al + ar) / 2;
        if (check(am)) {
            ar = am;
        } else {
            al = am + 1;
        }
    }
    cout << (al < INF ? al : -1);
    ////////////////////
    return 0;
}