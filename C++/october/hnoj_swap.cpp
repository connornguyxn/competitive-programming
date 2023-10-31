#if DEBUG
    #include "lib/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "swap"
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

// hnoj_swap
// <tags>

struct node {
    int val, pos;
    bool operator < (const node& o) const {
        if (val == o.val) return pos < o.pos;
        return val < o.val;
    }
};
int n, k;
vector<int> a, st_cnt;
vector<node> st_max;
////////////////////////////////////////
void build(int tl = 0, int tr = n - 1, int tv = 1) {
    if (tl == tr) {
        st_max[tv] = {a[tl], tl};
    } else {
        int tm = (tl + tr) / 2;
        build(tl, tm, tv * 2);
        build(tm + 1, tr, tv * 2 + 1);
        st_max[tv] = max(st_max[tv * 2], st_max[tv * 2 + 1]);
    }
}
////////////////////
void upd_max(int pos, int val, int tl = 0, int tr = n - 1, int tv = 1) {
    if (tl == tr) {
        st_max[tv].val = val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm) upd_max(pos, val, tl, tm, tv * 2);
        else upd_max(pos, val, tm + 1, tr, tv * 2 + 1);
        st_max[tv] = max(st_max[tv * 2], st_max[tv * 2 + 1]);
    }
}
void upd_cnt(int pos, int val, int tl = 0, int tr = n - 1, int tv = 1) {
    if (tl == tr) {
        st_cnt[tv] = val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm) upd_cnt(pos, val, tl, tm, tv * 2);
        else upd_cnt(pos, val, tm + 1, tr, tv * 2 + 1);
        st_cnt[tv] = st_cnt[tv * 2] + st_cnt[tv * 2 + 1];
    }
}
////////////////////
node get_max(int l, int r, int tl = 0, int tr = n - 1, int tv = 1) {
    if (r < tl || tr < l) return {-INF, -1};
    if (l <= tl && tr <= r) return st_max[tv];
    int tm = (tl + tr) / 2;
    return max(get_max(l, r, tl, tm, tv * 2), get_max(l, r, tm + 1, tr, tv * 2 + 1));
}
int get_bound(int tl = 0, int tr = n - 1, int tv = 1) {
    if (tl == tr) return tl;
    int tm = (tl + tr) / 2;
    if (st_cnt[tv << 1 | 1] <= k) return get_bound(tm + 1, tr, tv << 1 | 1);
    else return get_bound(tl, tm, tv << 1);
}
int get_cnt(int pos, int tl = 0, int tr = n - 1, int tv = 1) {
    if (tl == tr) return st_cnt[tv];
    int tm = (tl + tr) / 2;
    if (pos <= tm) return get_cnt(pos, tl, tm, tv * 2);
    else return st_cnt[tv * 2] + get_cnt(pos, tm + 1, tr, tv * 2 + 1);
}
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////////
    cin >> n >> k;
    a.resize(n);
    Rep(i, n) cin >> a[i];
    
    st_max.resize(n * 4);
    st_cnt.resize(n * 4);
    build();
    
    vector<bool> mk(n);
    vector<int> ans;
    ans.reserve(n);
    
    while (k > 0) {
        int bound = get_bound();
        node num = get_max(0, bound);
        int cost = num.pos - get_cnt(num.pos);
        
        // print(k, bound);
        // print(num.val, num.pos, cost);
        
        if (num.val == 0 || cost > k) break;
        
        k -= cost - 1;
        ans.push_back(num.val);
        mk[num.pos] = 1;
        upd_max(num.pos, 0);
        upd_cnt(num.pos, 1);
        
        // print(mk);
        // print("end", nl);
    }
    Forin(it, ans) cout << it << sp;
    Rep(i, n) if (!mk[i]) cout << a[i] << sp;
    ////////////////////
    return 0;
}