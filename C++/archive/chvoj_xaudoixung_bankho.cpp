#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "xaudoixung"
#endif
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define str string
#define nl '\n'
#define sp ' '
#define all(var) (var).begin(), (var).end()
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define Repd(i, n) for (int i = (n); i--; )
#define For(i, l, r) for (int i = (l), _r = (r); i < _r; i++)
#define Ford(i, r, l) for (int i = (r), _l = (l); --i >= _l; )
#define Fore(i, l, r) for (int i = (l), _r = (r); i <= _r; i++)
#define Forde(i, r, l) for (int i = (r) + 1, _l = (l); --i >= _l; )
#define Forin(it, var) for (auto it : var)
#define Bmask(i) (1ULL << (i))
#define Bget(mask, i) ((mask >> (i)) & 1)
#define Blog(n) (63 - __builtin_clzll(n))
template <class T = int>
T inp() { T x; cin >> x; return x; }
template <class... T>
void print(T&&... n) {
    using exp = int[];
    exp{0, (cout << n << sp, 0)...};
    cout << nl;
}
template <class T>
void mxmz(T &a, T b) { a = max(a, b); }
template <class T>
void mnmz(T &a, T b) { a = min(a, b); }
const int N = 1e6;
const ull MOD = 1e9 + 7;
const ull BASE = 311;
const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
const int dx[8] = {0, -1, 0, 1, -1, -1, 1, 1};
const int dy[8] = {-1, 0, 1, 0, -1, 1, 1, -1};

// http://chvoj.edu.vn/problem/xaudoixung_bankho
// string, binsearch

////////////////////////////////////////
int main() {
    // freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////
    str s;
    cin >> s;
    
    int n = s.size();
    s = sp + s;
    
    vector<ull> POW(N + 1);
    POW[0] = 1;
    Fore(i, 1, n) POW[i] = POW[i - 1] * BASE;
    
    vector<ull> pre(n + 1), suf(n + 2);
    Fore(i, 1, n) pre[i] = pre[i - 1] * BASE + (ull)s[i];
    Forde(i, n, 1) suf[i] = suf[i + 1] * BASE + (ull)s[i];
        
    auto getl = [&POW, &pre](int l, int r) {
        return pre[r] - pre[l - 1] * POW[r - l + 1];
    };
    auto getr = [&POW, &suf](int l, int r) {
        return suf[l] - suf[r + 1] * POW[r - l + 1];
    };
    
    int ans = 1;
    For(i, 2, n) {
        int lo = 0, hi = min(i - 1, n - i) + 1;
        while (lo < hi) {
            int md = (lo + hi) / 2;
            if ([&](int len) {
                int l = i - len, r = i + len;
                if (l < 0 || r > n) return false;
                return getl(l, i) == getr(i, r);
            }(md)) {
                lo = md + 1;
            } else {
                hi = md;
            }
        }
        mxmz(ans, (lo - 1) * 2 + 1);
    }
    
    For(i, 1, n) {
        int lo = 0, hi = min(i, n - i) + 1;
        while (lo < hi) {
            int md = (lo + hi) / 2;
            if ([&](int len) {
                int l = i - len + 1, r = i + len;
                if (l < 0 || r > n) return false;
                return getl(l, i) == getr(i + 1, r);
            }(md)) {
                lo = md + 1;
            } else {
                hi = md;
            }
        }
        mxmz(ans, (lo - 1) * 2);
    }
    
    cout << ans;
    ////////////////
    return 0;
}