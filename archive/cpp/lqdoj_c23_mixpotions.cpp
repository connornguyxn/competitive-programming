#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
using str = string;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define fi first
#define se second
#define nl '\n'
#define sp ' '
#define all(a) (a).begin(), (a).end()
#define FOR(i, l, r) for (int i = (l), _r = (r); i <= _r; i++)
#define FORD(i, r, l) for (int i = (r), _l = (l); i >= _l; i--)
#define FORIN(it, a) for (auto& it : a)
#define bmask(i) (1LL << (i))
#define bget(i, n) ((n) >> (i) & 1)
#define bon(i, n) ((n) | bmask(i))
#define boff(i, n) ((n) & ~bmask(i))
const ll MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ull N = 1e6 + 3;
template <class T>
using vector2 = vector<vector<T>>;
template <class T>
using vector3 = vector<vector2<T>>;
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
    cout << "[debug] ";
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

// https://lqdoj.edu.vn/problem/lqdoj2023r1mixpotion
// bitwise

int n;
ll k;
vector<ll> a;
////////////////////////////////////////////////////////////////////////////////
namespace sub1 {
    void main() {
        vector<ll> ans;
        ans.reserve(n * (n + 1) / 2);
        
        FOR(i, 0, n - 2) {
            FOR(j, i + 1, n - 1) {
                ans.push_back(a[i] ^ a[j]);
            }
        }
        
        sort(all(ans));
        cout << ans[k - 1] << nl;
    }
}
////////////////////////////////////////////////////////////////////////////////
namespace sub3 {
    void main() {
        sort(all(a));
        map<ll, ll> cnt;
        FORIN(it, a) {
            cnt[__lg(it)]++;
        }
        
        vector<pll> a;
        FORIN(it, cnt) {
            a.push_back(it);
        }
        n = a.size() - 1;
        
        ll cur = 0;
        FORIN(it, a) {
            cur += it.se * (it.se - 1) / 2;
        }
        if (k <= cur) {
            cout << 0;
            return;
        }
        
        FOR(i, 1, n) {
            FOR(j, 0, i - 1) {
                cur += a[j].se * a[i].se;
                if (k <= cur) {
                    cout << (bmask(a[i].fi) ^ bmask(a[j].fi));
                    return;
                }
            }
        }
    }
}
////////////////////////////////////////////////////////////////////////////////
int main() {
    // #define TASK "test"
    #define TASK "mixpotions"
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    ////////////////////////////////////////
    cin >> n >> k;
    
    resize(n, a);
    FORIN(it, a) cin >> it;
    
    if (n <= 5000) return sub1::main(), 0;
    return sub3::main(), 0;
    ////////////////////////////////////////
}