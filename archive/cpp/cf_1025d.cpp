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

// https://codeforces.com/problemset/problem/1025/D
// dp

int n;
vector<int> a;
////////////////////////////////////////////////////////////////////////////////
namespace subf {
    bool checksub() {
        return true;
    }
    const int N = 700;
    bitset<N * N * 2> dp, mk;
    vector3<int> adj;
    ////////////////////////////////////////
    int getidx(int x, int y, int z) {
        x--; y--;
        return (z * N * N) + y * N + x;
    }
    ////////////////////////////////////////
    bool solve(int l, int r, bool ck) {
        if (r == l) return true;
        
        int idx = getidx(l, r, ck);
        if (mk[idx]) return dp[idx];
        mk[idx] = 1;
        
        FORIN(mid, adj[ck][ck ? r : l]) {
            dp[idx] = solve(l + !ck, mid, true) && solve(mid, r - ck, false);
            if (dp[idx]) break;
        }
        
        return dp[idx];
    }
    ////////////////////////////////////////
    void main() {
        sort(1 + all(a));
        
        adj.resize(2, vector2<int>(n + 1));
        FOR(mid, 1, n) {
            FOR(i, 1, n) {
                if (mid != i && __gcd(a[mid], a[i]) > 1) {
                    adj[i < mid][mid].push_back(i);
                }
            }
        }
        
        FOR(i, 1, n) {
            if (solve(1, i, true) && solve(i, n, false)) {
                cout << "Yes";
                return;
            }
        }
        cout << "No";
    }
}
////////////////////////////////////////////////////////////////////////////////
int main() {
    #define TASK "test"
    // #define TASK "cf_1025d"
    // freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    ////////////////////////////////////////
    cin >> n;
    
    resize(n + 1, a);
    FOR(i, 1, n) cin >> a[i];
    
    
    if (subf::checksub()) return subf::main(), 0;
    ////////////////////////////////////////
}