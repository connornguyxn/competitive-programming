#if DEBUG
    #include "lib/debug.h"
    #include "lib/testlib/testlib.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #include "testlib.h"
    #define TASK "checker"
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
const ull BASE = 311;
const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
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

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
    
    int n = inf.readInt();
    vector<int> a(n + 1), p(n + 1);
    For(i, 1, n) a[i] = inf.readInt();
    For(i, 1, n) p[inf.readInt()] = i;
    
    int res = ouf.readInt();
    if (res != ans.readInt()) quitf(_wa, "Wrong answer");
    
    set<int> s;
    Rep(i, res) s.insert(ouf.readInt());
    
    if (*s.begin() < 1 || *s.rbegin() > n) quitf(_wa, "Wrong answer");
    if (s.size() != res) quitf(_wa, "Wrong answer");
    
    int mx = 0;
    For(i, 1, n) {
        if (!s.count(a[i])) continue;
        if (p[a[i]] < mx) quitf(_wa, "Wrong answer");
        mx = p[a[i]];
    }
    
    quitf(_ok, "Correct");
    ////////////////////////////////////////
    return 0;
}