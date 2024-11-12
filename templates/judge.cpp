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
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9 + 7;
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



////////////////////////////////////////////////////////////////////////////////
mt19937 rng(time(nullptr));
template <class T>
T rand(T l, T r) {
    return uniform_int_distribution<T>(l, r)(rng);
}
////////////////////////////////////////
template <class... C>
void readf(ifstream& cin, C&&... a) {
    using e = int[];
    e{(cin >> a, 0)...};
}
#define readout(...) readf(out, __VA_ARGS__)
#define readans(...) readf(ans, __VA_ARGS__)
////////////////////////////////////////////////////////////////////////////////
#define TASK "<task>"
////////////////////////////////////////
void gen() {
    ofstream cout(TASK".inp"); // dirty, but easier to write
    
    
    
}
////////////////////////////////////////
void check() {
    system(TASK"_.exe"); // bruteforce code
    system("move " TASK".out " TASK".ans");
    system(TASK".exe");
    //! ifstream out(TASK".out");
    //! ifstream ans(TASK".ans");
    
    assert(system("fc.exe " TASK".out " TASK".ans") == 0);
}
////////////////////////////////////////////////////////////////////////////////
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    atexit(logtime);
    ////////////////////////////////////////
    int tc = 1000;
    FOR(t, 1, tc) {
        print("////////////////////////////////////////");
        gen();
        print("Test generated");
        check();
    }
    ////////////////////////////////////////
}