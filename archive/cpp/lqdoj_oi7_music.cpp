#if DEBUG
    #include "lib/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "music"
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
#define Ford(i, r, l) for (int i = (r), _l = (l); i >= _l; i--)
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

// https://lqdoj.edu.vn/problem/lqdojcontest7bai2
// <tags>

int n, k;
vector<int> a;
////////////////////////////////////////
////////////////////////////////////////
struct sub1 {
    vector<int> state;
    unordered_set<ll> states;
    
    bool addstate() {
        ll chash = 0, base = 1;
        Rep(i, n) {
            add(chash, base * state[i]);
            mul(base, n);
        }
        if (states.count(chash)) return false;
        states.insert(chash);
        return true;
    }
    
    void solve() {
        Rep(i, n - 1) {
            if (a[state[i]] + a[state[i + 1]] > k) continue;
            swap(state[i], state[i + 1]);
            if (addstate()) solve();
            swap(state[i], state[i + 1]);
        }
    }
    
    void main() {
        unordered_map<int, int> pos;
        state.resize(n);
        Rep(i, n) {
            if (!pos.count(a[i])) pos[a[i]] = i;
            state[i] = pos[a[i]];
        };
        
        addstate();
        solve();
        
        cout << states.size();
    }
};
////////////////////////////////////////
struct sub2 {
    void main() {
        
    }
};
////////////////////////////////////////
struct sub3 {
    void main() {
        
    }
};
////////////////////////////////////////
struct sub4 {
    void main() {
        
    }
};
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////////
    int T;
    cin >> T;
    
    cin >> n >> k;
    a.resize(n);
    Forin(it, a) cin >> it;
    
    // if (T == 1) return sub1().main(), 0;
    // if (T == 2) return sub2().main(), 0;
    // if (T == 3) return sub3().main(), 0;
    sub1().main();
    ////////////////////
    return 0;
}