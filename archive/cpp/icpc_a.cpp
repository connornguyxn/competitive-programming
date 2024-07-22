#if DEBUG
    #include "lib/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "a"
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

// icpc_a
// <tags>

int ans;
vector<ll> fib(88);
// vector<ll> cur;
////////////////////////////////////////
void count(int id, ll n) {
    // print(id, n);
    if (n == 1) {
        ans++;
        // print(cur);
        return;
    }
    if (id < 3) return;
    
    // print("pre", id, fib[id]);
    int p = upper_bound(all(fib), n) - fib.begin() - 1;
    id = min(id, p);
    // print("new", id, fib[id]);
    
    Ford(i, id, 3) {
        if (n % fib[i] == 0) {
            // cur.push_back(fib[i]);
            count(i, n / fib[i]);
            // cur.pop_back();
        }
    }
}
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////////
    fib[1] = fib[2] = 1;
    For(i, 3, 87) fib[i] = fib[i - 1] + fib[i - 2];
    // print(fib);
    
    int q;
    cin >> q;
    For(i, 1, q) {
        ll n;
        cin >> n;
        // n = i;
        ans = 0;
        // cur.clear();
        count(87, n);
        cout << ans << nl;
    }
    ////////////////////
    return 0;
}