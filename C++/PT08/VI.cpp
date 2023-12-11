#include <bits/stdc++.h>
#define TASK "VI"
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

struct Query {
    bool q;
    int k, c = 0;
};
int n, q, f;
vector<int> a;
////////////////////////////////////////
struct sub2 {
    sub2() {
        vector<int> ans(n + 1);
        
        auto build = [&]() {
            fill(all(ans), 0);
            ans[f] = 1;
            int l = f - 1, r = f + 1;
            For(i, 2, n) {
                if (a[l] < a[r]) {
                    ans[l] = i;
                    l--;
                } else {
                    ans[r] = i;
                    r++;
                }
            }
        };
        
        bool upd = true;
        Rep(_, q) {
            char c;
            int k;
            cin >> c >> k;
            
            if (c == 'U') {
                int x;
                cin >> x;
                
                int o = a[k];
                For(i, 1, n) {
                    if (a[i] < o && a[i] >= x) a[i]++;
                }
                a[k] = x;
                upd = true;
            } else {
                if (upd) build();
                upd = false;
                cout << ans[k] << nl;
            }
        }
    }
};
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////////
    int O;
    cin >> O;
    
    cin >> n >> q >> f;
    a.resize(n + 2);
    For(i, 1, n) cin >> a[i];
    a[0] = a[n + 1] = INF;
    
    sub2();
    
    // if (O <= 2) {
    //     sub2();
    // }
    ////////////////////
    return 0;
}