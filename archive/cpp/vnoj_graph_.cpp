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

// https://oj.vnoi.info/problem/graph_
// graph, tarjan, classic

int n, m;
vector2<int> adj;
vector<int> tin, low, cut;
vector<pii> bridge;
int timer;
////////////////////////////////////////////////////////////////////////////////
void dfs(int cur, int pre) {
    tin[cur] = low[cur] = ++timer;
    
    int child = 0;
    FORIN(nxt, adj[cur]) if (nxt != pre) {
        if (tin[nxt] == 0) {
            dfs(nxt, cur);
            low[cur] = min(low[cur], low[nxt]);
            child++;
        } else {
            low[cur] = min(low[cur], tin[nxt]);
            continue;
        }
        
        if (low[nxt] == tin[nxt]) {
            bridge.push_back({cur, nxt});
        }
        if (low[nxt] >= tin[cur] && pre != 0) {
            cut.push_back(cur);
        }
    }
    
    if (child > 1 && pre == 0) {
        cut.push_back(cur);
    }
}
////////////////////////////////////////////////////////////////////////////////
int main() {
    #define TASK "test"
    // #define TASK "vnoj_graph_"
    // freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    ////////////////////////////////////////
    cin >> n >> m;
    
    resize(n + 1, adj);
    FOR(i, 1, m) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    resize(n + 1, tin, low);
    FOR(i, 1, n) {
        if (tin[i] == 0) dfs(i, 0);
    }
    
    // print(cut);
    // print(bridge);
    sort(all(cut));
    cut.erase(unique(all(cut)), cut.end());
    
    cout << cut.size() << sp << bridge.size();
    ////////////////////////////////////////
}