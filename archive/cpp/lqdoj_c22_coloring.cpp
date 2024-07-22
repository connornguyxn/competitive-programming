#include "bits/stdc++.h"
#ifdef LOCAL
    #define TASK "test"
#else
    #define TASK "coloring"
#endif
using namespace std;
using ll = long long;
using str = string;
using pii = pair<int, int>;
#define fi first
#define se second
#define nl '\n'
#define sp ' '
#define ALL(a) (a).begin(), (a).end()
#define BMASK(i) (1LL << (i))
#define BGET(n, i) (((n) >> (i)) & 1)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define REPD(i, n) for (int i = (n); i--; )
#define FOR(i, l, r) for (int i = (l), _r = (r); i <= _r; i++)
#define FORD(i, r, l) for (int i = (r), _l = (l); i >= _l; i--)
#define FORIN(it, a) for (auto& it : a)
const int N = 2e6 + 1;
const ll MOD = 1e9 + 7;
const int INF = 1e9 + 9;
const ll INFLL = 1e18 + 9;
const int ofr[] = {0, 1, 0, -1, 1, 1, -1, -1};
const int ofc[] = {1, 0, -1, 0, 1, -1, -1, 1};
template <class T>
bool mxmz(T& a, T b) { return a < b ? a = b, 1 : 0; }
template <class T>
bool mnmz(T& a, T b) { return b < a ? a = b, 1 : 0; }
void add(ll& a, ll b) { a = (a + b % MOD) % MOD; }
void sub(ll& a, ll b) { a = (a - b % MOD + MOD) % MOD; }
void mul(ll& a, ll b) { a = a * (b % MOD) % MOD; }
template <class T>
T sqr(T n) { return n * n; }
template <template <class...> class T, class... Args>
ostream& operator<<(ostream& out, const T<Args...>& a) {
    out << '{';
    for (auto it = a.begin(); it != a.end(); it++) {
        if (it != a.begin()) out << ", ";
        out << *it;
    }
    return out << '}';
}
template <class... T>
void print(T&&... n) {
    using exp = int[];
    exp{0, (cout << n << sp, 0)...};
    cout << endl;
}
#define printv(...) print(#__VA_ARGS__, '=', __VA_ARGS__)


// https://lqdoj.edu.vn/problem/lqdoj2022r1coloring
// graph, tree, greedy

int n, k;
vector<vector<int>> adj;
vector<int> group, path;
////////////////////////////////////////
int getmin(int cur, int pre) {
    int minval = n + 1;
    FORIN(nxt, adj[cur]) if (nxt != pre) {
        if (group[nxt]) continue;
        if (mnmz(minval, getmin(nxt, cur))) {
            path[cur] = nxt;
        }
    }
    return min(minval, cur);
}
////////////////////////////////////////
int main() {
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    cin.tie(nullptr)->sync_with_stdio(false);
    ////////////////////
    cin >> n;
    adj.resize(n + 1);
    
    REP(i, n - 1) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    group.resize(n + 1);
    int cnt = 1;
    FOR(i, 1, n) {
        if (group[i]) continue;
        
        group[i] = cnt;
        path.assign(n + 1, 0);
        int min1 = 0, min2 = 0, val1 = n + 1, val2 = n + 1;
        FORIN(nxt, adj[i]) {
            if (group[nxt]) continue;
            int cval = getmin(nxt, i);
            if (cval <= val1) {
                val2 = val1;
                min2 = min1;
                val1 = cval;
                min1 = nxt;
            } else if (cval < val2) {
                val2 = cval;
                min2 = nxt;
            }
        }
        
        while (min1) {
            group[min1] = cnt;
            min1 = path[min1];
        }
        while (min2) {
            group[min2] = cnt;
            min2 = path[min2];
        }
        cnt++;
    }
    
    FOR(i, 1, n) cout << group[i] << sp;
    ////////////////////
    return 0;
}