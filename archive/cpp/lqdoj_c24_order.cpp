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

// https://lqdoj.edu.vn/contest/lqdojcup2024r1
// graph, math

int n, m;
vector2<int> adj;
vector<ll> a;
////////////////////////////////////////////////////////////////////////////////
namespace subfull {
    vector<ll> fact;
    ////////////////////////////////////////
    void main() {
        fact.resize(n + 1);
        fact[0] = 1;
        FOR(i, 1, n) fact[i] = (fact[i - 1] * (ll)i) % MOD;

        ll ans = 0;
        FOR(cur, 1, n) {
            FORIN(nxt, adj[cur]) {
                ans = (ans + ((ll)n * ((ll)n - 1) / 2) % MOD * fact[n - 2] % MOD * a[nxt]) % MOD;
            }
        }
        cout << ans;
    }
}
////////////////////////////////////////////////////////////////////////////////
int main() {
    // #define TASK "test"
    #define TASK "order"
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    ////////////////////////////////////////
    cin >> n >> m;

    resize(n + 1, adj, a);
    FOR(i, 1, n) cin >> a[i];

    FOR(i, 1, m) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    return subfull::main(), 0;
    ////////////////////////////////////////
}
