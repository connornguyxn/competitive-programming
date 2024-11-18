#include "../template.cpp"


const int N = 1e6;
array<ll, N + 1> fact, ifact;
////////////////////////////////////////////////////////////////////////////////
ll binpow(ll n, ll k) {
    n %= MOD;
    ll res = 1;
    while (k) {
        if (k % 2) mulm(res, n);
        mulm(n, n);
        k /= 2;
    }
    return res;
}
////////////////////
ll C(int n, int r) {
    return fact[n] * ifact[r] % MOD * ifact[n - r] % MOD;
}
////////////////////////////////////////////////////////////////////////////////
void prep() {
    fact[0] = 1;
    FOR(i, 1, N) fact[i] = fact[i - 1] * i % MOD;
    ifact[N] = binpow(fact[N], MOD - 2);
    FORD(i, N - 1, 0) ifact[i] = ifact[i + 1] * (i + 1) % MOD;
    
}