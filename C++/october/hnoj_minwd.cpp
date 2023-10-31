#if DEBUG
    #include "lib/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "minwd"
#endif
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
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define Repd(i, n) for (int i = (n); i--; )
#define For(i, l, r) for (int i = (l), _r = (r); i <= _r; i++)
#define Fors(i, l, r) for (int i = (l), _r = (r); i < _r; i++)
#define Ford(i, r, l) for (int i = (r) + 1, _l = (l); --i >= _l; )
#define Forin(it, var) for (auto& it : var)
#define bmask(i) (1ULL << (i))
#define bget(mask, i) ((mask >> (i)) & 1)
#define blog2(n) (63 - __builtin_clzll(n))
const int N = 1e6;
const ll MOD = 1e9 + 7;
const ull BASE = 311;
const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
const int dx[8] = {0, -1, 0, 1, -1, -1, 1, 1};
const int dy[8] = {-1, 0, 1, 0, -1, 1, 1, -1};
template <class... T>
void print(T&&... n) {
    using exp = int[];
    exp{0, (cout << n << sp, 0)...};
    cout << endl;
}
template <class T>
bool mxmz(T &a, T b) { return (b > a ? a = b, 1 : 0); }
template <class T>
bool mnmz(T &a, T b) { return (b < a ? a = b, 1 : 0); }
void add(ll &a, ll b) { a = (a + b) % MOD; }
void sub(ll &a, ll b) { a = (a + MOD - b) % MOD; }
void mul(ll &a, ll b) { a = a * (b % MOD) % MOD; }

// hnoj_minwd
// <tags>

struct pos {
    int x;
    ll w;
    int id;
};
ostream& operator<<(ostream& os, const pos& p) {
    return os << '(' << p.x << sp << p.w << sp << p.id << ')';
}
struct query {
    int l, r, id;
};
ostream& operator<<(ostream& os, const query& q) {
    return os << '(' << q.l << sp << q.r << sp << q.id << ')';
}
struct segtree {
    int n;
    vector<ll> st;
    
    segtree(int _n) : n(_n), st(n * 4, INFLL) {}
    
    void update(int p, ll v, int tl = 0, int tr = -1, int tv = 1) {
        if (tr < 0) tr = n - 1;
        if (p < tl || tr < p) return;
        if (tl == tr) {
            mnmz(st[tv], v);
        } else {
            int tm = (tl + tr) / 2;
            update(p, v, tl, tm, tv * 2);
            update(p, v, tm + 1, tr, tv * 2 + 1);
            st[tv] = min(st[tv * 2], st[tv * 2 + 1]);
        }
    }
    
    ll get(int l, int r, int tl = 0, int tr = -1, int tv = 1) {
        if (tr < 0) tr = n - 1;
        if (r < tl || tr < l) return INF;
        if (l <= tl && tr <= r) return st[tv];
        int tm = (tl + tr) / 2;
        return min(get(l, r, tl, tm, tv * 2), get(l, r, tm + 1, tr, tv * 2 + 1));
    }
};
////////////////////////////////////////
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////////
    int n, q;
    cin >> n >> q;
    
    vector<pos> a(n);
    vector<int> ps(n);
    Rep(i, n) {
        cin >> a[i].x >> a[i].w;
        a[i].id = i;
    }
    
    sort(all(a), [](const pos& a, const pos& b) {
        return a.x < b.x;
    });
    Rep(i, n) ps[a[i].id] = i;
    
    vector<vector<pair<ll, int>>> add(n);
    
    deque<int> stk{0};
    For(i, 1, n - 1) {
        while (stk.size() && a[stk.back()].w <= a[i].w) stk.pop_back();
        if (stk.size()) {
            int p = stk.back();
            add[i].emplace_back((a[p].w + a[i].w) * (a[i].x - a[p].x), p);
        }
        stk.push_back(i);
    }
    
    stk = {n - 1};
    Repd(i, n - 1) {
        while (stk.size() && a[stk.back()].w <= a[i].w) stk.pop_back();
        if (stk.size()) {
            int p = stk.back();
            add[p].emplace_back((a[p].w + a[i].w) * (a[p].x - a[i].x), i);
        }
        stk.push_back(i);
    }
    // print(add);
    
    vector<query> qs;
    Rep(i, q) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        qs.push_back({l, r, i});
    }
    sort(all(qs), [&ps](const query& a, const query& b) {
        return ps[a.r] < ps[b.r];
    });
    // print(qs);
    
    segtree st(n);
    vector<ll> ans(q);
    
    int j = 0;
    Forin(cur, qs) {
        while (j <= ps[cur.r]) {
            Forin(it, add[j]) {
                st.update(it.se, it.fi);
            }
            j++;
        }
        ans[cur.id] = st.get(ps[cur.l], ps[cur.r]);
    }
    
    Forin(it, ans) cout << it << nl;
    ////////////////////
    return 0;
}