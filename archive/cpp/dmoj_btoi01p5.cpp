#pragma GCC optimize("O3")
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

// https://dmoj.ca/problem/btoi01p5
// https://oj.vnoi.info/problem/area
// sweepline, segtree, classic, adhoc

struct Line {
    ll x, miny, maxy, type;
    bool operator<(const Line& o) const {
        return x < o.x;
    }
};
struct Node {
    // cover: số cạnh *trực tiếp* cover cả đoạn hiện tại
    // cnt: độ dài đoạn đang được cover
    int cnt, cover;
};
const int N = 3e4 + 1;
array<Node, N * 4> st;
////////////////////////////////////////////////////////////////////////////////
void update(int l, int r, ll v, int tl = 0, int tr = N - 1, int tv = 1) {
    if (tr < l || r < tl) return;
    if (l <= tl && tr <= r) {
        st[tv].cover += v;
        if (st[tv].cover > 0) {
            st[tv].cnt = tr - tl + 1;
        } else {
            st[tv].cnt = tl == tr ? 0 : st[lnode].cnt + st[rnode].cnt;
        }
        return;
    }
    int tm = (tl + tr) / 2;
    update(l, r, v, tl, tm, lnode);
    update(l, r, v, tm + 1, tr, rnode);
    if (st[tv].cover > 0) {
        st[tv].cnt = tr - tl + 1;
    } else {
        st[tv].cnt = tl == tr ? 0 : st[lnode].cnt + st[rnode].cnt;
    }
}
////////////////////////////////////////////////////////////////////////////////
int main() {
    #define TASK "test"
    // #define TASK "dmoj_btoi01p5"
    // freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    ////////////////////////////////////////
    int n;
    cin >> n;
    vector<Line> a(1);
    
    FOR(i, 1, n) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        a.push_back({x1, y1, y2, 1});
        a.push_back({x2, y1, y2, -1});
    }
    sort(1 + all(a));
    
    // FORIN(it, a) print(it.x, it.miny, it.maxy, it.type);
    
    ll ans = 0;
    FOR(i, 1, n * 2) {
        ans += (a[i].x - a[i - 1].x) * st[1].cnt;
        update(a[i].miny, a[i].maxy - 1, a[i].type);
    }
    
    cout << ans;
    ////////////////////////////////////////
}