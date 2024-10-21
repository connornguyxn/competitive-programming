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


// cf_2014g
// implementation, stack

////////////////////////////////////////////////////////////////////////////////
namespace subf {
    ////////////////////////////////////////
    void main() {
        ll n, m, k;
        cin >> n >> m >> k;
        
        vector<ll> a(n + 1), d(n + 1);
        FOR(i, 1, n) {
            cin >> d[i] >> a[i];
        }
        
        d.push_back(INF);
        
        deque<pll> st;
        
        ll ans = 0;
        FOR(i, 1, n) {
            st.push_back({d[i] + k, a[i]});
            // print(i);
            
            ll curday = d[i], left = 0;
            while (st.size()) {
                pll& latest = st.back();
                
                left += latest.se;
                
                ll maxadd = min({
                    left / m, // max days possible
                    d[i + 1] - curday, // days cap
                    max(0LL, latest.fi - curday) // max days before expire
                });
                
                // print(st, left, latest.fi, maxadd);
                
                ans += maxadd;
                curday += maxadd;
                left -= maxadd * m;
                
                if (curday == d[i + 1]) {
                    latest.se = left;
                    break;
                }
                
                st.pop_back();
            }
        }
        
        cout << ans << nl;
    }
}
////////////////////////////////////////////////////////////////////////////////
signed main() {
    #define TASK "cf_2014g"
    // freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    atexit(logtime);
    ////////////////////////////////////////
    int tc = 1;
    cin >> tc;
    
    while (tc--) {
        subf::main();
    }
    ////////////////////////////////////////
}