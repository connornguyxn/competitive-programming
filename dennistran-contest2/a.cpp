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

// https://codeforces.com/group/OgDyRcm8ue/contest/550507
// <tags>

struct Path {
    int n;
    ll w, maxdist = 0;
    bool operator<(const Path& o) const {
        return w > o.w;
    }
};
int n, m, k;
vector2<Path> adj;
vector<pii> pts;
////////////////////////////////////////////////////////////////////////////////
namespace subf {
    bool checksub() {
        return true;
    }
    ////////////////////////////////////////
    ////////////////////////////////////////
    void main() {
        vector<ll> dist(n + 1, INFLL);
        dist[n] = 0;
        priority_queue<Path> pq;
        pq.push({n, 0});
        
        while (pq.size()) {
            Path cur = pq.top();
            pq.pop();
            
            FORIN(nxt, adj[cur.n]) {
                if (dist[nxt.n] > cur.w + nxt.w) {
                    dist[nxt.n] = cur.w + nxt.w;
                    pq.push({nxt.n, dist[nxt.n]});
                }
            }
        }
        
        vector<ll> dist2(n + 1, INFLL);
        FORIN(it, pts) {
            dist2[it.fi] = dist[it.fi];
            pq.push({it.fi, dist[it.fi], it.se});
        }
        
        while (pq.size()) {
            Path cur = pq.top();
            pq.pop();
            
            FORIN(nxt, adj[cur.n]) {
                if (dist2[nxt.n] > cur.w + nxt.w && cur.w + nxt.w - dist2[nxt.n] <= cur.maxdist) {
                    dist2[nxt.n] = cur.w + nxt.w;
                    pq.push({nxt.n, dist2[nxt.n], cur.maxdist});
                }
            }
        }
        // print(dist2);
        
        FOR(i, 1, n - 1) cout << (dist2[i] < INFLL) << nl;
    }
}
////////////////////////////////////////////////////////////////////////////////
int main() {
    #define TASK "test"
    // #define TASK "a"
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    ////////////////////////////////////////
    cin >> n >> m >> k;
    
    resize(n + 1, adj);
    FOR(i, 1, n) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    resize(k, pts);
    FORIN(it, pts) cin >> it.fi >> it.se;
    
    if (subf::checksub()) return subf::main(), 0;
    ////////////////////////////////////////
}