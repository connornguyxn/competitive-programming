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
#define FOR(i, l, r) for (auto i = (l), _r = (r); i <= _r; i++)
#define FORD(i, r, l) for (auto i = (r), _l = (l); i >= _l; i--)
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


// https://codeforces.com/problemset/problem/1611/F
// binsearch

////////////////////////////////////////////////////////////////////////////////
namespace subf {
    ////////////////////////////////////////
    ////////////////////////////////////////
    void main() {
        int n;
        ll s;
        cin >> n >> s;
        
        vector<ll> a(n + 1);
        FOR(i, 1, n) {
            cin >> a[i];
            a[i] += a[i - 1];
        }
        
        int lg = __lg(n);
        vector2<ll> spt(lg + 1, vector<ll>(n + 1));
        spt[0] = a;
        
        FOR(i, 1, lg) {
            FOR(j, 1, n - bmask(i) + 1) {
                spt[i][j] = min(spt[i - 1][j], spt[i - 1][j + bmask(i - 1)]);
            }
        }
        
        auto get = [&](int l, int r) -> ll {
            int i = __lg(r - l + 1);
            return min(spt[i][l], spt[i][r - bmask(i) + 1]);
        };
        
        int ansl = 0, ansr = -1;
        FOR(i, 1, n) {
            int lo = i, hi = n, res = i - 1;
            while (lo <= hi) {
                int cur = (lo + hi) / 2;
                if (get(i, cur) - a[i - 1] + s >= 0) {
                    res = cur;
                    lo = cur + 1;
                } else {
                    hi = cur - 1;
                }
            }
            
            if (res - i + 1 > ansr - ansl + 1) {
                ansl = i;
                ansr = res;
            }
        }
        
        if (ansl == 0) {
            cout << -1;
        } else {
            cout << ansl << sp << ansr;
        }
        cout << nl;
    }
}
////////////////////////////////////////////////////////////////////////////////
int main() {
    #define TASK "cf_1611f"
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    atexit(logtime);
    ////////////////////////////////////////
    int tc;
    cin >> tc;
    
    FOR(_, 1, tc) {
        subf::main();
    }
    ////////////////////////////////////////
}