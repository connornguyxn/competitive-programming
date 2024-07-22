#if DEBUG
    #include "lib/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "b"
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

// https://oj.vnoi.info/problem/sqrt_b
// sqrtdcmp

struct range {
    int l, r;
    bool rev = false;
    ll sum = 0;
};
ostream& operator<<(ostream& out, const range& r) {
    out << '(' << r.l << ", " << r.r << ", " << r.sum << ", " << r.rev << ')';
    return out;
}
////////////////////////////////////////
////////////////////////////////////////
int main() {
    // freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////////
    int n, q;
    cin >> n >> q;
    
    vector<ll> a(n);
    Rep(i, n) cin >> a[i];
    
    int sz = sqrt(n);
    vector<range> ranges;
    
    auto build = [&]() {
        int pos = 0;
        ranges.assign((n - 1) / sz + 1, range{});
        Forin(cur, ranges) {
            cur.l = sz * pos++;
            cur.r = min(cur.l + sz - 1, n - 1);
            For(i, cur.l, cur.r) {
                cur.sum += a[i];
            }
        }
    };
    build();
    
    auto split = [&](int p) -> int {
        int cpos = 0;
        // print(ranges);
        for (auto it = ranges.begin(); it != ranges.end(); it++) {
            cpos += it->r - it->l + 1;
            if (p + 1 == cpos) return it - ranges.begin();
            if (cpos <= p) continue;
            
            if (it->rev) reverse(it->l + a.begin(), a.begin() + it->r + 1);
            
            range lft{it->l, it->l - 1};
            For(i, cpos - (it->r - it->l + 1), p) {
                lft.sum += a[++lft.r];
            }
            range rgt{lft.r + 1, it->r, 0, it->sum - lft.sum};
            // print(lft, rgt);
            
            *it = lft;
            it = ranges.insert(++it, rgt);
            return it - 1 - ranges.begin();
        }
        return n;
    };
    
    Rep(_, q) {
        int t, l, r;
        cin >> t >> l >> r;
        l--;
        r--;
        
        if (ranges.size() >= sz * 3) {
            vector<ll> b;
            Forin(cur, ranges) {
                if (cur.rev) reverse(a.begin() + cur.l, a.begin() + cur.r + 1);
                b.insert(b.end(), a.begin() + cur.l, a.begin() + cur.r + 1);
            }
            a = b;
            
            build();
        };
        
        int lit = split(l - 1) + 1, rit = split(r);
        
        if (t == 1) {
            reverse(lit + ranges.begin(), ranges.begin() + rit + 1);
            for (auto it = ranges.begin() + lit; it != ranges.begin() + rit + 1; it++) {
                it->rev ^= 1;
            }
        } else {
            ll ans = 0;
            for (auto it = ranges.begin() + lit; it != ranges.begin() + rit + 1; it++) {
                ans += it->sum;
            }
            cout << ans << nl;
        }
        // print();
    }
    ////////////////////
    return 0;
}