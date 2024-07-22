#include "bits/stdc++.h"
#ifdef LOCAL
    #define TASK "test"
#else
    #define TASK "convexhull"
#endif
using namespace std;
using ll = long long;
using str = string;
using pll = pair<ll, ll>;
#define fi first
#define se second
#define nl '\n'
#define sp ' '
#define DR(a) (*(a))
#define ALL(a) (a).begin(), (a).end()
#define BMASK(i) (1LL << (i))
#define BGET(n, i) (((n) >> (i)) & 1)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define REPD(i, n) for (int i = (n); i--; )
#define FOR(i, l, r) for (int i = (l), _r = (r); i <= _r; i++)
#define FORD(i, r, l) for (int i = (r), _l = (l); i >= _l; i--)
#define FORIN(it, a) for (auto& it : a)
const int N = 6e6 + 1;
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


// cses_convexhull
// basic, geometry

////////////////////////////////////////
bool ccw(pll o, pll a, pll b) {
    ll x1 = a.fi - o.fi, y1 = a.se - o.se;
    ll x2 = b.fi - o.fi, y2 = b.se - o.se;
    return x1 * y2 - x2 * y1 > 0;
}
////////////////////
vector<pll> convex_hull(vector<pll>& a) {
    sort(ALL(a), [](pll a, pll b) {
        if (a.fi != b.fi) return a.fi < b.fi;
        return a.se < b.se;
    });
    vector<pll> hull{a[0]};
    
    FOR(i, 1, a.size() - 1) {
        while (hull.size() > 1 && ccw(hull[hull.size() - 2], hull.back(), a[i])) hull.pop_back();
        hull.push_back(a[i]);
    }
    FORD(i, a.size() - 2, 0) {
        while (hull.size() > 1 && ccw(hull[hull.size() - 2], hull.back(), a[i])) hull.pop_back();
        hull.push_back(a[i]);
    }
    
    hull.pop_back();
    return hull;
}
////////////////////////////////////////
int main() {
    // freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////////
    int n;
    cin >> n;
    vector<pll> a(n);
    FORIN(it, a) cin >> it.fi >> it.se;
    
    vector<pll> res = convex_hull(a);
    cout << res.size() << nl;
    FORIN(it, res) cout << it.fi << sp << it.se << nl;
    ////////////////////
    return 0;
}