#if DEBUG
    #include "lib/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "test"
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
const int MOD = 1e4 + 7;
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
void add(int &a, int b) { a = (a + b) % MOD; }
void sub(int &a, int b) { a = (a + MOD - b) % MOD; }
void mul(int &a, int b) { a = a * (b % MOD) % MOD; }
using namespace chrono;
struct Timer : high_resolution_clock {
    const time_point start_time;
    Timer() : start_time(now()) {}
    rep elapsed() const {
        return duration_cast<milliseconds>(now() - start_time).count();
    }
    void log() {
        cout << "Time elapsed: " << elapsed() << "ms" << endl;
    }
} timer;

// https://oj.vnoi.info/contest/chvpt_dtqg23_t2/ranking/
// dp, math

int n;
int dp[500][9][8][7][5][3][2];
////////////////////////////////////////
int solve(int idx, int mod9, int mod8, int mod7, int ck2485, int ck39, bool ck7) {
    if (idx == n) {
        if (ck2485 == 4) return 0;
        if (ck2485 < 4 && mod8 % bmask(ck2485)) return 0;
        if (mod9 % (int)pow(3, ck39)) return 0;
        if (ck7 && mod7) return 0;
        return 1;
    }
    
    int& res = dp[idx][mod9][mod8][mod7][ck2485][ck39][ck7];
    if (res != -1) return res;
    res = 0;
    
    For(i, 1, 9) {
        int nck2485;
        if (ck2485 == 0) {
            if (i == 5) {
                nck2485 = 5;
            } else {
                nck2485 = i % 2 ? 0 : (i == 6 ? 1 : __lg(i));
            }
        } else {
            if (ck2485 < 4) {
                nck2485 = max(ck2485, i % 2 ? 0 : (i == 6 ? 1 : __lg(i)));
            } else {
                nck2485 = 4 + (i == 5);
            }
        }
        
        add(res, solve(
            idx + 1,
            (mod9 + i) % 9,
            (mod8 * 10 + i) % 8,
            (mod7 * 10 + i) % 7,
            nck2485,
            max(ck39, (i % 3 ? 0 : (i == 9 ? 2 : 1))),
            ck7 || i == 7
        ));
    }
    
    return res;
}
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////////
    cin >> n;
    memset(dp, -1, sizeof(dp));
    
    cout << solve(0, 0, 0, 0, 0, 0, 0) << nl;
    timer.log();
    ////////////////////
    return 0;
}