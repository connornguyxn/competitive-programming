#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using str = string;
using pii = pair<int, int>;
#define fi first
#define se second
#define nl '\n'
#define sp ' '
#define BMASK(i) (1LL << (i))
#define BGET(n, i) (((n) >> (i)) & 1)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define REPD(i, n) for (int i = (n); i--; )
#define FOR(i, l, r) for (int i = (l), _r = (r); i <= _r; i++)
#define FORD(i, r, l) for (int i = (r), _l = (l); i >= _l; i--)
#define FORIN(it, a) for (auto& it : a)
const ll MOD = 1e9 + 7;
const int INF = 1e9 + 9;
const ll INFLL = 1e18 + 9;
template <class... T>
void print(T&&... n) {
    using exp = int[];
    exp{0, (cout << n << sp, 0)...};
    cout << endl;
}

const int N = 1e6;
const ll BASE = 311, MOD1 = 1e9 + 7, MOD2 = 1e9 + 9;
vector<ll> bp1(N + 1), bp2(N + 1);
////////////////////////////////////////
struct Hash {
    vector<ll> h1, h2;
    Hash(const str& s) : h1(s.size()), h2(s.size()) {
        FOR(i, 1, s.size() - 1) {
            h1[i] = h1[i - 1] * BASE + (ll)s[i] % MOD1;
            h2[i] = h2[i - 1] * BASE + (ll)s[i] % MOD2;
        }
    }
    pair<ll, ll> get(int l, int r) {
        ll v1 = (h1[r] - h1[l - 1] * bp1[r - l + 1] + MOD1 * MOD1) % MOD1;
        ll v2 = (h2[r] - h2[l - 1] * bp2[r - l + 1] + MOD2 * MOD2) % MOD2;
        return {v1, v2};
    }
};
////////////////////////////////////////
////////////////////////////////////////
int main() {
    #define TASK "test"
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    cin.tie(nullptr)->sync_with_stdio(false);
    ////////////////////
    bp1[0] = bp2[0] = 1;
    FOR(i, 1, N) {
        bp1[i] = bp1[i - 1] * BASE % MOD1;
        bp2[i] = bp2[i - 1] * BASE % MOD2;
    }
    ////////////////////
    return 0;
}