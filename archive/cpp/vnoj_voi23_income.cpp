#if DEBUG
    #include "lib/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "income"
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
#define Ford(i, r, l) for (int i = (r), _l = (l); i >= _l; i--)
#define Forin(it, var) for (auto& it : var)
#define bmask(i) (1ULL << (i))
#define bget(mask, i) ((mask >> (i)) & 1)
const int N = 1e6;
const ll MOD = 1e9 + 7;
const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
// right, down, left, up, lower right, lower left, upper left, upper right
const int dv[] = {0, 1, 0, -1, 1, 1, -1, -1};
const int dh[] = {1, 0, -1, 0, 1, -1, -1, 1};
using namespace chrono;
struct Timer : high_resolution_clock {
    const time_point start_time;
    Timer() : start_time(now()) {}
    rep elapsed() const {
        return duration_cast<milliseconds>(now() - start_time).count();
    }
} timer;
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
void add(ll &a, ll b) { a = (a + b) % MOD; }
void sub(ll &a, ll b) { a = (a + MOD - b) % MOD; }
void mul(ll &a, ll b) { a = a * (b % MOD) % MOD; }
template <typename T, int D>
struct vec : vector<vec<T, D - 1>> {
    template <typename... Args>
    vec(int n = 0, Args... args) : vector<vec<T, D - 1>>(n, vec<T, D - 1>(args...)) {}
};
template <typename T>
struct vec<T, 1> : vector<T> {
    vec(int n = 0, const T& val = T()) : vector<T>(n, val) {}
};

// https://oj.vnoi.info/problem/voi23_income

int n;
vector<int> a;
vector<pii> qs;
////////////////////////////////////////
struct sub2 {
    struct SparseTable {
        int n, k;
        vector<vector<int>> st;
        
        SparseTable(const vector<int>& a) {
            n = a.size();
            k = __lg(n);
            st.resize(k + 1, vector<int>(n));
            
            Rep(i, n) st[0][i] = a[i];
            
            For(i, 1, k) {
                for (int j = 0; j + bmask(i) <= n; j++) {
                    st[i][j] = max(st[i - 1][j], st[i - 1][j + bmask(i - 1)]);
                }
            }
        }
        
        int get(int l, int r) {
            int i = __lg(r - l + 1);
            return max(st[i][l], st[i][r - bmask(i) + 1]);
        }
    };
    
    void main() {
        int ans = 1;
        while (true) {
            SparseTable st(a);
            bool ck = false;
            For(i, 1, n) {
                ck |= mxmz(a[i], st.get(qs[i].fi, qs[i].se));
            }
            if (!ck) break;
            ans++;
        }
        cout << ans;
    }
};
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////////
    cin >> n;
    a.resize(n + 1);
    For(i, 1, n) cin >> a[i];
    qs.resize(n + 1);
    For(i, 1, n) cin >> qs[i].fi >> qs[i].se;
    
    sub2().main();
    ////////////////////
    return 0;
}