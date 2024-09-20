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

// https://dmoj.ca/problem/aac1p5
// tree, prefixsum, combinatorics

int n;
vector2<pii> adj;
////////////////////////////////////////////////////////////////////////////////
namespace sub3 {
    vector2<ll> sum;
    
    void dfs(int cur, int pre, int s) {
        sum[cur][s]++;
        FORIN(nxt, adj[cur]) if (nxt.fi != pre) {
            dfs(nxt.fi, cur, s ^ nxt.se);
            sum[cur][0] += sum[nxt.fi][0];
            sum[cur][1] += sum[nxt.fi][1];
        }
    }
    
    ll ans = INF;
    void tryans() {
        ans = min(ans, abs(
            sum[1][0] * (sum[1][0] - 1) / 2
            + sum[1][1] * (sum[1][1] - 1) / 2
            - sum[1][1] * sum[1][0]
       ));
    }
    
    
    void solve(int cur, int pre) {
        FORIN(nxt, adj[cur]) if (nxt.fi != pre) {
            auto swapsum = [&]() {
                sum[1][0] -= sum[nxt.fi][0];
                sum[1][1] -= sum[nxt.fi][1];
                swap(sum[nxt.fi][0], sum[nxt.fi][1]);
                sum[1][0] += sum[nxt.fi][0];
                sum[1][1] += sum[nxt.fi][1];
            };
            swapsum();
            tryans();
            swapsum();
            solve(nxt.fi, cur);
        }
    }
    
    void main() {
        sum.resize(n + 1, vector<ll>(2));
        dfs(1, 0, 0);
        
        tryans();
        solve(1, 0);
        cout << ans;
    }
}
////////////////////////////////////////////////////////////////////////////////
int main() {
    #define TASK "dmoj_aac1p5"
    // freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    ////////////////////////////////////////
    cin >> n;
    resize(n + 1, adj);
    
    FOR(i, 2, n) {
        int u, v, w;
        cin >> u >> v >> w;
        w %= 2;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    return sub3::main(), 0;
    ////////////////////////////////////////
}
