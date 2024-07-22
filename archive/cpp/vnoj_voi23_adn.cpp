#if DEBUG
    #include "lib/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "adn"
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

// https://oj.vnoi.info/problem/voi23_adn
// greedy, dp

////////////////////////////////////////
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////////
    str s;
    cin >> s;
    
    int n = s.size();
    s = '.' + s;
    if (n == 1) return !(cout << 0);
    
    int l = 1, r = 1;
    while (s[r] == '?') r++;
    while (l < r) s[l++] = s[r];
    r++;
    
    for (; r <= n; r++) {
        if (s[r] == '?') continue;
        if (s[l] == s[r]) {
            while (l < r) s[l++] = s[r];
        } else {
            l = r;
        }
    }
    while (s[--r] == '?') s[r] = s[l];
    // print(s);
    
    vector<pair<char, ll>> a{{'.', 0}};
    a.reserve(n + 1);
    For(i, 1, n) {
        if (s[i] == a.back().fi) {
            a.back().se++;
        } else {
            a.emplace_back(s[i], a.back().se + 1);
        }
    }
    n = a.size() - 1;
    // print(a);8
    
    vector<ll> dp(n + 1);
    For(i, 1, n) {
        char c = (a[i].fi != '?' ? a[i].fi : a[i - 1].fi);
        for (int j = i; a[j].fi == c || a[j].fi == '?'; j--) {
            // print(j, i);
            ll cnt = a[i].se - a[j - 1].se;
            mxmz(dp[i], dp[j - 1] + cnt * (cnt + 1) / 2);
        }
    }
    // print(dp);
    
    cout << a.back().se * (a.back().se + 1) / 2 - *max_element(all(dp));
    ////////////////////
    return 0;
}