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


// cf_321c
// centroid, greedy


int n;
vector2<int> adj;
///////////////////////////////////////////////////////////////////////////////
namespace sub1 {
    vector<int> size, del;
    vector<char> ans;
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
    void dcmp(int cur, char rank) {
        del[cur] = 1;
        ans[cur] = rank;
        
        FORIN(nxt, adj[cur]) {
            if (del[nxt]) continue;
            calc_size(nxt, cur);
            int c = centroid(nxt, nxt, size[cur] / 2);
            dcmp(c, rank + 1);
        }
    }
    ////////////////////////////////////////
    void main() {
        resize(n + 1, del, size, ans);
        
        calc_size(1, 1);
        dcmp(centroid(1, 1, n / 2), 'A');
        
        FOR(i, 1, n) cout << ans[i] << sp;
    }
    bool run() {
        return main(), 1;
    }
}
////////////////////////////////////////////////////////////////////////////////
int main() {
    #define TASK "cf_321c"
    // freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    atexit(logtime);
    ////////////////////////////////////////
    cin >> n;
    
    resize(n + 1, adj);
    FOR(i, 1, n) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    if (sub1::run()) return 0;
    ////////////////////////////////////////
    return 0;
}