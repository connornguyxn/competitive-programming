#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #pragma GCC optimize("O3,unroll-loops,inline")
    #include <bits/stdc++.h>
    #define TASK "sohoc"
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
#define b_mask(POS) (1ULL << (POS))
#define b_get(MASK, POS) ((MASK >> (POS)) & 1)
#define all(VAR) (VAR).begin(), (VAR).end()
const int N = 1e6 + 100;
const ull MOD = 1e9 + 7;
const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
// directions = left, up, right, down, upper_l, upper_r, lower_r, lower_l
const int dx[8] = {0, -1, 0, 1, -1, -1, 1, 1};
const int dy[8] = {-1, 0, 1, 0, -1, 1, 1, -1};
template<typename tVar, typename tVal>
void mnmz(tVar &var, tVal val) { if (val < var) var = val; }
template<typename tVar, typename tVal>
void mxmz(tVar &var, tVal val) { if (val > var) var = val; }

// sohoc
// <tags>

array<int, N + 1> spf;
////////////////////////////////////////
void init_sieve() {
    for (int i = 2; i * i <= N; i++) {
        for (int j = i * i; j <= N; j += i) {
            spf[j] = i;
        }
    }
}
bool isprime(int n) {
    return n > 1 && spf[n] == 0;
}
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(0);
    ////////////////
    int n;
    cin >> n;
    
    init_sieve();
    
    int a, cnt = 0;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a;
        sum += a * (1 - a % 2) * 1LL;
        
        if (isprime(a)) {
            int tmp = a;
            while (tmp > 0) {
                a += tmp % 10;
                tmp /= 10;
            }
            
            cnt += isprime(a);
        };
    }
    
    cout << sum << nl;
    cout << cnt;
    ////////////////
    return 0;
}
