#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using str = string;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template <class T>
using vector2 = vector<vector<T>>;
template <class T>
using vector3 = vector<vector2<T>>;
#define fi first
#define se second
#define nl '\n'
#define sp ' '
#define all(a) (a).begin(), (a).end()
#define tvl (tv * 2)
#define tvr (tv * 2 + 1)
#define FOR(i, l, r) for (ll i = (l), _r = (r); i <= _r; i++)
#define FORD(i, r, l) for (ll i = (r), _l = (l); i >= _l; i--)
#define FORIN(it, a) for (auto& it : a)
#define bmask(i) (1LL << (i))
#define bget(i, n) ((n) >> (i) & 1LL)
const ll MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
void addmod(ll& a, ll b) { a = (a + b % MOD) % MOD; }
void submod(ll& a, ll b) { a = (a + MOD - b % MOD) % MOD; }
void mulmod(ll& a, ll b) { a = a * (b % MOD) % MOD; }
template <class T, class... C>
void assign(int n, T v, C&&... a) {
    using e = int[];
    e{(a.assign(n, v), 0)...};
}
template <class... C>
void resize(int n, C&&... a) {
    using e = int[];
    e{(a.resize(n), 0)...};
}
////////////////////////////////////////
template <class... T>
void print(T&&... a) {
    cout << flush;
    clog << "\n[debug] ";
    using e = int[];
    e{(clog << a << sp, 0)...};
    clog << endl;
}
template <class Ch, class Tr, class C>
basic_ostream<Ch, Tr>& operator<<(basic_ostream<Ch, Tr>& cout, C a) {
    cout << "{ ";
    FORIN(it, a) cout << it << sp;
    return cout << "}";
}
template <class T1, class T2>
ostream& operator<<(ostream& cout, pair<T1, T2> a) {
    return cout << '(' << a.fi << sp << a.se << ')';
}
void logtime() {
    print("[time]", clock() * 1.0 / CLOCKS_PER_SEC);
}


// https://oj.vnoi.info/problem/chvpt_xor
// dp, bitwise

int n;
ll A, B;
vector<ll> a;
////////////////////////////////////////////////////////////////////////////////
namespace sub1 {
    ll cnt[2][41];
    ll dp[41][2][2];
    ////////////////////////////////////////
    ll solve(int idx, bool lower, bool higher) {
        if (idx < 0) return 0;
        
        ll& res = dp[idx][lower][higher];
        if (~res) return res;
        res = INFLL;
        
        int lo = (higher ? 0 : bget(idx, A));
        int hi = (lower ? 1 : bget(idx, B));
        
        if (lo == 0) {
            res = min(res, solve(idx - 1, lower || hi == 1, higher) + bmask(idx) * cnt[1][idx]);
        }
        if (hi == 1) {
            res = min(res, solve(idx - 1, lower, higher || lo == 0) + bmask(idx) * cnt[0][idx]);
        }
        
        return res;
    }
    ////////////////////////////////////////
    void main() {
        FOR(idx, 0, 40) {
            FOR(i, 1, n) {
                cnt[bget(idx, a[i])][idx]++;
            }
        }
        
        memset(dp, -1, sizeof(dp));
        cout << solve(40, false, false);
    }
    void run() {
        main();
        exit(0);
    }
}
////////////////////////////////////////////////////////////////////////////////
int main() {
    #define TASK "vnoj_chvpt_xor"
    freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    atexit(logtime);
    ////////////////////////////////////////
    cin >> n >> A >> B;
    
    resize(n + 1, a);
    FOR(i, 1, n) {
        cin >> a[i];
    }
    
    sub1::run();
    ////////////////////////////////////////
    return 0;
}