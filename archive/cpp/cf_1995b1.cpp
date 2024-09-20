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
#define FOR3(i, l, r, a1) for (int i = (r), _l = (l); i >= _l; i--)
#define OVERLOAD(a, b, c, d, e, ...) e
#define FOR(...) OVERLOAD(__VA_ARGS__, FOR3, FOR2, FOR1)(__VA_ARGS__)
#define FORIN(it, a) for (auto& it : a)
const ll MOD = 1e9 + 7;
const int INF = 1e9 + 9;
const ll INFLL = 1e18 + 9;
template <class T1, class... T2>
void assign(int n, T1 v, T2&&... a) {
    using e = int[];
    e{(a.assign(n, v), 0)...};
}
template <class... T2>
void resize(int n, T2&&... a) {
    using e = int[];
    e{(a.resize(n), 0)...};
}
template <class... T>
void print(T&&... a) {
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

// cf_1995b1
// <tags>

////////////////////////////////////////
ll solve() {
    int n;
    ll m;
    cin >> n >> m;
    
    vector<ll> a(n);
    FORIN(it, a) cin >> it;
    sort(all(a));
    
    int l = 0;
    ll res = 0, cur = 0;;
    FOR(i, n) {
        cur += a[i];
        
        while ((l <= m) && (cur > m || a[i] - a[l] > 1)) {
            cur -= a[l];
            l++;
        }
        
        res = max(cur, res);
    }
    
    return res;
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
    while (tc--) cout << solve() << nl;
    ////////////////////////////////////////
}