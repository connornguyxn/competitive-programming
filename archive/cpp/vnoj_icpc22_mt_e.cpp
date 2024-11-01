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
#define bmask(i) (1 << (i))
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


// https://oj.vnoi.info/problem/icpc22_mt_e
// dp, 2d

int n, m, k;
vector2<ll> a;
vector<ll> v;
////////////////////////////////////////////////////////////////////////////////
namespace subf {
    ll dp[101][101][11];
    vector2<ll> sum;
    ////////////////////////////////////////
    ll get(int x1, int y1, int x2, int y2) {
        return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
    }
    ////////////////////////////////////////
    ll solve(int r, int c, int idx) {
        if (r > n || c > m) return 0;
        if (idx == k) {
            return get(r, c, n, m) < v[k];
        };
        
        ll& res = dp[r][c][idx];
        if (res != -1) return res;
        res = 0;
        
        FOR(i, r, n) {
            if (get(r, c, i, m) <= v[idx]) {
                res = (res + solve(i + 1, c, idx + 1)) % MOD;
            }
        }
        FOR(i, c, m) {
            if (get(r, c, n, i) <= v[idx]) {
                res = (res + solve(r, i + 1, idx + 1)) % MOD;
            }
        }
        
        return res;
    }
    ////////////////////////////////////////
    void main() {
        sum = a;
        FOR(i, 1, n) {
            FOR(j, 1, m) {
                sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
            }
        }
        
        memset(dp, -1, sizeof(dp));
        cout << solve(1, 1, 1);
    }
}
////////////////////////////////////////////////////////////////////////////////
int main() {
    #define TASK "vnoj_icpc22_mt_e"
    // freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    atexit(logtime);
    ////////////////////////////////////////
    cin >> n >> m >> k;
    
    a.assign(n + 1, vector<ll>(m + 1));
    FOR(i, 1, n) {
        FOR(j, 1, m) {
            cin >> a[i][j];
        }
    }
    
    resize(k + 1, v);
    FOR(i, 1, k) {
        cin >> v[i];
    }
    
    return subf::main(), 0;
    ////////////////////////////////////////
}