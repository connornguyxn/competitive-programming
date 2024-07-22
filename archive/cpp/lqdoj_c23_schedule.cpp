#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "schedule"
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
#define Ford(i, r, l) for (int i = (r) + 1, _l = (l); --i >= _l; )
#define Forin(it, var) for (auto it : var)
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

// lqdoj_c23_schedule
// <tags>

int n, m;
vector<ll> k;
vector<int> s, t;
////////////////////////////////////////
struct sub3 {
    sub3() {
        vector<int> a(n + 2);
        
        For(i, 1, m) {
            a[s[i]] += k[i];
            a[t[i] + 1] -= k[i];
        }
        
        For(i, 1, n) a[i] += a[i - 1];
        a.pop_back();
        
        cout << *max_element(all(a)) << nl;
    }
};
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////
    cin >> m >> n;
    
    k.resize(m + 1);
    s.resize(m + 1);
    t.resize(m + 1);
    
    For(i, 1, m) {
        cin >> k[i] >> s[i] >> t[i];
    }
    
    if ([&]() {
        For(i, 1, m) if (s[i] != t[i]) return false;
        return true;
    }()) {
        cout << *max_element(all(k)) << nl;
    } else if ([&]() {
        For(i, 1, m) if (k[i] > 1) return false;
        return true;
    }()) {
        cout << *max_element(all(k)) << nl;
    }
    ////////////////
    return 0;
}