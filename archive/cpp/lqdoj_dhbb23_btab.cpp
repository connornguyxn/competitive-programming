#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #pragma GCC optimize("O3,unroll-loops")
    #pragma GCC target("sse4.2")
    #include <bits/stdc++.h>
    #define TASK "btab"
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
#define all(VAR) (VAR).begin(), (VAR).end()
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define Repd(i, n) for (int i = (n); i--; )
#define For(i, l, r) for (int i = (l), _b = (r); i < _b; i++)
#define Ford(i, r, l) for (int i = (r), _a = (l); --i >= _a; )
#define Fore(i, l, r) for (int i = (l), _b = (r); i <= _b; i++)
#define Forde(i, r, l) for (int i = (r), _a = (l); i >= _a; i++)
#define Forin(it, var) for (auto it : var)
template<typename tVar, typename tVal>
void mnmz(tVar &var, tVal val) { if (val < var) var = val; }
template<typename tVar, typename tVal>
void mxmz(tVar &var, tVal val) { if (val > var) var = val; }
#define bmask(POS) (1ULL << (POS))
#define bget(MASK, POS) ((MASK >> (POS)) & 1)
#define blog2(NUM) (__builtin_clzll(1) - __builtin_clzll(NUM))
const int N = 1e6;
const ll MOD = 1e9 + 7;
const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
const int dx[8] = {0, -1, 0, 1, -1, -1, 1, 1};
const int dy[8] = {-1, 0, 1, 0, -1, 1, 1, -1};

// https://lqdoj.edu.vn/contest/dhbb23
// dp

////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(0);
    ////////////////
    int n, m;
    cin >> n >> m;
    
    vector<int> a(n + 1), sa(n + 1);
    Fore(i, 1, n) {
        cin >> a[i];
    }
    partial_sum(all(a), sa.begin());
    
    vector<int> b(m + 1), sb(m + 1);
    Fore(i, 1, m) {
        cin >> b[i];
    };
    partial_sum(all(b), sb.begin());
    
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1));
    
    Fore(i, 1, n) {
        Fore(j, 1, m) {
            if (a[i] * b[j] != 1) continue;
            
            for (int x = i - 1, y = j - 1; a[x] * b[y] == 1; x--, y--) {
                if (sa[i] == sa[x - 1] && sb[j] == sb[y - 1]) {
                    dp[i][j] = dp[x - 1][y - 1] + 1;
                    break;
                }
            }
        }
    }
    
    // db(dp);
    
    ll ans = 0;
    Fore(i, 1, n) {
        Fore(j, 1, m) {
            ans += dp[i][j];
        }
    }
    
    cout << ans;
    ////////////////
    return 0;
}