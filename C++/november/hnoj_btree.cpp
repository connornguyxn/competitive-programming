#if DEBUG
    #include "lib/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "btree"
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

// https://hnoj.edu.vn/contest/lqtbr2/
// implementation

ll ans = 0;
vector<int> a;
vector<vector<int>> st;
////////////////////////////////////////
void solve(int tl, int tr, int tv) {
    if (tl > tr) return;
    if (tl == tr) {
        st[tv] = {a[tl]};
        return;
    }
    int tm = (tl + tr) / 2;
    solve(tl, tm, tv * 2);
    solve(tm + 1, tr, tv * 2 + 1);
    
    vector<int>& l = st[tv * 2], r = st[tv * 2 + 1];
    merge(all(l), all(r), back_inserter(st[tv]));
    
    ll ansl = 0, ansr = 0;
    Forin(it, l) ansl += upper_bound(all(r), it) - r.begin();
    Forin(it, r) ansr += upper_bound(all(l), it) - l.begin();
    ans += min(ansl, ansr);
}
////////////////////////////////////////
int main() {
    // freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////////
    int n;
    cin >> n;
    n = bmask(n);
    
    a.resize(n);
    Rep(i, n) cin >> a[i];
    
    st.resize(n * 4);
    solve(0, n - 1, 1);
    
    cout << ans;
    ////////////////////
    return 0;
}