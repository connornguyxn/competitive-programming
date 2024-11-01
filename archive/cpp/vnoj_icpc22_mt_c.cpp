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


// https://oj.vnoi.info/problem/icpc22_mt_c
// dp, segtree

int n, k;
vector<pii> a;
////////////////////////////////////////////////////////////////////////////////
namespace subf {
    ////////////////////////////////////////
    struct Segtree {
        vector<ll> st;
        Segtree() {
            st.resize(n * 4);
        }
        ////////////////////////////////////////
        void update(int p, ll v, int tl = 1, int tr = n, int tv = 1) {
            if (tl == tr) {
                st[tv] += v;
                return;
            }
            int tm = (tl + tr) / 2;
            if (p <= tm) update(p, v, tl, tm, tvl);
            else update(p, v, tm + 1, tr, tvr);
            st[tv] = st[tvl] + st[tvr];
        }
        ////////////////////////////////////////
        ll get(int l, int r, int tl = 1, int tr = n, int tv = 1) {
            if (r < tl || tr < l) return 0;
            if (l <= tl && tr <= r) return st[tv];
            int tm = (tl + tr) / 2;
            return get(l, r, tl, tm, tvl) + get(l, r, tm + 1, tr, tvr);
        }
    };
    ////////////////////////////////////////
    void main() {
        sort(1 + all(a));
        
        vector<Segtree> st(k);
        
        FOR(i, 1, n) {
            st[0].update(a[i].se, 1);
            FOR(cnt, 1, k - 1) {
                st[cnt].update(a[i].se, st[cnt - 1].get(1, a[i].se - 1));
            }
        }
        
        cout << st[k - 1].get(1, n);
    }
}
////////////////////////////////////////////////////////////////////////////////
int main() {
    #define TASK "vnoj_icpc22_mt_c"
    freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    atexit(logtime);
    ////////////////////////////////////////
    cin >> n >> k;
    
    resize(n + 1, a);
    FOR(i, 1, n) cin >> a[i].fi >> a[i].se;
    
    return subf::main(), 0;
    ////////////////////////////////////////
}