#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using str = string;
using pii = pair<int, int>;
#define fi first
#define se second
#define sp ' '
#define nl '\n'
#define FOR(i, l, r) for (int i = (l), _n = (r); i <= _n; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FORIN(it, a) for (auto& it : a)
template <class c, class t, class con>
basic_ostream<c, t>& operator<<(basic_ostream<c, t>& cout, const con& a) {
    cout << "{ ";
    FORIN(it, a) cout << it << sp;
    return cout << "}";
}
template <class... t>
void print(t&&... a) {
    using e = int[];
    e{(cout << a << sp, 0)...};
    cout << endl;
}

const int N = 1e6;
const ll MOD = 998244353;
vector<ll> fact(N + 1), finv(N + 1);
///////////////////////////////////////
ll bpow(ll n, ll k) {
    n %= MOD;
    ll res = 1;
    
    while (k) {
        if (k % 2) res = res * n % MOD;
        n = n * n % MOD;
        k /= 2;
    }
    
    return res;
}
///////////////////////////////////////
ll nck(int n, int k) {
    return fact[n] * finv[k] % MOD * finv[n - k] % MOD;
}
///////////////////////////////////////
int main() {
    #define task "1312d"
//    freopen(task".inp", "r", stdin);
//    freopen(task".out", "w", stdout);
    ///////////////////////////////////////
    int n, m;
    cin >> n >> m;
    
    if (n == 2) {
        cout << 0;
        return 0;
    }
    
    fact[0] = 1;
    FOR(i, 1, N) fact[i] = fact[i - 1] * (ll)i % MOD;
    finv[N] = bpow(fact[N], MOD - 2);
    for (ll i = N - 1; i >= 0; i--) {
        finv[i] = finv[i + 1] * (i + 1) % MOD;
    }
    
    cout << nck(m, n - 1) * (ll)(n - 2) % MOD * bpow(2, n - 3) % MOD;
    ///////////////////////////////////////
}
