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
#define len(a) ((int)((a).size()))
#define tvl (tv * 2)
#define tvr (tv * 2 + 1)
#define FOR(i, l, r) for (ll i = (l), _r = (r); i <= _r; i++)
#define FORD(i, r, l) for (ll i = (r), _l = (l); i >= _l; i--)
#define FORIN(it, a) for (auto& it : a)
#define bmask(i) (1 << (i))
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


// https://oj.vnoi.info/problem/chvpt_dtqg_dong_tien_gia
// implementation

////////////////////////////////////////////////////////////////////////////////
namespace sub1 {
    ////////////////////////////////////////
    ////////////////////////////////////////
    void main() {
        
        int n, k;
        cin >> n >> k;
        
        unordered_map<int, int> cnt;
        unordered_set<int> invalid;
        int cmpcnt = 0;
        
        FOR(i, 1, k) {
            int c;
            cin >> c;
            vector<int> l(c), r(c);
            FORIN(it, l) cin >> it;
            FORIN(it, r) cin >> it;
            int t;
            cin >> t;
            
            if (t == 0) {
                FORIN(it, l) invalid.insert(it);
                FORIN(it, r) invalid.insert(it);
            }
            if (t == 1) {
                FORIN(it, r) cnt[it]++;
                cmpcnt++;
            }
            if (t == 2) {
                FORIN(it, l) cnt[it]++;
                cmpcnt++;
            }
        }
        
        if (len(invalid) + 1 == n) {
            FOR(i, 1, n) {
                if (!invalid.count(i)) {
                    cout << i;
                    return;
                }
            }
        }
        
        FORIN(it, invalid) cnt.erase(it);
        
        int ans = 0;
        FORIN(it, cnt) {
            if (it.se == cmpcnt) {
                if (ans == 0) {
                    ans = it.fi;
                } else {
                    cout << 0;
                    return;
                }
            }
        }
        cout << ans;
        
    }
    void run() {
        main();
        exit(0);
    }
}
////////////////////////////////////////////////////////////////////////////////
int main() {
    #define TASK "vnoj_chvpt_dtqg_dong_tien_gia"
    freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    atexit(logtime);
    ////////////////////////////////////////
    
    
    sub1::run();
    ////////////////////////////////////////
    return 0;
}