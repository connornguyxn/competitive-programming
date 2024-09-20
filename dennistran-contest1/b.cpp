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
template <class T, class... T2>
void mnmz(T& a, T2&&... b) {
    a = min({a, b...});
}
template <class T, class... T2>
void mxmz(T& a, T2&&... b) {
    a = max({a, b...});
}
void add(ll& a, ll b) { a = (a + b) % MOD; }
void sub(ll& a, ll b) { a = (a + MOD * MOD - b) % MOD; }
void mul(ll& a, ll b) { a = a * (b % MOD) % MOD; }
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

// b
// <tags>

int n;
vector<int> a;
////////////////////////////////////////////////////////////////////////////////
namespace sub2 {
    struct Node {
        int vl, vr, mx = -1;
    };
    vector2<Node> dp;
    
    Node solve(int l, int r) {
        if (r == l + 1){
            if (a[l] == a[r]) return {a[l + 1], a[l + 1], a[l + 1]};
            return {a[l], a[r], max(a[l], a[r])};
        }
        if (l == r) return {a[l], a[l], a[l]};
        
        Node& res = dp[l][r];
        if (res.mx != -1) return res;
        
        FOR(i, l, r - 1) {
            Node lseg = solve(l, i);
            Node rseg = solve(i + 1, r);
            
        }
    }
    
    void main() {
        dp.assign(n + 1, vector<int>(n + 1));
        cout << solve(1, n);
    }
}
////////////////////////////////////////////////////////////////////////////////
int main() {
    #define TASK "test"
    // #define TASK "b"
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    ////////////////////////////////////////
    cin >> n;
    
    resize(n + 1, a);
    FOR(i, 1, n) cin >> a[i];
    
    ////////////////////////////////////////
}