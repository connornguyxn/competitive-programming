#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using str = string;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define sp ' '
#define nl '\n'
#define all (a).begin(), (a.end());
#define FOR1(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FOR2(i, l, n) for (int i = (l), _n = (n); i <= _n; i++)
#define FOR3(i, l, n, sp) for (int i = (n), _n = (l); i >= _n; i--)
#define overload(a, b, c, d, e, ...) e
#define FOR(...) overload(__VA_ARGS__, FOR3, FOR2, FOR1)(__VA_ARGS__)
#define FORIN(it, a) for (auto& it : a)
const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
template <class ch, class tr, class c>
basic_ostream<ch, tr>& operator<<(basic_ostream<ch, tr>& cout, c& a) {
    cout << "{ ";
    FORIN(it, a) cout << it << sp;
    return cout << "}";
}
template <class... t>
void print(t&&... a) {
    using e = int[];
    e{(cout << a << sp, 0)...};
    cout << endl;
}
template <class... t>
void resize(int n, t&&... a) {
    using e = int[];
    e{(a.resize(n), 0)...};
}

const ll MOD = 1e9 + 7;

template <class... t>
void add(ll& n, t&&... a) {
    n %= MOD;
    using e = int[];
    e{(n = (n + (ll)a % MOD) % MOD, 0)...};
}


ll n;
///////////////////////////////////
ll sum(ll n) {
    return n * (n + 1) / 2 % MOD;
}
///////////////////////////////////
namespace sub2 {
    void main() {
        n++;
        ll ans = n;
        FOR(d, 1, n - 1) {
            ll mx = (n - 1) / d;
            add(ans, n * mx);
            add(ans, -1LL * d * sum(mx));
        }
        cout << ans << nl;
    }
}
///////////////////////////////////
int main() {
    #define task "test"
    freopen(task".inp", "r", stdin);
   freopen(task".out", "w", stdout);
    ///////////////////////////////////
    int tc;
    cin >> tc;
    FOR(i, tc) {
        cin >> n;
        sub2::main();
    }
    ///////////////////////////////////
}
