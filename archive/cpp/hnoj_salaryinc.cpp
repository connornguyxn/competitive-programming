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
#define bon(i, n) ((n) | bmask(i))
#define boff(i, n) ((n) & ~bmask(i))
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

// https://hnoj.edu.vn/problem/salaryinc
// graph, offline, segtree

struct Q {
    int p, u, id, type;
    bool operator<(const Q& o) const {
        return p < o.p;
    }
};
int n, m, q;
vector2<int> adj;
int timer;
vector<int> tin, tout;
vector<ll> st, lz;
////////////////////////////////////////////////////////////////////////////////
void dfs(int cur) {
    tin[cur] = ++timer;
    FORIN(nxt, adj[cur]) dfs(nxt);
    tout[cur] = timer;
}
////////////////////////////////////////
void push(int tv) {
    st[lnode] += lz[tv];
    st[rnode] += lz[tv];
    lz[lnode] += lz[tv];
    lz[rnode] += lz[tv];
    lz[tv] = 0;
}
////////////////////////////////////////
void update(int l, int r, ll v, int tl = 1, int tr = n, int tv = 1) {
    if (tr < l || r < tl) return;
    if (l <= tl && tr <= r) {
        st[tv] += v;
        lz[tv] += v;
        return;
    }
    int tm = (tl + tr) / 2;
    push(tv);
    update(l, r, v, tl, tm, lnode);
    update(l, r, v, tm + 1, tr, rnode);
    st[tv] = min(st[tv * 2], st[tv * 2 + 1]);
}
////////////////////////////////////////
ll get(int p, int tl = 1, int tr = n, int tv = 1) {
    if (tl == tr) {
        return st[tv];
    }
    int tm = (tl + tr) / 2;
    push(tv);
    if (p <= tm) return get(p, tl, tm, lnode);
    return get(p, tm + 1, tr, rnode);
}
////////////////////////////////////////////////////////////////////////////////
int main() {
    #define TASK "test"
    // #define TASK "hnoj_salaryinc"
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    ////////////////////////////////////////
    cin >> n >> m >> q;
    
    resize(n + 1, adj);
    FOR(i, 2, n) {
        int p;
        cin >> p;
        adj[p].push_back(i);
    }
    
    vector<pll> b(m + 1);
    FOR(i, 1, m) cin >> b[i].fi >> b[i].se;
    
    vector<Q> qs;
    FOR(i, 1, q) {
        int l, r, u;
        cin >> l >> r >> u;
        qs.push_back({l - 1, u, i, -1});
        qs.push_back({r, u, i, 1});
    }
    sort(all(qs));
    
    resize(n + 1, tin, tout);
    dfs(1);
    resize(n * 4, st, lz);
    
    vector<ll> ans(q + 1);
    int idx = 0;
    FORIN(cq, qs) {
        while (idx < cq.p) {
            idx++;
            update(tin[b[idx].fi], tout[b[idx].fi], b[idx].se);
        }
        ans[cq.id] += cq.type * get(tin[cq.u]);
    }
    
    FOR(i, 1, q) cout << ans[i] << nl;
    ////////////////////////////////////////
}