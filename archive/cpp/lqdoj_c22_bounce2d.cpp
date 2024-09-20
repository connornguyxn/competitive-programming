#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using str = string;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define fi first
#define se second
#define nl '\n'
#define sp ' '
#define all(a) (a).begin(), (a).end()
#define FOR1(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FOR2(i, l, r) for (int i = (l), _r = (r); i <= _r; i++)
#define FOR3(i, r, l, sp) for (int i = (r), _l = (l); i >= _l; i--)
#define OVERLOAD(a, b, c, d, e, ...) e
#define FOR(...) OVERLOAD(__VA_ARGS__, FOR3, FOR2, FOR1)(__VA_ARGS__)
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

// https://lqdoj.edu.vn/problem/lqdoj2022r8bounce2d
// dp

struct Pt {
    ll x, y;
    bool t;
    bool operator<(const Pt& o) const {
        if (x != o.x) return x < o.x;
        return y < o.y;
    }
};
int n, m;
ll w, h;
vector<Pt> a;
vector<vector<ll>> dp;
////////////////////////////////////////
ll solve(int cur, int curk) {
    if (cur == n) return 0;
    
    if (a[cur].t) curk = 0;
    
    ll& res = dp[cur][curk];
    if (res != -1) return res;
    res = INF;
    
    int mx = -1, my = -1;
    FOR(nxt, cur + 1, n) {
        if (a[nxt].x == a[cur].x) {
            if (mx == -1 || a[mx].y > a[nxt].y) mx = nxt;
        }
        if (a[nxt].y == a[cur].y) {
            if (my == -1 || a[my].x > a[nxt].x) my = nxt;
        }
    }
    
    auto go = [&](int nxt) {
        ll dst = max(a[nxt].x - a[cur].x, a[nxt].y - a[cur].y);
        if (a[cur].t) {
            res = min(res, solve(nxt, 0) + dst);
        } else {
            if (dst % bmask(curk) == 0) {
                res = min(res, solve(nxt, curk) + dst / bmask(curk));
            }
            if (dst % bmask(curk + 1) == 0) {
                res = min(res, solve(nxt, curk + 1) + dst / bmask(curk + 1));
            }
        }
    };
    
    if (mx != -1) go(mx);
    if (my != -1) go(my);
    
    return res;
}
////////////////////////////////////////
int main() {
    #define TASK "bounce2d"
    // #define TASK "test"
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    ////////////////////////////////////////
    cin >> w >> h >> n >> m;
    
    resize(n + m, a);
    FOR(i, n) {
        cin >> a[i].x >> a[i].y;
        a[i].t = 0;
    }
    FOR(i, m) {
        cin >> a[n + i].x >> a[n + i].y;
        a[n + i].t = 1;
    }
    
    sort(all(a));
    a.insert(a.begin(), {0, 0, 1});
    a.push_back({w, h, 0});
    n = a.size() - 1;
    
    // FORIN(it, a) print(it.x, it.y, it.t);
    // print();
    
    dp.assign(n, vector<ll>(32, -1));
    cout << solve(0, 0);
    
    // FORIN(it, dp) print(it);
    ////////////////////////////////////////
}