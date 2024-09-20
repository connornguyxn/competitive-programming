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

// https://dmoj.ca/problem/cco24p1
// graph, tree, dp, dijkstra

struct P {
    int n;
    ll w;
    bool operator<(const P& o) const {
        return w > o.w;
    }
};
int n, m;
vector<ll> v;
vector2<P> adj;
////////////////////////////////////////////////////////////////////////////////
namespace sub1 {
    void solve(int cur) {
        vector<ll> res(n + 1, INFLL);
        priority_queue<P> pq;
        pq.push({cur, 0});
        res[cur] = 0;
        
        ll ans = 0;
        
        while (pq.size()) {
            P cur = pq.top();
            pq.pop();
            
            ans = max(ans, v[cur.n] -res[cur.n]);
            
            FORIN(nxt, adj[cur.n]) {
                if (res[nxt.n] > cur.w + nxt.w) {
                    res[nxt.n] = cur.w + nxt.w;
                    pq.push({nxt.n, res[nxt.n]});
                }
            }
        }
        
        cout << ans << nl;
    }
    
    void main() {
        FOR(i, 1, n) {
            solve(i);
        }
    }
}
////////////////////////////////////////////////////////////////////////////////
namespace sub2 {
    vector<int> par;
    vector<ll> maxv;
    
    int root(int u) {
        if (par[u] < 0) return u;
        return par[u] = root(par[u]);
    }
    
    bool merge(int u, int v) {
        u = root(u);
        v = root(v);
        if (u == v) return false;
        if (par[u] > par[v]) swap(u, v);
        par[u] += par[v];
        par[v] = u;
        maxv[u] = max(maxv[u], maxv[v]);
        return true;
    }
    
    void main() {
        par.assign(n + 1, -1);
        maxv = v;
        
        FOR(i, 1, n) {
            FORIN(nxt, adj[i]) {
                if (nxt.w == 0) {
                    merge(i, nxt.n);
                }
            }
        }
        
        FOR(i, 1, n) {
            cout << maxv[root(i)] << nl;
        }
    }
}
////////////////////////////////////////////////////////////////////////////////
namespace sub3 {
    vector<ll> dp, ans;
    ////////////////////////////////////////
    void solvesub(int cur, int pre) {
        dp[cur] = v[cur];
        
        FORIN(nxt, adj[cur]) if (nxt.n != pre) {
            solvesub(nxt.n, cur);
            dp[cur] = max(dp[cur], dp[nxt.n] - nxt.w);
        }
    }
    ////////////////////////////////////////
    void solve(int cur, int pre, ll sum) {
        ans[cur] = max(sum, dp[cur]);
        
        multiset<ll, greater<ll>> mx{v[cur]};
        FORIN(nxt, adj[cur]) if (nxt.n != pre) {
            mx.insert(dp[nxt.n] - nxt.w);
        }
        
        FORIN(nxt, adj[cur]) if (nxt.n != pre) {
            mx.erase(mx.find(dp[nxt.n] - nxt.w));
            ll mxv = (mx.size() ? *(mx.begin()) : 0LL);
            solve(nxt.n, cur, max(0LL, max(sum, mxv) - nxt.w));
            mx.insert(dp[nxt.n] - nxt.w);
        }
    }
    ////////////////////////////////////////
    void main() {
        assign(n + 1, 0, dp, ans);
        solvesub(1, 1);
        // print(dp);
        solve(1, 1, 0);
        
        FOR(i, 1, n) cout << ans[i] << nl;
    }
}
////////////////////////////////////////////////////////////////////////////////
namespace sub4 {
    void main() {
        priority_queue<pll> pq;
        FOR(i, 1, n) pq.push({v[i], i});
        
        while (pq.size()) {
            pll cur = pq.top();
            pq.pop();
            
            FORIN(nxt, adj[cur.se]) {
                if (v[nxt.n] < cur.fi - nxt.w) {
                    v[nxt.n] = cur.fi - nxt.w;
                    pq.push({v[nxt.n], nxt.n});
                }
            }
        }
        
        FOR(i, 1, n) cout << v[i] << sp;
    }
}
////////////////////////////////////////////////////////////////////////////////
int main() {
    #define TASK "test"
    // #define TASK "cco24p1"
    // freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    ////////////////////////////////////////
    cin >> n >> m;
    
    bool ck1 = true;
    resize(n + 1, adj, v);
    
    FOR(i, 1, n) cin >> v[i];
    
    FOR(i, 1, m) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        if (w != 0 && w != 1e9) ck1 = false;
    }
    
    // if (n <= 3000 && m <= 3000) return sub1::main(), 0;
    // if (ck1) return sub2::main(), 0;
    // return sub3::main(), 0;
    return sub4::main(), 0;
    ////////////////////////////////////////
}