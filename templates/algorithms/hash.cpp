#include "../template.cpp"

const int N = 1e6;
ll bp[N + 1];
const ll BASE = 311;
////////////////////////////////////////////////////////////////////////////////
struct Hash {
    vector<ll> h;
    void init(str s) {
        s = sp + s;
        h.resize(size(s));
        FOR(i, 1, size(s) - 1) {
            h[i] = h[i - 1] * BASE + s[i];
        }
    }
    ////////////////////////////////////////
    ll get(int l, int r) {
        l++; r++;
        return h[r] - h[l - 1] * bp[r - l + 1];
    }
    ////////////////////////////////////////
    friend ll join(ll a, ll b, int lb, int rb) {
        return a * bp[rb - lb + 1] + b;
    }
};
////////////////////////////////////////////////////////////////////////////////
void prep() {
    bp[0] = 1;
    FOR(i, 1, N) {
        bp[i] = bp[i - 1] * BASE;
    }
}