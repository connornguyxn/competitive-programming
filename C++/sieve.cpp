#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #pragma GCC optimize("O3,unroll-loops")
    #include <bits/stdc++.h>
    #define TASK "sieve"
#endif
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define str string
#define nl '\n'
#define sp ' '
#define all(var) (var).begin(), (var).end()
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define Repd(i, n) for (int i = (n); i--; )
#define For(i, l, r) for (int i = (l), _r = (r); i < _r; i++)
#define Ford(i, r, l) for (int i = (r), _l = (l); --i >= _l; )
#define Fore(i, l, r) for (int i = (l), _r = (r); i <= _r; i++)
#define Forde(i, r, l) for (int i = (r) + 1, _l = (l); --i >= _l; )
#define Forin(it, var) for (auto it : var)
#define Bmask(i) (1ULL << (i))
#define Bget(mask, i) ((mask >> (i)) & 1)
#define Blog(n) (63 - __builtin_clzll(n))
template <class T = int>
T inp() { T x; cin >> x; return x; }
template <typename... T>
void print(T&&... n) {
    using exp = int[];
    exp{0, (cout << n << sp, 0)...};
    cout << nl;
}
template <class T>
void mxmz(T &a, T b) { a = max(a, b); }
template <class T>
void mnmz(T &a, T b) { a = min(a, b); }
const int N = 1e6;
const ll MOD = 1e9 + 7;
const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
const int dx[8] = {0, -1, 0, 1, -1, -1, 1, 1};
const int dy[8] = {-1, 0, 1, 0, -1, 1, 1, -1};

// sieve
// <tags>

struct Sieve {
    int n;
    vector<int> spf;
    Sieve(int _n) : n(_n), spf(n, 2) {
        for (int i = 3; i < n; i += 2) {
            if (spf[i] > 2) continue;
            spf[i] = i;
            for (int j = i * i; j < n; j += i * 2) {
                if (spf[j] == 2) spf[j] = i;
            }
        }
    }
};
////////////////////////////////////////
int main() {
    // freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////
    vector<bool> isprime(N + 1, true);
    for (int i = 2; i * i <= N; i++) {
        if (isprime[i]) {
            for (int j = i * i; j <= N; j += i) isprime[j] = false;
        }
    }
    
    Sieve sieve(N + 1);
    // Fore(i, 3, N) {
    //     int spf = [&]() {
    //         Fore(j, 2, i) {
    //             if (isprime[j] && i % j == 0) return j;
    //         }
    //         return 0;
    //     }();
    //     print(i, spf, sieve.spf[i]);
    //     cout << flush;
    //     assert(spf == sieve.spf[i]);
    // }
    cout << "ok";
    ////////////////
    return 0;
}