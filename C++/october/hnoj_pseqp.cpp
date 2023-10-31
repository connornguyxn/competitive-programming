#if DEBUG
    #include "lib/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "pseqp"
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
bool mxmz(T &a, T b) { if (b > a) return a = b, 1; }
template <class T>
bool mnmz(T &a, T b) { if (b < a) return a = b, 1; }
void add(ll &a, ll b) { a = (a + b) % MOD; }
void sub(ll &a, ll b) { a = (a + MOD - b) % MOD; }
void mul(ll &a, ll b) { a = a * (b % MOD) % MOD; }

// https://hnoj.edu.vn/problem/pseqp
// segtree, implementation

struct segtree {
    int n;
    vector<int> st;
    
    void build(const vector<int>& a, int tl, int tr, int tv = 1) {
        if (tl == tr) {
            st[tv] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(a, tl, tm, tv * 2);
            build(a, tm + 1, tr, tv * 2 + 1);
            st[tv] = max(st[tv * 2], st[tv * 2 + 1]);
        }
    }
    
    segtree(const vector<int>& a) : n(a.size()), st(n * 4) {
        build(a, 0, n - 1);
    }
    
    void update(int p, int v, int tl = 0, int tr = -1, int tv = 1) {
        if (tr < 0) tr = n - 1;
        if (p < tl || tr < p) return;
        if (tl == tr) {
            st[tv] = v;
        } else {
            int tm = (tl + tr) / 2;
            update(p, v, tl, tm, tv * 2);
            update(p, v, tm + 1, tr, tv * 2 + 1);
            st[tv] = max(st[tv * 2], st[tv * 2 + 1]);
        }
    }
    
    int get(int l, int r, int tl = 0, int tr = -1, int tv = 1) {
        if (tr < 0) tr = n - 1;
        if (r < tl || tr < l) return -INF;
        if (l <= tl && tr <= r) return st[tv];
        int tm = (tl + tr) / 2;
        return max(get(l, r, tl, tm, tv * 2), get(l, r, tm + 1, tr, tv * 2 + 1));
    }
};
////////////////////////////////////////
////////////////////////////////////////
int main() {
    // freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////////
    int n, q;
    cin >> n >> q;
    vector<int> pos(n + 1);
    Rep(i, n) {
        int tmp;
        cin >> tmp;
        pos[tmp] = i;
    }
    // print(pos);
    
    vector<int> dst(n), a(n);
    Rep(i, n) {
        cin >> a[i];
        dst[(i - pos[a[i]] + n) % n]++;
    }
    // print(dst);
    
    segtree ans(dst);
    Rep(_, q) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        
        dst[(l - pos[a[l]] + n) % n]--;
        dst[(r - pos[a[r]] + n) % n]--;
        ans.update((l - pos[a[l]] + n) % n, dst[(l - pos[a[l]] + n) % n]);
        ans.update((r - pos[a[r]] + n) % n, dst[(r - pos[a[r]] + n) % n]);
        
        swap(a[l], a[r]);
        
        dst[(l - pos[a[l]] + n) % n]++;
        dst[(r - pos[a[r]] + n) % n]++;
        ans.update((l - pos[a[l]] + n) % n, dst[(l - pos[a[l]] + n) % n]);
        ans.update((r - pos[a[r]] + n) % n, dst[(r - pos[a[r]] + n) % n]);
        
        cout << ans.get(0, n) << nl;
        // print(dst);
    }
    ////////////////////
    return 0;
}