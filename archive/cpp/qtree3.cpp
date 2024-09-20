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
#define FOR1(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FOR2(i, l, r) for (int i = (l), _r = (r); i <= _r; i++)
#define FOR3(i, r, l, sp) for (int i = (r), _l = (l); i >= _l; i--)
#define OVERLOAD(a, b, c, d, e, ...) e
#define FOR(...) OVERLOAD(__VA_ARGS__, FOR3, FOR2, FOR1)(__VA_ARGS__)
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

// https://www.spoj.com/problems/QTREE3/en/
// hld, graph, tree

#define left tv * 2
#define right tv * 2 + 1

int n, q;
vector2<int> adj;
vector<pii> qs;
////////////////////////////////////////////////////////////////////////////////
namespace full {
    vector<int> st, par, depth, head, hev, pos;
    int timer = 0;
    ////////////////////////////////////////
    int combine(int u, int v) {
        if (u == INF) return v;
        if (v == INF) return u;
        if (depth[u] > depth[v]) return v;
        return u;
    }
    ////////////////////////////////////////
    void st_update(int p, int v, int tl = 0, int tr = n - 1, int tv = 1) {
        if (tl == tr) {
            st[tv] = v;
            return;
        }
        int tm = (tl + tr) / 2;
        if (p <= tm) st_update(p, v, tl, tm, left);
        else st_update(p, v, tm + 1, tr, right);
        st[tv] = combine(st[left], st[right]);
    }
    ////////////////////////////////////////
    int st_get(int l, int r, int tl = 0, int tr = n - 1, int tv = 1) {
        if (r < tl || tr < l) return INF;
        if (l <= tl && tr <= r) {
            return st[tv];
        }
        int tm = (tl + tr) / 2;
        int lq = st_get(l, r, tl, tm, left);
        int rq = st_get(l, r, tm + 1, tr, right);
        return combine(lq, rq);
    }
    ////////////////////////////////////////
    int dfs(int cur) {
        int size = 1, mx = 0;
        
        FORIN(nxt, adj[cur]) if (nxt != par[cur]) {
            par[nxt] = cur;
            depth[nxt] = depth[cur] + 1;
            int s = dfs(nxt);
            size += s;
            if (s > mx) {
                mx = s;
                hev[cur] = nxt;
            }
        }
        
        return size;
    }
    ////////////////////////////////////////
    void decompose(int cur, int chead) {
        pos[cur] = timer++;
        head[cur] = chead;
        
        if (hev[cur] != -1) decompose(hev[cur], chead);
        FORIN(nxt, adj[cur]) if (nxt != par[cur] && nxt != hev[cur]) {
            decompose(nxt, nxt);
        }
    }
    ////////////////////////////////////////
    int hld_get(int u, int v) {
        int res = INF;
        while (head[u] != head[v]) {
            if (depth[head[u]] > depth[head[v]]) swap(u, v);
            res = combine(res, st_get(pos[head[v]], pos[v]));
            v = par[head[v]];
        }
        if (depth[u] > depth[v]) swap(u, v);
        return combine(res, st_get(pos[u], pos[v]));
    }
    ////////////////////////////////////////
    void main() {
        assign(n + 1, -1, par, depth, head, hev, pos);
        
        depth[1] = 1;
        dfs(1);
        decompose(1, 1);
        
        st.assign(n * 4, INF);
        vector<int> val(n + 1, INF);
        
        FORIN(it, qs) {
            // print(it);
            if (it.fi == 0) {
                val[it.se] = (val[it.se] == INF ? it.se : INF);
                st_update(pos[it.se], val[it.se]);
            } else {
                int res = hld_get(1, it.se);
                cout << (res < INF ? res : -1) << nl;
            }
        }
    }
};
////////////////////////////////////////////////////////////////////////////////
int main() {
    #define TASK "test"
    // #define TASK "qtree3"
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    ////////////////////////////////////////
    cin >> n >> q;
    
    resize(n + 1, adj);
    FOR(i, n - 1) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    qs.resize(q);
    FORIN(it, qs) cin >> it.fi >> it.se;
    
    return full::main(), 0;
    ////////////////////////////////////////
}