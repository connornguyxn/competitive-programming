#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using str = string;
using pii = pair<int, int>;
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
const int INF = 1e9 + 10;
const ll INFLL = 1e18 + 10;
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
    clog << "[debug] ";
    using e = int[];
    e{(clog << a << sp, 0)...};
    clog << endl;
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

// cf_1991c
// bitmasks

////////////////////////////////////////
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    FORIN(it, a) cin >> it;
    
    FOR(i, n - 1) {
        if (a[i] % 2 != a[i + 1] % 2) {
            cout << -1 << nl;
            return;
        }
    }
    
    FORIN(it, a) it = abs(it);
    sort(all(a));
    
    vector<int> ans;
    FOR(i, 29, 0, sp) {
        FORIN(it, a) {
            it = abs(it - bmask(i));
        }
        ans.push_back(bmask(i));
    }
    
    if (a[0]) ans.push_back(1);
    
    cout << ans.size() << nl;
    FORIN(it, ans) cout << it << sp;
        
    cout << nl;
}
////////////////////////////////////////
int main() {
    #define task "test"
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    ////////////////////////////////////////
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    
    

    ////////////////////////////////////////
}