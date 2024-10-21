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
void logtime() {
    cout << flush;
    clog << nl << "[time] " << clock() * 1.0 / CLOCKS_PER_SEC << nl;
}


// https://dmoj.ca/problem/wac2p2
// greedy, easy


ll n, m, q;
vector<pll> a;
////////////////////////////////////////////////////////////////////////////////
namespace subf {
    struct Day {
        ll l, r, c;
    };
    ////////////////////////////////////////
    ////////////////////////////////////////
    void main() {
        vector<Day> a(q);
        FOR(i, 0, q - 2) {
            a[i] = {::a[i + 1].fi, ::a[i].fi, ::a[i].se};
        }
        a[q - 1] = {1, ::a[q - 1].fi, ::a[q - 1].se};
        a.push_back({::a[0].fi, n, 1000000});
        
        sort(all(a), [](Day a, Day b) {
            return a.c < b.c;
        });
        
        ll ans = 0;
        unordered_set<ll> mk;
        FORIN(it, a) {
            ll add = min((ll)(it.r - it.l + 1 - mk.count(it.l) - (it.l != it.r ? mk.count(it.r) : 0)), m);
            ans += add * it.c;
            m -= add;
            if (m == 0) break;
            mk.insert(it.l);
            mk.insert(it.r);
        }
        
        cout << ans << nl;
    }
}
////////////////////////////////////////////////////////////////////////////////
int main() {
    #define TASK "dmoj_wac2p2"
    // freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    atexit(logtime);
    ////////////////////////////////////////
    cin >> n >> m >> q;
    
    resize(q, a);
    FORIN(it, a) cin >> it.fi >> it.se;
    
    return subf::main(), 0;
    ////////////////////////////////////////
}