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
#define FOR(i, l, r) for (ll i = (l), _r = (r); i <= _r; i++)
#define FORD(i, r, l) for (ll i = (r), _l = (l); i >= _l; i--)
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
void logtime() {
    cout << flush;
    clog << nl << "[time] " << clock() * 1.0 / CLOCKS_PER_SEC << nl;
}


// cf_29d
// shorting, tree, eulertour

int n;
vector2<int> adj;
vector<int> ord;
////////////////////////////////////////////////////////////////////////////////
namespace subf {
    vector<int> pos;
    ////////////////////////////////////////
    int dfs(int cur, int pre) {
        vector<pii> path;
        FORIN(nxt, adj[cur]) if (nxt != pre) {
            int leaf = dfs(nxt, cur);
            path.push_back({leaf, nxt});
        }
        
        adj[cur].clear();
        if (path.empty()) return cur;
        
        sort(all(path), [&](pii a, pii b) {
            return pos[a.fi] < pos[b.fi];
        });
        
        FORIN(it, path) adj[cur].push_back(it.se);
        
        return path[0].fi;
    }
    ////////////////////////////////////////
    vector<int> tour, visit;
    void travel(int cur) {
        tour.push_back(cur);
        if (adj[cur].empty()) visit.push_back(cur);
        
        FORIN(nxt, adj[cur]) {
            travel(nxt);
            tour.push_back(cur);
        }
    }
    ////////////////////////////////////////
    void main() {
        resize(n + 1, pos);
        
        FOR(i, 0, ord.size() - 1) {
            pos[ord[i]] = i + 1;
        }
        
        dfs(1, 0);
        travel(1);
        
        if (visit == ord) {
            FORIN(it, tour) cout << it << sp;
        } else {
            cout << -1;
        }
    }
}
////////////////////////////////////////////////////////////////////////////////
int main() {
    #define TASK "cf_29d"
    freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    atexit(logtime);
    ////////////////////////////////////////
    cin >> n;
    
    resize(n + 1, adj);
    FOR(i, 2, n) {
        int u, v;
        cin >> u >> v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    
    int x;
    while (cin >> x) {
        ord.push_back(x);
    }
    
    return subf::main(), 0;
    ////////////////////////////////////////
}