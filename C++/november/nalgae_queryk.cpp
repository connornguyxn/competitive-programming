#if DEBUG
    #include "lib/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "queryk"
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
const ll MOD = 2e9 + 1;
const ull BASE = 311;
const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
const int dv[] = {0, 1, 0, -1, 1, 1, -1, -1};
const int dh[] = {1, 0, -1, 0, 1, -1, -1, 1};
const ll zero = 1e9;
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
template <int D, typename T>
struct vec : vector<vec<D - 1, T>> {
    template <typename... Args>
    vec(int n = 1, Args... args) : vector<vec<D - 1, T>>(n, vec<D - 1, T>(args...)) {}
};
template <typename T>
struct vec<1, T> : vector<T> {
    vec(int n = 0, const T& val = T()) : vector<T>(n, val) {}
};

// https://sos.contest.codeforces.com/group/I5RsBaI6Kd/contest/488969
// datastruct, implementation, trie

struct Binary_trie {
    unique_ptr<Binary_trie> child[2];
    int size = 0, n = 0;
    
    void init_child() {
        if (!child[0]) child[0] = make_unique<Binary_trie>();
        if (!child[1]) child[1] = make_unique<Binary_trie>();
    }
    
    void insert(ll x, int i = 50) {
        size++;
        
        if (i < 0) {
            n++;
            return;
        }
        int b = bget(x, i);
        
        init_child();
        
        child[b]->insert(x, i - 1);
    }
    
    int count(ll x, int i = 50) {
        if (i < 0) return n;
        int b = bget(x, i);
        
        init_child();
        
        return child[b]->count(x, i - 1);
    }
    
    bool erase(ll x, int cnt, int i = 50) {
        if (i < 0) {
            n -= cnt;
            size -= cnt;
            return true;
        }
        int b = bget(x, i);
        
        if (!child[b]) return false;
        if (child[b]->erase(x, cnt, i - 1)) {
            size -= cnt;
            return true;
        }
        return false;
    }
    
    ll get(int k, int i = 50) {
        if (i < 0) return 0;
        
        init_child();
        
        if (k < child[0]->size) return child[0]->get(k, i - 1);
        return bmask(i) | child[1]->get(k - child[0]->size, i - 1);
    }
    
    int count_smaller_equal(ll x, int i = 50) {
        if (i < 0) return n;
        int b = bget(x, i);
        
        init_child();
        
        if (b) return child[0]->size + child[1]->count_smaller_equal(x, i - 1);
        return child[0]->count_smaller_equal(x, i - 1);
    }
} trie;
////////////////////////////////////////
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////////
    int n;
    cin >> n;
    Rep(i, n) {
        ll x;
        cin >> x;
        trie.insert(x + 1e9);
    }
    
    int q;
    cin >> q;
    
    ll sum = 0;
    
    while (q--) {
        int type;
        ll x;
        cin >> type >> x;
        
        if (type < 4) {
            ll cur = (sum + x) % MOD;
            if (type == 1) trie.insert(cur);
            else if (type == 2) trie.erase(cur, 1);
            else trie.erase(cur, trie.count(cur));
        } else {
            if (type == 4) {
                ll ans = trie.get(x - 1) - zero;
                cout << ans << nl;
                sum += ans;
            } else {
                ll y;
                cin >> y;
                cout << trie.count_smaller_equal(y + zero) - trie.count_smaller_equal(x + zero - 1) << nl;
            }
        }
        // print_trie();
    }
    ////////////////////
    return 0;
}