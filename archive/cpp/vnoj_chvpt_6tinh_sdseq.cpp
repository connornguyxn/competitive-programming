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
#define bget(i, n) ((n) >> (i) & 1)
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


// https://imgur.com/a/2FUDlMO
// segtree, digit dp

int n, s, q;
vector<array<ll, 3>> qs;
////////////////////////////////////////////////////////////////////////////////
namespace sub1 {
    int m;
    ll pow10[10];
    ////////////////////////////////////////
    ll get_digit(int i, ll n) {
        return n / pow10[i] % 10;
    }
    ////////////////////////////////////////
    bool valid(ll n) {
        if (n % s == 0) return 1;
        while (n) {
            if (n % 10 == s) return 1;
            n /= 10;
        }
        return 0;
    }
    ////////////////////////////////////////
    vector3<pll> dp; // {sum, count}
    ////////////////////////////////////////
    pll get_sum_valid(const ll& n, int idx = 9, bool low = 0, ll mod = 0, bool included = 0) {
        if (idx < 0) return {0, (mod == 0 || included)};
        
        pll& mem = dp[idx][mod][included];
        if (low && mem.fi != -1) return mem;
        pll res = {0, 0};
        
        int d = get_digit(idx, n);
        FOR(i, 0, (low ? 9 : d)) {
            pll nxt = get_sum_valid(n, idx - 1, low || i < d, (mod * 10 + i) % s, included || i == s);
            res.fi += nxt.fi;
            res.se += nxt.se;
            res.fi += pow10[idx] * i * nxt.se;
        }
        
        return low ? mem = res : res;
    }
    ////////////////////////////////////////
    struct Segtree {
        vector<ll> st;
        Segtree() {
            st.assign(m * 4, 0);
        }
        ////////////////////////////////////////
        void update(int p, ll v, int tl = 0, int tr = m - 1, int tv = 1) {
            if (tl == tr) {
                st[tv] = v;
                return;
            }
            int tm = (tl + tr) / 2;
            if (p <= tm) update(p, v, tl, tm, tvl);
            else update(p, v, tm + 1, tr, tvr);
            st[tv] = st[tvl] + st[tvr];
        }
        ////////////////////////////////////////
        ll get(int l, int r, int tl = 0, int tr = m - 1, int tv = 1) {
            if (tr < l || r < tl) return 0;
            if (l <= tl && tr <= r) return st[tv];
            int tm = (tl + tr) / 2;
            return get(l, r, tl, tm, tvl) + get(l, r, tm + 1, tr, tvr);
        }
    };
    ////////////////////////////////////////
    void main() {
        vector<int> zip;
        FORIN(it, qs) {
            zip.push_back(it[1]);
            if (it[0] == 2) zip.push_back(it[2]);
        }
        sort(all(zip));
        zip.erase(unique(all(zip)), zip.end());
        unordered_map<int, int> pos;
        m = zip.size();
        FOR(i, 0, m - 1) {
            pos[zip[i]] = i;
        }
        
        pow10[0] = 1;
        FOR(i, 1, 9) pow10[i] = pow10[i - 1] * 10;
        
        dp.assign(10, vector2<pll>(10, vector<pll>(2, {-1, -1})));
        Segtree delta;
        
        FORIN(cq, qs) {
            if (cq[0] == 1) {
                ll p = cq[1], c = cq[2];
                delta.update(pos[p], (c - p) * (1 + valid(p)));
            } else {
                ll l = cq[1], r = cq[2];
                ll res = (l + r) * (r - l + 1) / 2;
                res += get_sum_valid(r).fi - get_sum_valid(l - 1).fi;
                res += delta.get(pos[l], pos[r]);
                cout << res << nl;
            }
        }
    }
    void run() {
        main();
        exit(0);
    }
}
////////////////////////////////////////////////////////////////////////////////
int main() {
    #define TASK "sdseq"
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    atexit(logtime);
    ////////////////////////////////////////
    cin >> n >> s >> q;
    
    resize(q, qs);
    FORIN(it, qs) {
        cin >> it[0] >> it[1] >> it[2];
    }
    
    sub1::run();
    ////////////////////////////////////////
    return 0;
}