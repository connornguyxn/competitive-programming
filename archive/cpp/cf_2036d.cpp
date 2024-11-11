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
#define sp ' '
#define nl '\n'
#define fi first
#define se second
#define size(a) ((int)(a).size())
#define all(a) begin(a), end(a)
#define tvl (tv * 2)
#define tvr (tv * 2 + 1)
#define FOR(i, l, r) for (int i = (l), _r = (r); i <= _r; i++)
#define FORD(i, r, l) for (int i = (r), _l = (l); i >= _l; i--)
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
void minimize(T& a, C&&... v) {
    a = min<T>({a, v...});
}
template <class T, class... C>
void maximize(T& a, C&&... v) {
    a = max<T>({a, v...});
}
template <class T, class... C>
void assign(int n, const T& v, C&&... a) {
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


// cf_2036d
// basic, implementation



///////////////////////////////////////////////////////////////////////////////
namespace sub1 {
    ////////////////////////////////////////
    ////////////////////////////////////////
    void main() {
        int n, m;
        cin >> n >> m;
        
        vector2<int> a(n + 1, vector<int>(m + 1));
        FOR(i, 1, n) {
            FOR(j, 1, m) {
                char c;
                cin >> c;
                a[i][j] = c - '0';
            }
        }
        
        int cnt = 0;
        
        FOR(l, 0, min(n, m) / 2 - 1) {
            vector<int> cur;
            
            FOR(i, 1 + l, m - l) {
                cur.push_back(a[l + 1][i]);
            }
            FOR(i, 2 + l, n - l - 1) {
                cur.push_back(a[i][m - l]);
            }
            FORD(i, m - l, 1 + l) {
                cur.push_back(a[n - l][i]);
            }
            FORD(i, n - l - 1, 2 + l) {
                cur.push_back(a[i][l + 1]);
            }
            
            FOR(i, 0, size(cur) - 1) {
                cnt += (cur[i] == 1 && cur[(i + 1) % size(cur)] == 5 && cur[(i + 2) % size(cur)] == 4 && cur[(i + 3) % size(cur)] == 3);
            }
        }
        
        cout << cnt << nl;
    }
    bool run() {
        return main(), 1;
    }
}
////////////////////////////////////////////////////////////////////////////////
int main() {
    #define TASK "cf_2036d"
    // freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    atexit(logtime);
    ////////////////////////////////////////
    int tc;
    cin >> tc;
    
    FOR(ct, 1, tc) {
        sub1::run();
    }
    ////////////////////////////////////////
    return 0;
}