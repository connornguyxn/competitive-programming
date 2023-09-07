#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "count"
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
const ll MOD = 1e9 + 7;
const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
const int dx[8] = {0, -1, 0, 1, -1, -1, 1, 1};
const int dy[8] = {-1, 0, 1, 0, -1, 1, 1, -1};

// count
// <tags>

int n;
vector<int> a;
////////////////////////////////////////
struct sub1 {
    sub1() {
        ll cnt = 0;
        Rep(i, n) {
            int mx = a[i], mn = a[i];
            For(j, i, n) {
                mxmz(mx, a[j]);
                mnmz(mn, a[j]);
                if (__gcd(mx, mn) == 1) cnt++;
            }
        }
        cout << cnt;
    }
};
/////////////////
struct sub2 {
    sub2() {
        int mx = 0;
        unordered_map<int, ll> cnt;
        for (int i = 0; i < n; i++) {
            cnt[a[i]]++;
            mxmz(mx, a[i]);
        }
        
        vector<ll> mul(mx + 1);
        for (int i = 1; i <= mx; i++) {
            for (int j = i; j <= mx; j += i) {
                mul[i] += cnt[j];
            }
        }
        
        vector<ll> dp(mx + 1);
        for (int i = mx; i >= 1; i--) {
            dp[i] = mul[i] * (mul[i] - 1) / 2;
            for (int j = i * 2; j <= mx; j += i) {
                dp[i] -= dp[j];
            }
        }
        
        cout << dp[1];
    }
};
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////
    cin >> n;
    a.resize(n);
    Rep(i, n) cin >> a[i];
    
    if (is_sorted(all(a))) {
        sub2();
    } else if (is_sorted(a.rbegin(), a.rend())) {
        reverse(all(a));
        sub2();
    } else {
        sub1();
    }
    ////////////////
    return 0;
}