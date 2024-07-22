#include "bits/stdc++.h"
#ifdef LOCAL
    #define TASK "test"
#else
    #define TASK "b"
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


// https://oj.vnoi.info/problem/vnoicup24_r2_b
// implementation

////////////////////////////////////////
void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    FOR(i, 1, n) cin >> a[i];
    
    vector<pii> res;
    res.reserve(2000);
    
    FOR(i, 1, n) {
        if (a[i] == i) continue;
        FOR(j, i + 1, n) {
            if (a[j] != i) continue;
            res.emplace_back(j, n + 1);
            FORD(k, j - 1, i) {
                a[k + 1] = a[k];
                res.emplace_back(k, k + 1);
            }
            break;
        }
        a[i] = i;
        res.emplace_back(n + 1, i);
    }
    
    cout << res.size() << nl;
    FORIN(it, res) cout << it.fi << sp << it.se << nl;
}
////////////////////////////////////////
int main() {
    // freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////////
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    ////////////////////
    return 0;
}