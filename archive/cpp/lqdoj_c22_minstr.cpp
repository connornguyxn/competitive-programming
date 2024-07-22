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
// const ll MOD = 1e9 + 7;
const int INF = 1e9 + 9;
const ll INFLL = 1e18 + 9;
template <class Ch, class Tr, class C>
basic_ostream<Ch, Tr>& operator<<(basic_ostream<Ch, Tr>& cout, const C& a) {
    cout << "{ ";
    FORIN(it, a) cout << it << sp;
    return cout << "}";
}
template <class... T>
void print(T&&... n) {
    using exp = int[];
    exp{0, (cout << n << sp, 0)...};
    cout << endl;
}


// https://lqdoj.edu.vn/problem/lqdoj2022r2minstr
// string, hashing

const ll MOD1 = 1e9 + 7, MOD2 = 1e9 + 9, BASE = 311;
const int N = 1e6;
vector<ll> bp1(N + 1), bp2(N + 1);
////////////////////////////////////////
struct Hash {
    vector<ll> h1, h2;
    void init(str s) {
        int n = s.size();
        s = sp + s;
        h1.resize(s.size());
        h2.resize(s.size());
        FOR(i, 1, n) {
            h1[i] = (h1[i - 1] * BASE + s[i]) % MOD1;
            h2[i] = (h2[i - 1] * BASE + s[i]) % MOD2;
        }
    }
    
    ll get(int l, int r) {
        l++; r++;
        ll v1 = (h1[r] - h1[l - 1] * bp1[r - l + 1] + MOD1 * MOD1) % MOD1;
        ll v2 = (h2[r] - h2[l - 1] * bp2[r - l + 1] + MOD2 * MOD2) % MOD2;
        return v1 << 32 | v2;
    }
};
////////////////////////////////////////
int main() {
    #define TASK "test"
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    cin.tie(nullptr)->sync_with_stdio(false);
    ////////////////////
    int n, m;
    cin >> n >> m;
    
    str a;
    cin >> a;
    
    bp1[0] = bp2[0] = 1;
    FOR(i, 1, N) {
        bp1[i] = bp1[i - 1] * BASE % MOD1;
        bp2[i] = bp2[i - 1] * BASE % MOD2;
    }
    
    vector<str> b(m);
    FORIN(it, b) cin >> it;
    
    a = sp + a + a;
    
    vector<Hash> hb(m);
    REP(i, m) {
        hb[i].init(b[i]);
    }
    Hash ha;
    ha.init(a);
    
    auto check = [&](int x) {
        vector<ll> v;
        REP(i, m) {
            REP(j, b[i].size() - x + 1) {
                v.push_back(hb[i].get(j, j + x - 1));
            }
        }
        sort(v.begin(), v.end());
        
        vector<int> mk(a.size() + 1);
        FOR(i, 1, n * 2 - x + 1) {
            ll cur = ha.get(i, i + x - 1);
            if (binary_search(v.begin(), v.end(), cur)) {
                mk[max(1, i - n + x)]++;
                mk[min(n, i) + 1]--;
            }
        }
        
        FOR(i, 1, n) {
            mk[i] += mk[i - 1];
            if (mk[i] == 0) return false;
        }
        
        return true;
    };
    
    int lo = 1, hi = n + 1;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    cout << hi - 1;
    ////////////////////
    return 0;
}