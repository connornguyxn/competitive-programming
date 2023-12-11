#if DEBUG
    #include "lib/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "4c"
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
bool mxmz(T &a, T b) { return a < b ? a = b, 1 : 0; }
template <class T>
bool mnmz(T &a, T b) { return b < a ? a = b, 1 : 0; }
void add(ll &a, ll b) { a = (a + b) % MOD; }
void sub(ll &a, ll b) { a = (a + MOD - b) % MOD; }
void mul(ll &a, ll b) { a = a * (b % MOD) % MOD; }

// https://tbhnptlcqntn2023.contest.codeforces.com/group/ZosfxzdjkV/contest/485820/problem/C
// 2ptrs, datastruct

int n, m;
vector<int> a, st, lz;
////////////////////////////////////////
void build(int tl = 1, int tr = m, int tv = 1) {
    if (tl == tr) {
        st[tv] = -tl;
    } else {
        int tm = (tl + tr) / 2;
        build(tl, tm, tv * 2);
        build(tm + 1, tr, tv * 2 + 1);
        st[tv] = max(st[tv * 2], st[tv * 2 + 1]);
    }
}
////////////////////
void push(int tv) {
    st[tv * 2] += lz[tv];
    st[tv * 2 + 1] += lz[tv];
    
    lz[tv * 2] += lz[tv];
    lz[tv * 2 + 1] += lz[tv];
    
    lz[tv] = 0;
}
////////////////////
int query(int l, int r, int tl = 1, int tr = m, int tv = 1) {
    if (r < tl || tr < l) return -INF;
    if (l <= tl && tr <= r) return st[tv];
    
    push(tv);
    int tm = (tl + tr) / 2;
    return max(query(l, r, tl, tm, tv * 2), query(l, r, tm + 1, tr, tv * 2 + 1));
}
////////////////////
void update(int l, int r, int v, int tl = 1, int tr = m, int tv = 1) {
    if (r < tl || tr < l) return;
    if (l <= tl && tr <= r) {
        st[tv] += v;
        lz[tv] += v;
    } else {
        push(tv);
        int tm = (tl + tr) / 2;
        update(l, r, v, tl, tm, tv * 2);
        update(l, r, v, tm + 1, tr, tv * 2 + 1);
        st[tv] = max(st[tv * 2], st[tv * 2 + 1]);
    }
}
////////////////////////////////////////
int main() {
    // freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////////
    cin >> n;
    a.resize(n);
    Rep(i, n) {
        cin >> a[i];
        mxmz(m, a[i]);
    }
    
    st.resize(m * 4 + 4);
    lz = st;
    build();
    
    ll ans = 0;
    for (int l = 0, r = 0; r < n; r++) {
        update(a[r], m, 1);
        
        while (query(1, m) > 0) {
            update(a[l], m, -1);
            l++;
        }
        
        ans += r - l + 1LL;
    }
    cout << ans;
    ////////////////////
    return 0;
}