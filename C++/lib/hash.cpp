struct Hash {
    int n;
    vector<ll> a, p;
    ll base, mod;
    
    Hash(const str& s, ll _mod = MOD, ll _base = BASE) : n(s.size()), a(n + 1), p(n + 1) {
        base = _base;
        mod = _mod;
        
        p[0] = 1;
        Fore(i, 1, n) {
            p[i] = p[i - 1] * base % mod;
            a[i] = (a[i - 1] * base + (ll)s[i - 1]) % mod;
        }
    }
    
    ll get(int l, int r) {
        return (a[r] - a[l - 1] * p[r - l + 1] + mod * mod) % mod;
    }
};