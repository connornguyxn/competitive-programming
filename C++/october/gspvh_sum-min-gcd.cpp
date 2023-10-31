#if DEBUG
    #include "lib/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "sum-min-gcd"
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
bool mxmz(T &a, T b) { return a < b ? a = b, 1 : 0; }
template <class T>
bool mnmz(T &a, T b) { return b < a ? a = b, 1 : 0; }
void add(ll &a, ll b) { a = (a + b) % MOD; }
void sub(ll &a, ll b) { a = (a + MOD - b) % MOD; }
void mul(ll &a, ll b) { a = a * (b % MOD) % MOD; }

// gspvh_sum-min-gcd
// <tags>

int n;
vector<ll> a;
////////////////////////////////////////
template <typename data_t>
struct smin {
    data_t operator()(data_t a, data_t b) {
        return min(a, b);
    }
};
template <typename data_t, typename cmp>
struct sparse_table {
    int n, k;
    vector<vector<data_t>> st;
    cmp comp;
    
    sparse_table(const vector<data_t> &a) {
        n = a.size();
        k = b_log2(n);
        
        st.resize(k + 1, vector<data_t>(n));
        st[0] = a;
        
        
        for (int i = 1; i <= k; i++){
            for (int j = 0; j + b_mask(i) - 1 < n; j++) {
                st[i][j] = comp(st[i - 1][j], st[i - 1][j + b_mask(i - 1)]);
            }
        }
    }
    
    data_t get(int l, int r) {
        int i = b_log2(r - l + 1);
        return comp(st[i][l], st[i][r - b_mask(i) + 1]);
    }
};
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////////
    int tn;
    cin >> tn;
    
    cin >> n;
    a.resize(n);
    Rep(i, n) cin >> a[i];
    
    
    
    ////////////////////
    return 0;
}