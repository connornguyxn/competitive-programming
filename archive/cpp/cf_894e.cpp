#include "bits/stdc++.h"
using namespace std;
using ll = long long;
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

// https://codeforces.com/contest/894/problem/E
// graph, scc, dp

struct Path {
    int n;
    ll w;
};
int n, m, s, timer, scc;
vector<vector<Path>> adj;
vector<int> tin, low, comp, del;
deque<int> stk;
////////////////////////////////////////
ll calcmax(ll x) {
    ll lo = 0, hi = INF, res = 0;
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        if (mid * (mid + 1) / 2 <= x) {
            res = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    
    return x * (res + 1) - ((res) * (res + 1) * (res + 2) / 6);
}
////////////////////////////////////////
void tarjan(int cur) {
    stk.push_back(cur);
    low[cur] = tin[cur] = timer++;
    
    FORIN(nxt, adj[cur]) {
        if (comp[nxt.n] != -1) continue;
        if (tin[nxt.n] != -1) {
            low[cur] = min(low[cur], tin[nxt.n]);
        } else {
            tarjan(nxt.n);
            low[cur] = min(low[cur], low[nxt.n]);
        }
    }
    
    if (low[cur] == tin[cur]) {
        scc++;
        int u;
        do {
            u = stk.back();
            comp[u] = scc;
            stk.pop_back();
        } while (u != cur);
    }
}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
int main() {
    #define TASK "test"
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    ////////////////////////////////////////
    cin >> n >> m;
    
    resize(n + 1, adj);
    assign(n + 1, -1, comp, tin, low);
    
    FOR(i, 1, m) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    
    cin >> s;
    
    
    FOR(i, 1, n) if (tin[i] == -1) tarjan(i);
    
    vector<ll> val;
    vector<vector<Path>> dagadj;
    resize(scc + 1, dagadj, val);
    
    FOR(cur, 1, n) {
        FORIN(nxt, adj[cur]) {
            if (comp[cur] == comp[nxt.n]) {
                val[comp[cur]] += calcmax(nxt.w);
            } else {
                dagadj[comp[cur]].push_back({comp[nxt.n], nxt.w});
            }
        }
    }
    
    vector<ll> dp = val;
    FOR(cur, 1, scc) {
        FORIN(nxt, dagadj[cur]) {
            dp[cur] = max(dp[cur], dp[nxt.n] + nxt.w + val[cur]);
        }
    }
    
    cout << dp[comp[s]];
    ////////////////////////////////////////
}