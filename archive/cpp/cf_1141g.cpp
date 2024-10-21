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
    clog << "[debug] ";
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
    cout << flush;
    clog << nl << "[time] " << clock() * 1.0 / CLOCKS_PER_SEC << nl;
}


// https://codeforces.com/problemset/problem/1141/G
// tree, binsearch, greedy

int n, k;
vector2<int> adj;
vector<pii> es;
////////////////////////////////////////////////////////////////////////////////
namespace subf {
    int cnt, r;
    ////////////////////////////////////////
    void dfs(int cur, int pre) {
        if ((int)adj[cur].size() > r) {
            cnt++;
        }
        
        FORIN(nxt, adj[cur]) if (nxt != pre) {
            dfs(nxt, cur);
        }
    }
    ////////////////////////////////////////
    map<pii, int> c;
    ////////////////////////////////////////
    void color(int cur, int pre, int curr) {
        FORIN(nxt, adj[cur]) if (nxt != pre) {
            c[{min(cur, nxt), max(cur, nxt)}] = curr;
            curr = (curr + 1) % r;
            color(nxt, cur, curr);
        }
    }
    ////////////////////////////////////////
    void main() {
        int lo = 1, hi = n - 1, res = 0;
        while (lo <= hi) {
            int cur = (lo + hi) / 2;
            
            cnt = 0;
            r = cur;
            dfs(1, 0);
            
            if (cnt <= k) {
                res = cur;
                hi = cur - 1;
            } else {
                lo = cur + 1;
            }
        }
        
        r = res;
        color(1, 0, 0);
        
        // print(c);
        
        cout << res << nl;
        FORIN(it, es) {
            cout << c[{min(it.fi, it.se), max(it.fi, it.se)}] + 1 << sp;
        }
    }
}
////////////////////////////////////////////////////////////////////////////////
int main() {
    #define TASK "cf_1141g"
    freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    atexit(logtime);
    ////////////////////////////////////////
    cin >> n >> k;
    
    resize(n + 1, adj);
    FOR(i, 2, n) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        es.push_back({u, v});
    }
    
    return subf::main(), 0;
    ////////////////////////////////////////
}