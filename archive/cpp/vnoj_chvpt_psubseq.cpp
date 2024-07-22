#if DEBUG
    #include "lib/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "psubseq"
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
#define Ford(i, r, l) for (int i = (r) + 1, _l = (l); --i >= _l; )
#define Forin(it, var) for (auto& it : var)
#define bmask(i) (1ULL << (i))
#define bget(mask, i) ((mask >> (i)) & 1)
const int N = 1e6;
const ll MOD = 1e9 + 7;
const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
// right, down, left, up, lower right, lower left, upper left, upper right
const int dv[] = {0, 1, 0, -1, 1, 1, -1, -1};
const int dh[] = {1, 0, -1, 0, 1, -1, -1, 1};
using namespace chrono;
struct Timer : high_resolution_clock {
    const time_point start_time;
    Timer() : start_time(now()) {}
    rep elapsed() const {
        return duration_cast<milliseconds>(now() - start_time).count();
    }
} timer;
template <class... T>
void print(T&&... n) {
    using exp = int[];
    exp{0, (cout << n << sp, 0)...};
    cout << endl;
}
template <class T>
bool mxmz(T &a, T b) { return a < b ? a = b, 1 : 0; }
template <class T>
bool mnmz(T &a, T b) { return b < a ? a = b, 1 : 0; }
void add(ll &a, ll b) { a = (a + b) % MOD; }
void sub(ll &a, ll b) { a = (a + MOD - b) % MOD; }
void mul(ll &a, ll b) { a = a * (b % MOD) % MOD; }
template <typename T, int D>
struct vec : vector<vec<T, D - 1>> {
    template <typename... Args>
    vec(int n = 0, Args... args) : vector<vec<T, D - 1>>(n, vec<T, D - 1>(args...)) {}
};
template <typename T>
struct vec<T, 1> : vector<T> {
    vec(int n = 0, const T& val = T()) : vector<T>(n, val) {}
};

// https://oj.vnoi.info/contest/chvpt_chieu_6_12_2023
// hashing

using puu = pair<ull, ull>;
namespace std {
    template <>
    struct hash<puu> {
        size_t operator()(const puu& p) const {
            return hash<ull>()(p.fi) ^ hash<ull>()(p.se);
        }
    };
}
////////////////////////////////////////
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////////
    int n, m;
    cin >> n >> m;
    
    vector<int> a(n), b(m), zip;
    Rep(i, n) {
        cin >> a[i];
        zip.push_back(a[i]);
    }
    Rep(i, m) {
        cin >> b[i];
        zip.push_back(b[i]);
    }
    
    sort(all(zip));
    zip.erase(unique(all(zip)), zip.end());
    Forin(it, a) it = lower_bound(all(zip), it) - zip.begin();
    Forin(it, b) it = lower_bound(all(zip), it) - zip.begin();
    ull mx = zip.size();
    
    vector<puu> pw(mx);
    pw[0] = {1, 1};
    For(i, 1, mx - 1) {
        pw[i] = {pw[i - 1].fi * mx % MOD, pw[i - 1].se * mx};
    }
    
    cout << [&]() {
        Ford(len, min(n, m), 1) {
            unordered_set<puu> mk;
            
            puu cur = {0, 0};
            auto add_hash = [&](int val) {
                cur.fi = (cur.fi + pw[val].fi) % MOD;
                cur.se += pw[val].se;
            };
            auto sub_hash = [&](int val) {
                cur.fi = (cur.fi + MOD - pw[val].fi) % MOD;
                cur.se -= pw[val].se;
            };
            
            
            Rep(i, len) add_hash(a[i]);
            mk.insert(cur);
            For(i, len, n - 1) {
                add_hash(a[i]);
                sub_hash(a[i - len]);
                mk.insert(cur);
            }
            
            
            cur = {0, 0};
            
            
            Rep(i, len) add_hash(b[i]);
            if (mk.count(cur)) return len;
            For(i, len, m - 1) {
                add_hash(b[i]);
                sub_hash(b[i - len]);
                if (mk.count(cur)) return len;
            }
        }
        return -1;
    }();
    ////////////////////
    return 0;
}