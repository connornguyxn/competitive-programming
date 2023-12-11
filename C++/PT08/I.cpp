#include <bits/stdc++.h>
#define TASK "I"
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
// template <class... T>
// void print(T&&... n) {
//     using exp = int[];
//     exp{0, (cout << n << sp, 0)...};
//     cout << endl;
// }
template <class T>
bool mxmz(T &a, T b) { return a < b ? a = b, 1 : 0; }
template <class T>
bool mnmz(T &a, T b) { return b < a ? a = b, 1 : 0; }
void add(ll &a, ll b) { a = (a + b) % MOD; }
void sub(ll &a, ll b) { a = (a + MOD - b) % MOD; }
void mul(ll &a, ll b) { a = a * (b % MOD) % MOD; }

////////////////////////////////////////
int count(int maxc, multiset<int> st) {
    int res = 0, pre = INF, curc = maxc;
    
    while (st.size()) {
        if (maxc < *st.begin()) return INF;
        
        auto cur = st.upper_bound(min(curc, pre));
        if (cur != st.begin()) {
            cur--;
            curc -= *cur;
            pre = *cur;
            st.erase(cur);
        } else {
            res++;
            pre = INF;
            curc = maxc;
        }
    }
    res += curc < maxc;
    
    return res;
}
////////////////////////////////////////
void solve() {
    int n, k;
    cin >> n >> k;
    
    multiset<int> a;
    Rep(i, n) {
        int x;
        cin >> x;
        a.insert(x);
    }
    
    int l = 1, r = INF;
    while (l < r) {
        int m = (l + r) / 2;
        
        if (count(m, a) <= k) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    
    cout << l << nl;
}
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////////
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    ////////////////////
    return 0;
}