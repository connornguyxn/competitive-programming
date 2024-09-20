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

// https://lqdoj.edu.vn/problem/gift01
// dp, datastruct

#define left (tv * 2)
#define right (tv * 2 + 1)

int n, k;
vector<ll> st;
////////////////////////////////////////////////////////////////////////////////
void update(int p, ll v, int tl = 0, int tr = n, int tv = 1) {
    if (tl == tr) {
        st[tv] = v;
        return;
    }
    int tm = (tl + tr) / 2;
    if (p <= tm) update(p, v, tl, tm, left);
    else update(p, v, tm + 1, tr, right);
    st[tv] = min(st[left], st[right]);
}
////////////////////////////////////////
ll get(int l, int r, int tl = 0, int tr = n, int tv = 1) {
    if (tr < l || r < tl) return INFLL;
    if (l <= tl && tr <= r) return st[tv];
    int tm = (tl + tr) / 2;
    ll lq = get(l, r, tl, tm, left);
    ll rq = get(l, r, tm + 1, tr, right);
    return min(lq, rq);
}
////////////////////////////////////////////////////////////////////////////////
int main() {
    #define TASK "test"
    // #define TASK "gift01"
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    ////////////////////////////////////////
    cin >> n >> k;
    
    vector<ll> a(n + 1);
    FOR(i, 1, n) cin >> a[i];
    
    assign(n * 4 + 4, INFLL, st);
    FOR(i, 1, k) update(i, a[i]);
    
    FOR(i, k + 1, n) {
        update(i, get(i - k, i - 1) + a[i]);
    }
    
    // FOR(i, 1, n) print(get(i, i));
    // print(accumulate(all(a), 0LL));
    
    cout << accumulate(all(a), 0LL) - get(n - k + 1, n);
    ////////////////////////////////////////
}