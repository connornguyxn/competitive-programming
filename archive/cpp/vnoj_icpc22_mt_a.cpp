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


// https://oj.vnoi.info/problem/icpc22_mt_a
// dp

int n, k;
str a;
////////////////////////////////////////////////////////////////////////////////
namespace subf {
    int dp[301][301][301][2];
    ////////////////////////////////////////
    int solve(int l, int r, int cnt0, int cnt1, bool turn) {
        if (cnt0 == k) return 0;
        if (cnt1 == k) return 1;
        
        int& res = dp[l][r][cnt0][turn];
        if (res != -1) return res;
        res = 0;
        
        if (turn == 0) {
            res |= solve(l + 1, r, cnt0 + (a[l] == 'B'), cnt1, !turn);
            res |= solve(l, r - 1, cnt0 + (a[r] == 'B'), cnt1, !turn);
        } else {
            res |= !solve(l + 1, r, cnt0, cnt1 + (a[l] == 'B'), !turn);
            res |= !solve(l, r - 1, cnt0, cnt1 + (a[r] == 'B'), !turn);
        }
        res ^= turn;
        
        return res;
    }
    ////////////////////////////////////////
    void main() {
        a = sp + a;
        memset(dp, -1, sizeof(dp));
        cout << (solve(1, n, 0, 0, 0) ? "YES" : "NO");
    }
}
////////////////////////////////////////////////////////////////////////////////
int main() {
    #define TASK "vnoj_icpc22_mt_a"
    freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    atexit(logtime);
    ////////////////////////////////////////
    cin >> n >> k;
    cin >> a;
    
    return subf::main(), 0;
    ////////////////////////////////////////
}