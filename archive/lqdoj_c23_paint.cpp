#if DEBUG
    #include "lib/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "paint"
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

// https://lqdoj.edu.vn/problem/lqdoj2023r8paint
// dp

int n, one, two;
vector<int> a, st;
int dp[2000][2000];
////////////////////////////////////////
void update(int p, int v, int tl = 1, int tr = n, int tv = 1) {
    if (tr < p || p < tl) return;
    if (tl == p && tr == p) {
        st[tv] = v;
    } else {
        int tm = (tl + tr) / 2;
        update(p, v, tl, tm, tv * 2);
        update(p, v, tm + 1, tr, tv * 2 + 1);
        st[tv] = min(st[tv * 2], st[tv * 2 + 1]);
    }
}
////////////////////
int query(int l, int r, int tl = 1, int tr = n, int tv = 1) {
    if (r < tl || tr < l) return 0;
    if (l <= tl && tr <= r) return st[tv];
    int tm = (tl + tr) / 2;
    return min(query(l, r, tl, tm, tv * 2), query(l, r, tm + 1, tr, tv * 2 + 1));
}
////////////////////////////////////////
int solve(int id, int cnt1) {
    if (id > n) {
        
    }
    int& res = dp[id][cnt1];
    if (res > -1) return res;
    res = 0;
    
    
}
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////////
    cin >> n >> one >> two;
    
    a.resize(n + 1);
    For(i, 1, n) {
        cin >> a[i];
    }
    sort(1 + all(a));
    
    st.resize(n * 4 + 4);
    
    auto ok = [&](int w) {
        memset(dp, -1, sizeof(dp));
        
    };
    
    int al = 0, ar = INF;
    while (al < ar) {
        int am = (al + ar) / 2;
        if (ok(am)) {
            ar = am;
        } else {
            al = am + 1;
        }
    }
    cout << al;
    ////////////////////
    return 0;
}