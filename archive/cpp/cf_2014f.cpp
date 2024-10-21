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


// f
// tree, dp, easy


int n;
ll c;
vector2<int> adj;
vector<ll> a;
////////////////////////////////////////////////////////////////////////////////
namespace subf {
    vector2<ll> dp;
    ////////////////////////////////////////
    void solve(int cur, int pre) {
        dp[cur] = {0, a[cur]};
        
        FORIN(nxt, adj[cur]) if (nxt != pre) {
            solve(nxt, cur);
            
            if (max(dp[nxt][1], dp[nxt][0]) > 0) {
                dp[cur][0] += max(dp[nxt][1], dp[nxt][0]);
            }
            if (max(dp[nxt][1] - c * 2, dp[nxt][0]) > 0) {
                dp[cur][1] += max(dp[nxt][1] - c * 2, dp[nxt][0]);
            }
        }
    }
    ////////////////////////////////////////
    void main() {
        cin >> n >> c;
        
        a.resize(n + 1);
        FOR(i, 1, n) {
            cin >> a[i];
        }
        
        adj.assign(n + 1, {});
        FOR(i, 1, n - 1) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        dp.resize(n + 1, vector<ll>(2));
        solve(1, 0);
        cout << max(dp[1][0], dp[1][1]) << nl;
    }
}
////////////////////////////////////////////////////////////////////////////////
int main() {
    #define TASK "f"
    // freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    // atexit(logtime);
    ////////////////////////////////////////
    int tc = 1;
    cin >> tc;
    
    while (tc--) {
        subf::main();
    }
    ////////////////////////////////////////
}