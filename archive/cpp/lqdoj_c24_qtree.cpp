#include <bits/stdc++.h>
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
#define tvl (tv * 2)
#define tvr (tv * 2 + 1)
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

// https://lqdoj.edu.vn/contest/lqdojcup2024r1
// dp, tree, prefixsum

int n, q, t, m;
vector2<int> adj;
struct Q {
    int u, v;
    ll k;
};
vector<Q> qs;
vector<pii> ts;
////////////////////////////////////////////////////////////////////////////////
namespace subf {
    vector<int> val, depth, tin, tout, tour, child;
    vector2<int> st;
    ////////////////////////////////////////
    void dfs(int cur, int pre) {
        tin[cur] = tour.size();
        tour.push_back(cur);
        
        FORIN(nxt, adj[cur]) if (nxt != pre) {
            depth[nxt] = depth[cur] + 1;
            dfs(nxt, cur);
            tour.push_back(cur);
        }
        
        tout[cur] = tour.size() - 1;
    }
    ////////////////////////////////////////
    void buildsum(int cur, int pre) {
        FORIN(nxt, adj[cur]) if (nxt != pre) {
            buildsum(nxt, cur);
            val[cur] += val[nxt];
        }
    }
    ////////////////////////////////////////
    int cmp(int u, int v) {
        return depth[u] < depth[v] ? u : v;
    }
    ////////////////////////////////////////
    int lca(int u, int v) {
        if (tin[u] > tin[v]) swap(u, v);
        int lg = __lg(tin[v] - tin[u] + 1);
        return cmp(st[lg][tin[u]], st[lg][tin[v] - bmask(lg) + 1]);
    }
    ////////////////////////////////////////
    vector2<ll> dp;
    void solve(int cur, int pre) {
        child[cur] = 1;
        fill(all(dp[cur]), 0);
        
        FORIN(nxt, adj[cur]) if (nxt != pre) {
            solve(nxt, cur);
            
            FORD(i, min(child[cur] + child[nxt], m), 1) {
                FOR(j, max(1, i - child[cur]), min(child[nxt], i)) {
                    dp[cur][i] = max({
                        dp[cur][i],
                        dp[cur][i - j] + dp[nxt][j - 1] + val[nxt]
                    });
                }
            }
            
            child[cur] += child[nxt];
        }
    }
    ////////////////////////////////////////
    void main() {
        resize(n + 1, tin, tout, depth, child);
        tour = {0};
        dfs(1, 0);
        
        int lg = __lg(n) + 1;
        st.assign(lg + 1, vector<int>(tour.size()));
        st[0] = tour;
        
        FOR(i, 1, lg) {
            FOR(j, 1, tour.size() - bmask(i)) {
                st[i][j] = cmp(st[i - 1][j], st[i - 1][j + bmask(i - 1)]);
            }
        }
        
        // print(depth);
        // print(tour);
        
        dp.resize(n + 1, vector<ll>(m + 1));
        
        FORIN(ct, ts) {
            assign(n + 1, 0, val);
            
            FOR(i, ct.fi, ct.se) {
                val[qs[i].u] += qs[i].k;
                val[qs[i].v] += qs[i].k;
                val[lca(qs[i].u, qs[i].v)] -= qs[i].k * 2;
            }
            buildsum(1, 0);
            
            // print(val);
            
            solve(1, 0);
            
            // FOR(i, 0, n) print(i, dp[i]);
            
            ll ans = 0;
            FOR(i, 1, n) ans = max(ans, dp[i][m]);
            cout << ans << nl;
        }
    }
}
////////////////////////////////////////////////////////////////////////////////
int main() {
    #define TASK "qtree"
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    ////////////////////////////////////////
    cin >> n >> q >> t >> m;
    
    resize(n + 1, adj);
    FOR(i, 2, n) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    resize(q + 1, qs);
    FOR(i, 1, q) {
        cin >> qs[i].u >> qs[i].v >> qs[i].k;
    }
    
    resize(t, ts);
    FORIN(it, ts) cin >> it.fi >> it.se;
    
    return subf::main(), 0;
    ////////////////////////////////////////
}