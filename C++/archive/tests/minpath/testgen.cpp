#include "jngen.h"
#include "debug.h"
namespace wd {
    #include <windows.h>
};
#define TASK "minpath"
#undef Polygon
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
#define all(var) (var).begin(), (var).end()
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define Repd(i, n) for (int i = (n); i--; )
#define For(i, l, r) for (int i = (l), _r = (r); i <= _r; i++)
#define Ford(i, r, l) for (int i = (r) + 1, _l = (l); --i >= _l; )
#define Forin(it, var) for (auto it : var)
#define bmask(i) (1ULL << (i))
#define bget(mask, i) ((mask >> (i)) & 1)
#define blog2(n) (63 - __builtin_clzll(n))
const int N = 1e6;
const ll MOD = 1e9 + 7;
const ull BASE = 311;
const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
const int dx[8] = {0, -1, 0, 1, -1, -1, 1, 1};
const int dy[8] = {-1, 0, 1, 0, -1, 1, 1, -1};
template <class... T>
void print(T&&... n) {
    using exp = int[];
    exp{0, (cout << n << sp, 0)...};
    cout << endl;
}
template <class T>
void mxmz(T &a, T b) { a = max(a, b); }
template <class T>
void mnmz(T &a, T b) { a = min(a, b); }
void add(ll &a, ll b) { a = (a + b) % MOD; }
void sub(ll &a, ll b) { a = (a + MOD * MOD - b) % MOD; }
void mul(ll &a, ll b) { a = a % MOD * (b % MOD) % MOD; }

str itos(int n) {
    stringstream ss;
    ss << n;
    return ss.str();
}
//////////////////////////
void gentest(int id, int nmx, int mmx) {
    print("** Generating test", id);
    ofstream fout(TASK".inp");
    
    int n = rnd.next(2, nmx);
    int step = mmx / n;
    // int m = n * step;
    int val = rnd.next(1, INF);
    
    vector<pii> edges;
    
    For(i, 1, n) {
        For(j, 1, step) {
            if (i + j > n) break;
            edges.push_back({i, min(n, i + j)});
        }
    }
    
    fout << n << sp << edges.size() << nl;
    print(n, edges.size(), step, val);
    
    for (pii e : edges) {
        fout << e.fi << sp << e.se << sp << (rnd.next(1, INF) % 11 ? val : 0) << nl;
    }
    
    print("Completed");
}
//////////////////////////
void runjudge() {
    print("Running judge");
    wd::system(TASK".exe");
    print("Completed");
}
//////////////////////////
void movetest(int id) {
    print("Moving test", id);
    wd::system(("mkdir " + itos(id)).c_str());
    wd::system(("move "TASK".inp " + itos(id) + "/"TASK".inp").c_str());
    wd::system(("move "TASK".out " + itos(id) + "/"TASK".out").c_str());
    print("Completed");
}
////////////////////////////////////////
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    ////////////////
    For(i, 1, 20) {
        gentest(i, 1e5, 2e5);
        runjudge();
        movetest(i);
    }
    For(i, 21, 35) {
        gentest(i, 1e4, 2e5);
        runjudge();
        movetest(i);
    }
    For(i, 36, 50) {
        gentest(i, 1e3, 2e5);
        runjudge();
        movetest(i);
    }
    ////////////////
    return 0;
}