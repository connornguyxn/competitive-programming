#if DEBUG
    #include "lib/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "zsum"
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

// nalgae_zsum
// dp, random

int n, k;
vector<vector<ll>> a;
////////////////////////////////////////
struct sub1 {
    vector<vector<ll>> dp;
    
    ll solve(int id, int sum) {
        if (id == n) return (sum == k * n ? 0 : INFLL);
        if (dp[id][sum] != -1) return dp[id][sum];
        
        dp[id][sum] = INFLL;
        For(i, -k, k) {
            mnmz(dp[id][sum], solve(id + 1, sum + i) + a[id][i + k]);
        }
        return dp[id][sum];
    }
    
    sub1() {
        dp.resize(n, vector<ll>(k * n + 1, -1));
        cout << solve(1, k * n);
    }
};
struct sub2 {
    sub2() {
        mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
        shuffle(all(a), rng);
        
        int LIM = 5001;
        vector<ll> cur(LIM, INFLL), nxt(LIM);
        cur[LIM / 2] = 0;
        
        Rep(i, n) {
            fill(all(nxt), INFLL);
            Rep(j, LIM) {
                if (cur[j] == INFLL) continue;
                For(l, -k, k) {
                    if (0 <= j + l && j + l < LIM) mnmz(nxt[j + l], cur[j] + a[i][l + k]);
                }
            }
            cur = nxt;
        }
        cout << cur[LIM / 2];
    }
};
////////////////////////////////////////
int main() {
    // freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////////
    cin >> n >> k;
    
    a.resize(n, vector<ll>(k * 2 + 1));
    Rep(i, n) {
        Rep(j, k * 2 + 1) {
            cin >> a[i][j];
        }
    }
    
    sub2();
    ////////////////////
    return 0;
}