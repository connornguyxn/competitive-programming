#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "paliny"
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
    cout << endl;
}
template <class T>
void mxmz(T &a, T b) { a = max(a, b); }
template <class T>
void mnmz(T &a, T b) { a = min(a, b); }
const ull MOD = 1e9 + 7;
const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
const int dx[8] = {0, -1, 0, 1, -1, -1, 1, 1};
const int dy[8] = {-1, 0, 1, 0, -1, 1, 1, -1};

// https://oj.vnoi.info/problem/paliny
// string, binsearch, hashing

const ll MOD1 = 1e9 + 7, MOD2 = 1e9 + 9, BASE = 311;
const int N = 1e6;
vector<ll> bp1(N + 1), bp2(N + 1);
////////////////////////////////////////
struct Hash {
    vector<ll> h1, h2;
    void init(str s) {
        s = sp + s;
        h1.resize(s.size());
        h2.resize(s.size());
        For(i, 1, s.size() - 1) {
            h1[i] = (h1[i - 1] * BASE + s[i] - 'a') % MOD1;
            h2[i] = (h2[i - 1] * BASE + s[i] - 'a') % MOD2;
        }
    }
    
    ll get(int l, int r) {
        l++; r++;
        ll v1 = (h1[r] - h1[l - 1] * bp1[r - l + 1] + MOD1 * MOD1) % MOD1;
        ll v2 = (h2[r] - h2[l - 1] * bp2[r - l + 1] + MOD2 * MOD2) % MOD2;
        return v1 << 32 | v2;
    }
};
////////////////////////////////////////
void prep() {
    bp1[0] = bp2[0] = 1;
    For(i, 1, N) {
        bp1[i] = bp1[i - 1] * BASE % MOD1;
        bp2[i] = bp2[i - 1] * BASE % MOD2;
    }
}
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////
    prep();
    int n;
    cin >> n;
    
    str s;
    cin >> s;
    
    Hash pre;
    pre.init(s);
    reverse(all(s));
    Hash suf;
    suf.init(s);
    
    int ans = 1;
    For(i, 2, n) {
        int lo = 0, hi = min(i - 1, n - i) + 1;
        while (lo < hi) {
            int md = (lo + hi) / 2;
            if ([&](int len) {
                int l = i - len, r = i + len;
                if (l < 0 || r > n) return false;
                return pre.get(l, i) == suf.get(n + 1 - r, n + 1 - i);
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
                return pre.get(l, i) == suf.get(n + 1 - r, n + 1 - (i + 1));
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