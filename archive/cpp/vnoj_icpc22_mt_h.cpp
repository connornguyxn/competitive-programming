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
#define bmask(i) (1 << (i))
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


// https://oj.vnoi.info/problem/icpc22_mt_h
// graph, dijkstra

struct Path {
    int n;
    ll w;
    bool operator<(const Path& o) const {
        return w > o.w;
    }
};
int n, m, k;
vector2<Path> adj; 
////////////////////////////////////////////////////////////////////////////////
namespace subf {
    ////////////////////////////////////////
    ////////////////////////////////////////
    void main() {
        vector<ll> res(n + 1, INFLL);
        res[1] = 0;
        priority_queue<Path> pq;
        pq.push({1, 0});
        
        while (pq.size()) {
            Path cur = pq.top();
            pq.pop();
            
            FORIN(nxt, adj[cur.n]) {
                if (res[nxt.n] > max(cur.w + 1, nxt.w)) {
                    res[nxt.n] = max(cur.w + 1, nxt.w);
                    pq.push({nxt.n, res[nxt.n]});
                }
            }
        }
        
        cout << (res[n] < INFLL ? res[n] : -1);
    }
}
////////////////////////////////////////////////////////////////////////////////
int main() {
    #define TASK "vnoj_icpc22_mt_h"
    freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    atexit(logtime);
    ////////////////////////////////////////
    cin >> n >> m;
    
    resize(n + 1, adj);
    FOR(i, 1, m) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, 0});
        adj[v].push_back({u, 0});
    }
    
    cin >> k;
    FOR(i, 1, k) {
        int t, u, v;
        cin >> t >> u >> v;
        adj[u].push_back({v, t});
        adj[v].push_back({u, t});
    }
    
    return subf::main(), 0;
    ////////////////////////////////////////
}