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

// https://codeforces.com/problemset/problem/1468/J
// graph, tree, dsu

struct E {
    int u, v;
    ll w;
};
int n, m, k;
vector<E> es;
vector<int> par;
////////////////////////////////////////////////////////////////////////////////
int root(int cur) {
    return (par[cur] < 0 ? cur : par[cur] = root(par[cur]));
}
////////////////////////////////////////
bool merge(int u, int v) {
    if ((u = root(u)) == (v = root(v))) return false;
    if (par[u] > par[v]) swap(u, v);
    par[u] += par[v];
    par[v] = u;
    return true;
}
////////////////////////////////////////
void solve() {
    cin >> n >> m >> k;
    
    par.assign(n + 1, -1);
    es.resize(m);
    FORIN(it, es) {
        cin >> it.u >> it.v >> it.w;
    }
    
    sort(all(es), [&](E& a, E& b) {
        return a.w < b.w;
    });
    
    ll ans = 0;
    int i = 0, cmp = n;
    while (cmp > 1) {
        auto& it = es[i];
        if (merge(it.u, it.v)) {
            cmp--;
            if (it.w > k) {
                ans += it.w - k;
                it.w = k;
            }
        }
        i++;
    }
    
    // print(ans);
    
    ll mn = abs(es[i - 1].w - k);
    FOR(j, i, m - 1) {
        mn = min(mn, abs(es[j].w - k));
    }
    
    cout << ans + mn << nl;
}
////////////////////////////////////////////////////////////////////////////////
int main() {
    #define TASK "test"
    // #define TASK "1468j"
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    ////////////////////////////////////////
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    ////////////////////////////////////////
}