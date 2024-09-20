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

// https://lqdoj.edu.vn/problem/sumcamp
// dsu, graph, tree

int n, m, k, q;
vector<int> par;
set<pii> es;
vector<unordered_map<int, int>> ans;
////////////////////////////////////////////////////////////////////////////////
int root(int cur) {
    if (par[cur] < 0) return cur;
    return par[cur] = root(par[cur]);
}
////////////////////////////////////////
bool join(int u, int v) {
    if ((u = root(u)) == (v = root(v))) return false;
    if (par[u] > par[v]) swap(u, v);
    par[u] += par[v];
    par[v] = u;
    FORIN(it, ans[v]) {
        ans[u][it.fi] += it.se;
    }
    return true;
}
////////////////////////////////////////////////////////////////////////////////
int main() {
    #define TASK "test"
    // #define TASK "sumcamp"
    // freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    ////////////////////////////////////////
    cin >> n >> m >> k;

    assign(n + 1, -1, par);
    resize(n + 1, ans);

    FOR(i, m) {
        int u, v;
        cin >> u >> v;
        if (u > v) swap(u, v);
        es.insert({u, v});
        ans[u][v]++;
        ans[v][u]++;
    }

    FOR(i, k) {
        int u, v;
        cin >> u >> v;
        join(u, v);
    }
    
    // print(comp);
    // print(ans);
    
    int q;
    cin >> q;
    FOR(_, q) {
        char t;
        cin >> t;
        if (t == 'F') {
            int u, v;
            cin >> u >> v;
            if (u > v) swap(u, v);
            if (es.count({u, v}) == 0) {
                ans[root(u)][v]++;
                ans[root(v)][u]++;
                es.count({u, v});
            } 
        } else if (t == 'T') {
            int u, v;
            cin >> u >> v;
            join(u, v);
        } else {
            int u;
            cin >> u;
            cout << ans[root(u)][u] << nl;
        }
    }
    ////////////////////////////////////////
}
