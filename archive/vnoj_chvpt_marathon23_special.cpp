#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "special"
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
#define Fors(i, l, r) for (int i = (l), _r = (r); i < _r; i++)
#define Forsd(i, r, l) for (int i = (r), _l = (l); --i >= _l; )
#define For(i, l, r) for (int i = (l), _r = (r); i <= _r; i++)
#define Ford(i, r, l) for (int i = (r) + 1, _l = (l); --i >= _l; )
#define Forin(it, var) for (auto it : var)
#define bmask(i) (1ULL << (i))
#define bget(mask, i) ((mask >> (i)) & 1)
#define blog(n) (63 - __builtin_clzll(n))
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
const int N = 1e6;
const ll MOD = 1e9 + 7;
const ull BASE = 311;
const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
const int dx[8] = {0, -1, 0, 1, -1, -1, 1, 1};
const int dy[8] = {-1, 0, 1, 0, -1, 1, 1, -1};

// https://oj.vnoi.info/problem/chvpt_chvmarathon2_special
// dp, math, matrix exponentiation


int n, k;
////////////////////////////////////////
struct sub2 {
    sub2() {
        vector<vector<ll>> dp(n + 1, vector<ll>(k));
        dp[0][0] = 1;
        
        For(i, 1, n) {
            dp[i][0] = dp[i - 1][0];
            Fors(j, 1, k) {
                (dp[i][j] += dp[i - 1][j - 1]) %= MOD;
                (dp[i][0] += dp[i - 1][j]) %= MOD;
            }
        }
        
        ll ans = 0;
        Rep(i, k) {
            (ans += dp[n][i]) %= MOD;
        }
        cout << ans << nl;
    }
};
////////////////////////////////////////
struct full {
    struct matrix {
        int n;
        vector<vector<ll>> mt;
        matrix(int _n) : n(_n), mt(_n, vector<ll>(_n)) {};
        
        matrix operator*(const matrix& oth) const {
            matrix res(n);
            
            Rep(i, n) {
                Rep(j, n) {
                    Rep(k, n) {
                        res.mt[i][j] = (res.mt[i][j] + mt[i][k] * oth.mt[k][j]) % MOD;
                    }
                }
            }
            
            return res;
        }
        
        matrix pow(int k) {
            matrix res(n), a = *this;
            Rep(i, n) {
                res.mt[i][i] = 1;
            }
            if (k == 0) return res;
            
            while (k > 0) {
                if (k % 2) res = res * a;
                a = a * a;
                k /= 2;
            };
            
            return res;
        }
    };
    ////////////////////////////////////////
    full() {
        matrix a(k), b(k);
        a.mt[k - 1][0] = 1;
        
        Rep(i, k - 1) {
            b.mt[i][i + 1] = 1;
        }
        Rep(i, k) {
            b.mt[i][0] = 1;
        }
        
        matrix res = a * b.pow(n);
        
        cout << accumulate(all(res.mt[k - 1]), 0LL) % MOD;
    }
};
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////
    cin >> n >> k;
    
    // sub2();
    // cout << nl;
    // full();
    
    if (n <= 2000 && k <= 2000) {
        sub2();
    } else {
        full();
    }
    ////////////////
    return 0;
}