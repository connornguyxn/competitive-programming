#include "bits/stdc++.h"
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
#define lnode (tv * 2)
#define rnode (tv * 2 + 1)
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

// https://dmoj.ca/problem/tle16c8p3
// math, binsearch

vector<ll> cnt, sum;
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void solve() {
    ll n;
    cin >> n;
    
    ll len = lower_bound(all(sum), n) - sum.begin();
    n -= sum[len - 1];
    
    while (len > 3) {
        if (n > cnt[len - 3]) {
            cout << 69;
            n -= cnt[len - 3];
            len -= 2;
            
        } else {
            cout << 420;
            len -= 3;
        }
    }
    if (len == 2) cout << 69;
    if (len == 3) cout << 420;
    cout << nl;
}
////////////////////////////////////////////////////////////////////////////////
int main() {
    #define TASK "dmoj_tle16c8p3"
    // freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    ////////////////////////////////////////
    const int N = 150;
    resize(N + 1, cnt, sum);
    cnt[2] = 1;
    cnt[3] = 1;
    FOR(i, 4, N) {
        cnt[i] = cnt[i - 2] + cnt[i - 3];
    }
    partial_sum(all(cnt), sum.begin());
    
    int tc;
    cin >> tc;
    while (tc--) solve();
    ////////////////////////////////////////
}
