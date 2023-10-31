#if DEBUG
    #include "lib/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "harem"
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
#define blog2(n) (63 - __builtin_clzll(n))
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
bool mxmz(T &a, T& b) { return (a < b ? a = b, 1 : 0); }
template <class T>
bool mnmz(T &a, T& b) { return (b < a ? a = b, 1 : 0); }
void add(ll &a, ll b) { a = (a + b) % MOD; }
void sub(ll &a, ll b) { a = (a + MOD - b) % MOD; }
void mul(ll &a, ll b) { a = a * (b % MOD) % MOD; }

// https://gspvh23.contest.codeforces.com/group/FIWwc7nF6c/contest/479930/problem/F
// graph

int n, m;
vector<vector<int>> adj;
vector<int> ans;
////////////////////////////////////////
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////////
    cin >> n >> m;
    vector<pii> edges(m);
    Rep(i, m) cin >> edges[i].fi >> edges[i].se;
    
    auto solve = [&](int k) {
        adj.assign(n + 1, {});
        vector<int> deg(n + 1);
        
        Rep(i, k) {
            int u = edges[i].fi, v = edges[i].se;
            adj[u].push_back(v);
            deg[v]++;
        }
        
        ans.assign(n + 1, 0);
        deque<int> q;
        For(i, 1, n) if (deg[i] == 0) {
            ans[i] = 1;
            q.push_back(i);
        }
        if (q.size() != 1) return;
        
        while (q.size()) {
            int cur = q.back();
            q.pop_back();
            
            Forin(nxt, adj[cur]) {
                if (--deg[nxt] == 0) {
                    ans[nxt] = ans[cur] + 1;
                    q.push_front(nxt);
                }
            }
        }
    };
    
    int al = 1, ar = m + 1;
    while (al < ar) {
        int am = (al + ar) / 2;
        solve(am);
        
        if (*max_element(all(ans)) == n) {
            ar = am;
        } else {
            al = am + 1;
        }
    }
    
    if (al > m) {
        cout << -1;
    } else {
        solve(al);
        cout << al << nl;
        For(i, 1, n) cout << ans[i] << sp;
    }
    ////////////////////
    return 0;
}