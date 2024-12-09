#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using str = string;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template <class T>
using vector2 = vector<vector<T>>;
template <class T>
using vector3 = vector<vector2<T>>;
#define sp ' '
#define nl '\n'
#define fi first
#define se second
#define size(a) ((int)(a).size())
#define all(a) begin(a), end(a)
#define tvl (tv * 2)
#define tvr (tv * 2 + 1)
#define FOR(i, l, r) for (int i = (l), _r = (r); i <= _r; i++)
#define FORD(i, r, l) for (int i = (r), _l = (l); i >= _l; i--)
#define FORIN(it, a) for (auto& it : a)
#define bmask(i) (1LL << (i))
#define bget(i, n) ((n) >> (i) & 1)
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9 + 7;
void addm(ll& a, ll b) { a = (a + b % MOD) % MOD; }
void subm(ll& a, ll b) { a = (a + MOD - b % MOD) % MOD; }
void mulm(ll& a, ll b) { a = a * (b % MOD) % MOD; }
template <class T, class... C>
void minimize(T& a, C&&... v) {
    a = min<T>({a, v...});
}
template <class T, class... C>
void maximize(T& a, C&&... v) {
    a = max<T>({a, v...});
}
template <class T, class... C>
void assign(int n, const T& v, C&&... a) {
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
    cout << flush;
    clog << "\n[debug] ";
    using e = int[];
    e{(clog << a << sp, 0)...};
    clog << endl;
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
void logtime() {
    print("[time]", clock() * 1.0 / CLOCKS_PER_SEC);
}


// https://usaco.org/index.php?page=viewproblem2&cpid=817
// centroids, tree


int n, q;
vector2<int> adj;
vector<pair<char, int>> qs;
///////////////////////////////////////////////////////////////////////////////
namespace sub1 {
    int lg, timer;
    vector<int> del, par, size, tin, tout, depth;
    vector2<int> up;
    ////////////////////////////////////////
    void dfs(int cur, int pre) {
        tin[cur] = ++timer;
        depth[cur] = depth[pre] + 1;
        
        up[0][cur] = pre;
        FOR(i, 1, lg) {
            up[i][cur] = up[i - 1][up[i - 1][cur]];
        }
        
        FORIN(nxt, adj[cur]) if (nxt != pre) {
            dfs(nxt, cur);
        }
        
        tout[cur] = timer;
    }
    ////////////////////////////////////////
    bool is_ancestor(int u, int v) {
        return tin[u] <= tin[v] && tout[v] <= tout[u];
    }
    ////////////////////////////////////////
    int lca(int u, int v) {
        if (is_ancestor(u, v)) return u;
        if (is_ancestor(v, u)) return v;
        FORD(i, lg, 0) {
            if (!is_ancestor(up[i][u], v)) u = up[i][u];
        }
        return up[0][u];
    }
    ////////////////////////////////////////
    int dist(int u, int v) {
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }
    ////////////////////////////////////////
    void calc_size(int cur, int pre) {
        size[cur] = 1;
        FORIN(nxt, adj[cur]) {
            if (nxt == pre || del[nxt]) continue;
            calc_size(nxt, cur);
            size[cur] += size[nxt];
        }
    }
    ////////////////////////////////////////
    int centroid(int cur, int pre, int s) {
        FORIN(nxt, adj[cur]) {
            if (nxt == pre || del[nxt]) continue;
            if (size[nxt] > s) return centroid(nxt, cur, s);
        }
        return cur;
    }
    ////////////////////////////////////////
    vector2<int> subtree_nodes;
    ////////////////////////////////////////
    void dcmp(int cur) {
        del[cur] = 1;
        
        subtree_nodes[cur].push_back(cur);
        
        FORIN(nxt, adj[cur]) {
            if (del[nxt]) continue;
            calc_size(nxt, nxt);
            int c = centroid(nxt, nxt, size[nxt] / 2);
            par[c] = cur;
            dcmp(c);
            copy(all(subtree_nodes[c]), back_inserter(subtree_nodes[cur]));
        }
    }
    ////////////////////////////////////////
    vector<array<pii, 2>> max_dist;
    vector<int> active;
    ////////////////////////////////////////
    void maximize_dist(array<pii, 2>& a, pii b) {
        if (b.fi >= a[0].fi) {
            if (b.se == a[0].se) {
                a[0].fi = b.fi;
            } else {
                a[1] = exchange(a[0], b);
            }
        } else if (b.fi > a[1].fi && b.se != a[0].se) {
            a[1] = b;
        }
    }
    ////////////////////////////////////////
    void update(int u) {
        int cur = par[u], child = u;
        while (cur) {
            if (active[cur]) {
                maximize_dist(max_dist[cur], {dist(cur, u), child});
            }
            child = exchange(cur, par[cur]);
        }
    }
    ////////////////////////////////////////
    int get(int u) {
        int res = max_dist[u][0].fi;
        
        int cur = par[u], child = u;
        while (cur) {
            if (active[cur]) {
                int mxd = (max_dist[cur][0].se == child ? max_dist[cur][1].fi : max_dist[cur][0].fi);
                maximize(res, mxd + dist(cur, u));
            }
            child = exchange(cur, par[cur]);
        }
        
        return res;
    }
    ////////////////////////////////////////
    void main() {
        resize(n + 1, del, par, size, depth, tin, tout, active, subtree_nodes);
        lg = __lg(n);
        up.assign(lg + 1, vector<int>(n + 1));
        
        FOR(i, 1, n) {
            if (tin[i] == 0) {
                dfs(i, i);
            }
        }
        
        FOR(i, 1, n) {
            if (del[i]) continue;
            calc_size(i, i);
            dcmp(centroid(i, i, size[i] / 2));
        }
        
        max_dist.assign(n + 1, {pii{-1, 0}, {-1, 0}});
        
        FORIN(cq, qs) {
            int u = cq.se;
            
            if (cq.fi == 'B') {
                active[u] = 1;
                maximize_dist(max_dist[u], {0, 0});
                update(u);
                
                FORIN(it, subtree_nodes[u]) {
                    if (active[it]) {
                        update(it);
                    }
                }
            } else {
                cout << get(u) << nl;
            }
        }
    }
    bool run() {
        return main(), 1;
    }
}
////////////////////////////////////////////////////////////////////////////////
int main() {
    #define TASK "newbarn"
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    atexit(logtime);
    ////////////////////////////////////////
    cin >> q;
    
    resize(q, qs);
    adj.resize(1);
    
    FORIN(it, qs) {
        cin >> it.fi >> it.se;
        if (it.fi == 'B') {
            n++;
            adj.emplace_back();
            if (it.se > 0) {
                adj[n].push_back(it.se);
                adj[it.se].push_back(n);
            }
            it.se = n;
        }
    }
    
    if (sub1::run()) return 0;
    ////////////////////////////////////////
    return 0;
}