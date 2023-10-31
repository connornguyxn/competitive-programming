#if DEBUG
    #include "lib/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "flowers"
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
ll MOD = 1e9 + 7;
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
bool mxmz(T &a, T& b) { return (a < b ? a = b, 1 : 0); }
template <class T>
bool mnmz(T &a, T& b) { return (b < a ? a = b, 1 : 0); }
void add(ll &a, ll b) { a = (a + b) % MOD; }
void sub(ll &a, ll b) { a = (a + MOD - b) % MOD; }
void mul(ll &a, ll b) { a = a * (b % MOD) % MOD; }

// https://gspvh23.contest.codeforces.com/group/FIWwc7nF6c/contest/479930/problem/C
// math, combinatorics

int t, n, m, k;
////////////////////////////////////////
ll modpow(ll n, int k) {
    ll res = 1;
    while (k) {
        if (k & 1) mul(res, n);
        mul(n, n);
        k >>= 1;
    }
    return res;
}
////////////////////////////////////////
struct sub3 {
    vector<ll> fact, finv;
    
    ll nCr(int n, int r) {
        n %= MOD;
        if (n <= N) return fact[n] * finv[r] % MOD * finv[n - r] % MOD;
        ll res = finv[r];
        Rep(i, r) mul(res, n - i);
        return res;
    }
    sub3() {
        fact.resize(N + 1);
        finv = fact;
        fact[0] = 1;
        For(i, 1, N) fact[i] = fact[i - 1] * i % MOD;
        finv[N] = modpow(fact[N], MOD - 2);
        Ford(i, N, 1) finv[i - 1] = finv[i] * i % MOD;
        
        Rep(_, t) {
            cin >> n >> m >> k;
            cout << nCr(n - 1, k) * m % MOD * modpow(m - 1, k) % MOD << nl;
        }
    }
};
struct sub4 {
    int spf[N + 1], cnt[N + 1];
    
    ll nCr(int n, int r) {
        memset(cnt, 0, sizeof(cnt));
        For(i, 1, n) {
            int tmp = i;
            while (tmp > 1) {
                cnt[spf[tmp]]++;
                tmp /= spf[tmp];
            }
        }
        For(i, 1, r) {
            int tmp = i;
            while (tmp > 1) {
                cnt[spf[tmp]]--;
                tmp /= spf[tmp];
            }
        }
        For(i, 1, n - r) {
            int tmp = i;
            while (tmp > 1) {
                cnt[spf[tmp]]--;
                tmp /= spf[tmp];
            }
        } 
        
        ll ans = 1;
        For(i, 1, n) if (cnt[i]) {
            mul(ans, modpow(i, cnt[i]));
        }
        return ans;
    }
    
    sub4() {
        For(i, 1, N) spf[i] = 2;
        for (int i = 3; i * i <= N; i += 2) {
            if (spf[i] > 2) continue;
            spf[i] = i;
            for (ll j = i; i * j <= N; j += 2) {
                if (spf[i] == 2) spf[i * j] = i;
            }
        }
        
        Rep(_, t) {
            cin >> n >> m >> k;
            // cout << nCr(n - 1, k) * m % MOD * modpow(m - 1, k) % MOD << nl;
            cout << nCr(n - 1, k) << nl;
        }
    }
};
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////////
    // (n - 1)Ck * m * (m - 1)^k
    cin >> t >> MOD;
    
    // sub3();
    // sub4();
    
    if (MOD == 998244353) {
        sub3();
    } else {
        sub4();
    }
    ////////////////////
    return 0;
}