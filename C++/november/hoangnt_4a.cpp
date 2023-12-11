#if DEBUG
    #include "lib/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "4a"
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

// https://tbhnptlcqntn2023.contest.codeforces.com/group/ZosfxzdjkV/contest/485820/problem/A
// datastruct, implementation

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
        k = __lg(n);
        
        st.resize(k + 1, vector<data_t>(n));
        st[0] = a;
        
        
        for (int i = 1; i <= k; i++){
            for (int j = 0; j + bmask(i) - 1 < n; j++) {
                st[i][j] = comp(st[i - 1][j], st[i - 1][j + bmask(i - 1)]);
            }
        }
    }
    
    data_t get(int l, int r) {
        int i = __lg(r - l + 1);
        return comp(st[i][l], st[i][r - bmask(i) + 1]);
    }
};
////////////////////////////////////////
////////////////////////////////////////
int main() {
    // freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////////
    int n;
    cin >> n;
    
    str s;
    cin >> s;
    s = sp + s;
    
    vector<int> pre(n + 2), suf(n + 2);
    For(i, 2, n) {
        pre[i] = pre[i - 1] + (s[i - 1] == 'L');
    }
    Ford(i, n - 1, 1) {
        suf[i] = suf[i + 1] + (s[i + 1] == 'R');
    }
    // print(pre);
    // print(suf);
    
    vector<int> cst(n + 1);
    For(i, 1, n) {
        cst[i] = pre[i] + suf[i];
    }
    // print(cst);
    
    sparse_table<int, smin<int>> st(cst);
    
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        if (l > r) swap(l, r);
        // print(st.get(l, r), pre[l], suf[r]);
        cout << st.get(l, r) - pre[l] - suf[r] << nl;
    }
    ////////////////////
    return 0;
}