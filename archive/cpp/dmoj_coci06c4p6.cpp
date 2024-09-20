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
#define lnode (tv * 2)
#define rnode (tv * 2 + 1)
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
basic_ostream<Ch, Tr>& operator<<(basic_ostream<Ch, Tr>& cout, C& a) {
    cout << "{ ";
    FORIN(it, a) cout << it << sp;
    return cout << "}";
}
template <class T1, class T2>
ostream& operator<<(ostream& cout, pair<T1, T2> a) {
    return cout << '(' << a.fi << sp << a.se << ')';
}

// https://dmoj.ca/problem/coci06c4p6
// segtree

struct Q {
    char t;
    int x, y;
};
int q;
vector<Q> qs;
////////////////////////////////////////////////////////////////////////////////
namespace sub1 {
    int n;
    vector<pii> st;
    ////////////////////////////////////////
    pii combine(pii a, pii b) {
        return max(a, b);
    }
    ////////////////////////////////////////
    void update(int p, pii v, int tl = 0, int tr = n, int tv = 1) {
        if (tl == tr) {
            st[tv] = v;
            return;
        }
        int tm = (tl + tr) / 2;
        if (p <= tm) update(p, v, tl, tm, lnode);
        else update(p, v, tm + 1, tr, rnode);
        st[tv] = combine(st[lnode], st[rnode]);
    }
    ////////////////////////////////////////
    pii get(int l, int r, int tl = 0, int tr = n, int tv = 1) {
        if (tr < l || r < tl) return {-1, -1};
        if (l <= tl && tr <= r) return st[tv];
        int tm = (tl + tr) / 2;
        return combine(get(l, r, tl, tm, lnode), get(l, r, tm + 1, tr, rnode));
    }
    ////////////////////////////////////////
    void main() {
        vector<pii> zip;
        FORIN(cq, qs) {
            if (cq.t == 'D') zip.push_back({cq.y, cq.x});
        }
        sort(all(zip));
        // zip.erase(unique(all(zip)), zip.end());
        auto getpos = [&](pii a) -> int {
            return lower_bound(all(zip), a) - zip.begin();
        };
        // print(zip);
        
        n = zip.size();
        resize(n * 4, st);
        
        vector<pii> a;
        FORIN(cq, qs) {
            if (cq.t == 'D') {
                a.push_back({cq.x, cq.y});
                update(getpos({cq.y, cq.x}), {cq.x, (int)a.size()});
            } else {
                pii cur = a[cq.x - 1];
                pii rev = {cur.se, cur.fi};
                int p = getpos(rev), lo = p + 1, hi = n - 1, res = -1;
                // print(cur, p, lo, hi);
                while (lo <= hi) {
                    int mid = (lo + hi) / 2;
                    // print(mid, get(p + 1, mid).fi);
                    if (get(p + 1, mid).fi >= cur.fi) {
                        res = mid;
                        hi = mid - 1;
                    } else {
                        lo = mid + 1;
                    }
                }
                pii ans = get(p + 1, res);
                // print(res, ans);
                if (ans.fi == -1 || ans.se == cq.x) {
                    cout << "NE";
                } else {
                    cout << ans.se;
                }
                cout << nl;
            }
            // FOR(i, 0, n - 1) cout << get(i, i) << sp;
            // print();
        }
    }
}
////////////////////////////////////////////////////////////////////////////////
int main() {
    #define TASK "test"
    // #define TASK "coci06c4p6"
    // freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    ////////////////////////////////////////
    cin >> q;
    resize(q, qs);
    
    FORIN(it, qs) {
        cin >> it.t >> it.x;
        if (it.t == 'D') cin >> it.y;
    }
    
    return sub1::main(), 0;
    ////////////////////////////////////////
}