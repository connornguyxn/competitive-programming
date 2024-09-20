#pragma GCC optimize("O3")
#include "bits/stdc++.h"
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
#define FOR(i, l, r) for (int i = (l), _r = (r); i <= _r; i++)
#define FORD(i, r, l) for (int i = (r), _l = (l); i >= _l; i--)
#define FORIN(it, a) for (auto& it : a)
#define bmask(i) (1LL << (i))
#define bget(i, n) ((n) >> (i) & 1)
#define bon(i, n) ((n) | bmask(i))
#define boff(i, n) ((n) & ~bmask(i))
const ll MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ull N = 1e6 + 3;
template <class T>
using vector2 = vector<vector<T>>;
template <class T>
using vector3 = vector<vector2<T>>;
template <class T, class... C>
void assign(int n, T v, C&&... a) {
    using e = int[];
    e{(a.assign(n, v), 0)...};
}
template <class... C>
void resize(int n, C&&... a) {
    using e = int[];
    e{(a.resize(n), 0)...};
}
template <class... T>
void print(T&&... a) {
    cout << "[debug] ";
    using e = int[];
    e{(cout << a << sp, 0)...};
    cout << endl;
}
template <class Ch, class Tr, class C>
basic_ostream<Ch, Tr>& operator<<(basic_ostream<Ch, Tr>& cout, C& a) {
    cout << "{ ";
    FORIN(it, a) cout << it << sp;
    return cout << "}";
}
template <class T1, class T2>
ostream& operator<<(ostream& cout, pair<T1, T2>& a) {
    return cout << '(' << a.fi << sp << a.se << ')';
}

// https://lqdoj.edu.vn/problem/lqdoj2023r1wireless
// graph, tree, incomplete

struct Path {
    int n;
    ll w;
};
int n, q;
vector2<Path> adj;
vector2<int> qs;
////////////////////////////////////////////////////////////////////////////////
namespace sub3 {
    int lg, timer = 1;
    vector2<int> up;
    vector<int> tin, tout;
    vector<ll> sum;
    
    bool is_ansc(int u, int v) {
        return tin[u] <= tin[v] && tout[v] <= tout[u];
    }
    
    int lca(int u, int v) {
        if (is_ansc(u, v)) return u;
        if (is_ansc(v, u)) return v;
        FORD(i, lg, 0) {
            if (!is_ansc(up[i][v], u)) v = up[i][v];
        }
        return up[0][v];
    }
    
    void dfs(int cur, int pre) {
        tin[cur] = timer++;
        up[0][cur] = pre;
        FOR(i, 1, lg) {
            up[i][cur] = up[i - 1][up[i - 1][cur]];
        }
        
        FORIN(nxt, adj[cur]) if (nxt.n != pre) {
            sum[nxt.n] = sum[cur] + nxt.w;
            dfs(nxt.n, cur);
        }
        tout[cur] = timer++;
    }
    
    void main() {
        lg = __lg(n) + 1;
        up.resize(lg + 1, vector<int>(n + 1));
        
        resize(n + 1, tin, tout, sum);
        dfs(1, 1);
        
        FORIN(cq, qs) {
            ll ans = INFLL;
            FOR(cur, 1, n) {
                ll res = 0;
                FORIN(it, cq) {
                    res += sum[cur] + sum[it] - sum[lca(cur, it)] * 2;
                }
                ans = min(ans, res);
            }
            cout << ans << nl;
        }
    }
}
////////////////////////////////////////////////////////////////////////////////
int main() {
    // #define TASK "test"
    #define TASK "wireless"
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    ////////////////////////////////////////
    cin >> n >> q;
    
    resize(n + 1, adj);
    
    FOR(i, 1, n - 1) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    resize(q, qs);
    FORIN(it, qs) {
        int k;
        cin >> k;
        it.resize(k);
        FORIN(jt, it) cin >> jt;
    }
    
    return sub3::main(), 0;
    ////////////////////////////////////////
}