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

// cf_1709d
// datastruct, segtree


#define left (tv * 2)
#define right (tv * 2 + 1)


int n, m, q;
vector<int> st, a;
////////////////////////////////////////////////////////////////////////////////
void build(int tl = 1, int tr = m, int tv = 1) {
    if (tl == tr) {
        st[tv] = a[tl];
        return;
    }
    int tm = (tl + tr) / 2;
    build(tl, tm, left);
    build(tm + 1, tr, right);
    st[tv] = max(st[left], st[right]);
}
////////////////////////////////////////
int get(int l, int r, int tl = 1, int tr = m, int tv = 1) {
    if (tr < l || r < tl) return -1;
    if (l <= tl && tr <= r) return st[tv];
    int tm = (tl + tr) / 2;
    int lq = get(l, r, tl, tm, left);
    int rq = get(l, r, tm + 1, tr, right);
    return max(lq, rq);
}
////////////////////////////////////////////////////////////////////////////////
int main() {
    #define TASK "test"
    // #define TASK "1709d"
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    ////////////////////////////////////////
    cin >> n >> m;
    
    resize(m + 1, a);
    FOR(i, 1, m) {
        cin >> a[i];
    }
    
    resize(m * 4 + 4, st);
    build();
    
    cin >> q;
    while (q--) {
        int x1, x2, y1, y2, k;
        cin >> x1 >> y1 >> x2 >> y2 >> k;
        
        bool ans = [&]() {
            if (abs(y1 - y2) % k) return false;
            if (x1 % k != x2 % k) return false;
            
            int mx = get(min(y1, y2), max(y1, y2));
            int p = (n - x1) / k * k + x1;
            // print(p, mx);
            if (p > n || p <= mx) return false;
            
            return true;
        }();
        
        cout << (ans ? "YES" : "NO") << nl; 
    }
    ////////////////////////////////////////
}