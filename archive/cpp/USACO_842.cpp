#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
using str = string;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template <class T>
using vector2 = vector<vector<T>>;
template <class T>
using vector3 = vector<vector2<T>>;
#define fi first
#define se second
#define nl '\n'
#define sp ' '
#define all(a) (a).begin(), (a).end()
#define lnode (tv * 2)
#define rnode (tv * 2 + 1)
#define FOR(i, l, r) for (int i = (l), _r = (r); i <= _r; i++)
#define FORD(i, r, l) for (int i = (r), _l = (l); i >= _l; i--)
#define FORIN(it, a) for (auto& it : a)
#define bmask(i) (1LL << (i))
#define bget(i, n) ((n) >> (i) & 1)
const ll MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
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
void add(ll& a, ll b) { a = (a + b) % MOD; }
void sub(ll& a, ll b) { a = (a + MOD * MOD - b) % MOD; }
void mul(ll& a, ll b) { a = a * (b % MOD) % MOD; }
////////////////////////////////////////
template <class... T>
void print(T&&... a) {
    cout << "[debug] ";
    using e = int[];
    e{(cout << a << sp, 0)...};
    cout << endl;
}
template <class Ch, class Tr, class C>
basic_ostream<Ch, Tr>& operator<<(basic_ostream<Ch, Tr>& cout, C a) {
    cout << "{ ";
    FORIN(it, a) cout << it << sp;
    return cout << "}";
}
template <class T1, class T2>
ostream& operator<<(ostream& cout, pair<T1, T2> a) {
    return cout << '(' << a.fi << sp << a.se << ')';
}

// https://vjudge.net/problem/USACO-842
// hld, tree

struct Edge {
    int u, v, w;
};
int n, m;
vector2<int> adj;
vector<Edge> e;
vector<pii> edges;
////////////////////////////////////////////////////////////////////////////////
namespace sub1 {
    int timer;
    vector<int> pos, par, head, hev, depth;
    
    int dfs(int cur) {
        int s = 1, mx = 0;
        
        FORIN(nxt, adj[cur]) if (nxt != par[cur]) {
            depth[nxt] = depth[cur] + 1;
            par[nxt] = cur;
            int cs = dfs(nxt);
            s += cs;
            if (cs > mx) {
                mx = cs;
                hev[cur] = nxt;
            }
        }
        
        return s;
    }
    
    void dcmp(int cur, int chead) {
        head[cur] = chead;
        pos[cur] = ++timer;
        
        if (hev[cur]) dcmp(hev[cur], chead);
        FORIN(nxt, adj[cur]) if (nxt != par[cur] && nxt != hev[cur]) {
            dcmp(nxt, nxt);
        }
    }
    
    vector<int> st, lz;
    void st_push(int tv) {
        st[lnode] = min(st[lnode], lz[tv]);
        st[rnode] = min(st[rnode], lz[tv]);
        
        lz[lnode] = min(lz[lnode], lz[tv]);
        lz[rnode] = min(lz[rnode], lz[tv]);
        
        lz[tv] = INF;
    }
    
    void st_update(int l, int r, int v, int tl = 1, int tr = n, int tv = 1) {
        if (r < tl || tr < l) return;
        if (l <= tl && tr <= r) {
            st[tv] = min(st[tv], v);
            lz[tv] = min(lz[tv], v);
            return;
        }
        st_push(tv);
        int tm = (tl + tr) / 2;
        st_update(l, r, v, tl, tm, lnode);
        st_update(l, r, v, tm + 1, tr, rnode);
        st[tv] = min(st[lnode], st[rnode]);
    }
    
    int st_get(int l, int r, int tl = 1, int tr = n, int tv = 1) {
        if (r < tl || tr < l) return INF;
        if (l <= tl && tr <= r) {
            return st[tv];
        }
        st_push(tv);
        int tm = (tl + tr) / 2;
        return min(st_get(l, r, tl, tm, lnode), st_get(l, r, tm + 1, tr, rnode));
    }
    
    void hld_update(int u, int v, int val) {
        while (head[u] != head[v]) {
            if (depth[head[u]] > depth[head[v]]) swap(u, v);
            st_update(pos[head[v]], pos[v], val);
            v = par[head[v]];
        }
        if (depth[u] > depth[v]) swap(u, v);
        st_update(pos[u] + 1, pos[v], val);
    }
    
    int hld_get(int u, int v) {
        int res = INF;
        while (head[u] != head[v]) {
            if (depth[head[u]] > depth[head[v]]) swap(u, v);
            res = min(res, st_get(pos[head[v]], pos[v]));
            v = par[head[v]];
        }
        if (depth[u] > depth[v]) swap(u, v);
        return min(res, st_get(pos[u] + 1, pos[v]));
    }
    
    void main() {
        resize(n + 1, par, head, hev, depth, pos);
        dfs(1);
        dcmp(1, 1);
        
        assign(n * 4, INF, st, lz);
        FORIN(it, e) {
            hld_update(it.u, it.v, it.w);
        }
        
        FORIN(it, edges) {
            int ans = hld_get(it.fi, it.se);
            cout << (ans < INF ? ans : -1) << nl;
        }
    }
}
////////////////////////////////////////////////////////////////////////////////
int main() {
    // #define TASK "test"
    #define TASK "disrupt"
    freopen(TASK".in", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    ////////////////////////////////////////
    cin >> n >> m;
    
    resize(n + 1, adj);
    FOR(i, 2, n) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.push_back({u, v});
    }
    
    resize(m, e);
    FORIN(it, e) {
        cin >> it.u >> it.v >> it.w;
    }
    
    return sub1::main(), 0;
    ////////////////////////////////////////
}