#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "pizza"
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
template <typename... T>
void print(T&&... n) {
    using exp = int[];
    exp{0, (cout << n << sp, 0)...};
    cout << nl;
}
template <class T>
void mxmz(T &a, T b) { a = max(a, b); }
template <class T>
void mnmz(T &a, T b) { a = max(a, b); }
const int N = 1e7;
const ll MOD = 1e9 + 7;
const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
const int dx[8] = {0, -1, 0, 1, -1, -1, 1, 1};
const int dy[8] = {-1, 0, 1, 0, -1, 1, 1, -1};

// pizza
// <tags>

////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////
    vector<int> spf(N + 1, 2);
    for (int i = 3; i * i <= N; i += 2) {
        if (spf[i] > 2) continue;
        spf[i] = i;
        for (int j = i * i; j <= N; j += i * 2) {
            spf[j] = i;
        }
    }
    
    auto fct = [&](int n) {
        unordered_map<ll, int> cnt;
        while (n > 1) {
            cnt[spf[n]]++;
            n /= spf[n];
        }
        return cnt;
    };
    
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        
        unordered_map<ll, int> fn = fct(n), fk = fct(k);
        Forin(it, fk) {
            mxmz(fn[it.fi], it.se);
        }
        
        ll p = 1;
        Forin(it, fn) {
            Rep(_, it.se + it.se % 2) {
                p *= it.fi;
            }
        }
        
        cout << p / k << nl;
    }
    ////////////////
    return 0;
}
