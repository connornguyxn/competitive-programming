#if DEBUG
    #include "lib/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "a"
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
void mxmz(T &a, T b) { a = max(a, b); }
template <class T>
void mnmz(T &a, T b) { a = min(a, b); }
void add(ll &a, ll b) { a = (a + b) % MOD; }
void sub(ll &a, ll b) { a = (a + MOD - b) % MOD; }
void mul(ll &a, ll b) { a = a * (b % MOD) % MOD; }

// https://oj.vnoi.info/problem/sqrt_a
// sqrtd, segtree, easy

////////////////////////////////////////
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////////
    int n, q;
    cin >> n >> q;
    int sq = sqrt(n);
    
    vector<ll> a(n);
    Rep(i, n) cin >> a[i];
    
    vector<ll> seg(sq + 2);
    Rep(i, n) {
        seg[i / sq] += a[i];
    }
    
    Rep(_, q) {
        int t, l, r;
        cin >> t >> l >> r;
        l--;
        if (t == 1) {
            seg[l / sq] += r - a[l];
            a[l] = r;
        } else {
            ll ans = 0;
            Fors(i, l, r) {
                if (i % sq || i + sq - 1 >= r) {
                    ans += a[i];
                } else {
                    ans += seg[i / sq];
                    i += sq - 1;
                }
            }
            cout << ans << nl;
        }
    }
    ////////////////////
    return 0;
}