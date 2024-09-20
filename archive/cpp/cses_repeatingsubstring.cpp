#include "bits/stdc++.h"
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
const ull N = 1e6 + 3;
template <class T>
using vector2 = vector<vector<T>>;
template <class T>
using vector3 = vector<vector2<T>>;
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
template <class... T>
void print(T&&... a) {
    cout << "[debug] ";
    using e = int[];
    e{(cout << a << sp, 0)...};
    cout << endl;
}
template <class Ch, class Tr, class C>
basic_ostream<Ch, Tr>& operator<<(basic_ostream<Ch, Tr>& cout, C& a) {
    cout << "{ ";
    FORIN(it, a) cout << it << sp;
    return cout << "}";
}
template <class T1, class T2>
ostream& operator<<(ostream& cout, pair<T1, T2>& a) {
    return cout << '(' << a.fi << sp << a.se << ')';
}

// cses_repeatingsubstring
// binsearch, hashing

int n;
str s;
vector<ull> h, bp;
////////////////////////////////////////////////////////////////////////////////
ull get(int l, int r) {
    return h[r] - h[l - 1] * bp[r - l + 1];
}
////////////////////////////////////////
bool check(int len) {
    unordered_set<ull> mk;
    FOR(i, 1, n - len + 1) {
        ull cur = get(i, i + len - 1);
        if (mk.count(cur)) return true;
        mk.insert(cur);
    }
    return false;
}
////////////////////////////////////////////////////////////////////////////////
int main() {
    #define TASK "test"
    // #define TASK "repeatingsubstring"
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    ////////////////////////////////////////
    cin >> s;
    n = s.size();
    s = sp + s;
    
    resize(n + 1, h, bp);
    
    bp[0] = 1;
    FOR(i, 1, n) bp[i] = bp[i - 1] * N;
    FOR(i, 1, n) h[i] = h[i - 1] * N + s[i];
    
    int lo = 0, hi = n - 1, ans = 0;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    
    if (ans == 0) {
        cout << -1;
        return 0;
    }
    
    unordered_set<ull> mk;
    FOR(i, 1, n - ans + 1) {
        ull cur = get(i, i + ans - 1);
        if (mk.count(cur)) {
            cout << s.substr(i, ans);
            return 0;
        }
        mk.insert(cur);
    }
    ////////////////////////////////////////
}