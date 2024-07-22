#include "bits/stdc++.h"
#ifdef LOCAL
    #define TASK "test"
#else
    #define TASK "three"
#endif
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define fi first
#define se second
#define nl '\n'
#define sp ' '
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
template <class T>
bool mxmz(T& a, T b) {
    return a < b ? a = b, 1 : 0;
}
template <class T>
bool mnmz(T& a, T b) {
    return b < a ? a = b, 1 : 0;
}
void add(ll& a, ll b) { a = (a + b % MOD) % MOD; }
void sub(ll& a, ll b) { a = (a - b % MOD + MOD) % MOD; }
void mul(ll& a, ll b) { a = a * (b % MOD) % MOD; }
template <class T>
T sqr(T n) { return n * n; }
template <class... T>
void print(T&&... n) {
    using exp = int[];
    exp{0, (cout << n << sp, 0)...};
    cout << endl;
}

// vnoj_voi24_three
// implementation

namespace sub3 {
    int n, m, q;
    vector<vector<ll>> a;
    ////////////////////////////////////////
    void solve() {
        vector<ll> row(n + 1), col(n + 1);
        FOR(i, 1, n) {
            FOR(j, 1, n) {
                row[i] += a[i][j];
                col[j] += a[i][j];
            }
        }
        
        multiset<ll> rows, cols;
        FOR(i, 1, n) {
            rows.insert(row[i]);
            cols.insert(col[i]);
        }
        
        ll res = 0;
        {
            auto it = rows.end();
            mxmz(res, *--it + *--it + *--it);
        }
        {
            auto it = cols.end();
            mxmz(res, *--it + *--it + *--it);
        }
        
        FOR(i, 1, n) {
            FOR(j, 1, n) {
                if (a[i][j]) {
                    cols.erase(cols.find(col[j]));
                    cols.insert(col[j] - a[i][j]);
                }
                if (a[j][i]) {
                    rows.erase(rows.find(row[j]));
                    rows.insert(row[j] - a[j][i]);
                }
            }
            
            {
                auto it = cols.end();
                mxmz(res, row[i] + *--it + *--it);
            }
            {
                auto it = rows.end();
                mxmz(res, col[i] + *--it + *--it);
            }
            
            FOR(j, 1, n) {
                if (a[i][j]) {
                    cols.erase(cols.find(col[j] - a[i][j]));
                    cols.insert(col[j]);
                }
                if (a[j][i]) {
                    rows.erase(rows.find(row[j] - a[j][i]));
                    rows.insert(row[j]);
                }
            }
        }
        
        cout << res << nl;
    }
    ////////////////////////////////////////
    struct Point {
        int r, c, w;
    };
    void main() {
        cin >> n >> m >> q;
        
        vector<Point> ps(m + 1);
        vector<int> zip;
        zip.reserve(m * 2);
        FOR(i, 1, m) {
            cin >> ps[i].r >> ps[i].c >> ps[i].w;
            zip.push_back(ps[i].r);
            zip.push_back(ps[i].c);
        }
        
        sort(zip.begin(), zip.end());
        zip.erase(unique(zip.begin(), zip.end()), zip.end());
        auto num = [&](int x) {
            return lower_bound(zip.begin(), zip.end(), x) - zip.begin() + 1;
        };
        FOR(i, 1, m) {
            ps[i].r = num(ps[i].r);
            ps[i].c = num(ps[i].c);
        }
        n = zip.size() + 1;
        
        a.assign(n + 1, vector<ll>(n + 1, 0));
        FOR(i, 1, m) {
            a[ps[i].r][ps[i].c] = ps[i].w;
        }
        
        solve();
        REP(i, q) {
            int t;
            ll d;
            cin >> t >> d;
            a[ps[t].r][ps[t].c] += d;
            solve();
            a[ps[t].r][ps[t].c] -= d;
        }
    }
}
////////////////////////////////////////
int main() {
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(12);
    ////////////////////
    int tc;
    cin >> tc;
    while (tc--) {
        sub3::main();
    }
    ////////////////////
    return 0;
}