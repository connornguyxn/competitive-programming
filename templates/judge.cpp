#include "bits/stdc++.h"
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
#define lnode (tv * 2)
#define rnode (tv * 2 + 1)
#define FOR(i, l, r) for (int i = (l), _r = (r); i <= _r; i++)
#define FORD(i, r, l) for (int i = (r), _l = (l); i >= _l; i--)
#define FORIN(it, a) for (auto& it : a)
#define bmask(i) (1LL << (i))
#define bget(i, n) ((n) >> (i) & 1)
#define bon(i, n) ((n) | bmask(i))
#define boff(i, n) ((n) & ~bmask(i))
const ll MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
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
    cout << "[debug] ";
    using e = int[];
    e{(cout << a << sp, 0)...};
    cout << endl;
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

mt19937 rng(time(nullptr));
template <class T>
T rand(T l, T r) {
    return uniform_int_distribution<T>(l, r)(rng);
}
float ctime() {
    return clock() * 1.0 / CLOCKS_PER_SEC;
}
////////////////////////////////////////
#define TASK ""
////////////////////////////////////////
void gen(int T) {
    ofstream cout(TASK".inp");
    
    
}
////////////////////////////////////////
bool check() {
    system(TASK".exe");
    system(TASK"_br.exe");
    return system("fc.exe " TASK ".out " TASK ".ans");
    ifstream cin(TASK".inp");
    ifstream cout(TASK".out");
    
    
    return 0;
}
////////////////////////////////////////////////////////////////////////////////
int main() {
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    ////////////////////////////////////////
    int tc = 5;
    FOR(t, 1, tc) {
        gen(t);
        if (check()) return 0;
    }
    print("Correct");
    ////////////////////////////////////////
}