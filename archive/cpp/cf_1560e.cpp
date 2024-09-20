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
// template <class... T>
// void print(T&&... a) {
//     cout << "[debug] ";
//     using e = int[];
//     e{(cout << a << sp, 0)...};
//     cout << endl;
// }
// template <class Ch, class Tr, class C>
// basic_ostream<Ch, Tr>& operator<<(basic_ostream<Ch, Tr>& cout, C& a) {
//     cout << "{ ";
//     FORIN(it, a) cout << it << sp;
//     return cout << "}";
// }
// template <class T1, class T2>
// ostream& operator<<(ostream& cout, pair<T1, T2>& a) {
//     return cout << '(' << a.fi << sp << a.se << ')';
// }


// https://codeforces.com/problemset/problem/1560/E
// strings

////////////////////////////////////////////////////////////////////////////////
void solve() {
    str s;
    cin >> s;
    
    str ord;
    unordered_map<char, int> cnt;
    FORD(i, s.size() - 1, 0) {
        if (!cnt.count(s[i])) {
            ord.push_back(s[i]);
        }
        cnt[s[i]]++;
    }
    
    reverse(all(ord));
    FOR(i, 0, ord.size() - 1) {
        if (cnt[ord[i]] % (i + 1)) {
            cout << -1 << nl;
            return;
        }
        cnt[ord[i]] /= i + 1;
    }
    
    int len = 0;
    FORIN(it, cnt) len += it.se;
    
    auto tmp = cnt;
    FOR(i, 0, len - 1) {
        tmp[s[i]]--;
        if (tmp[s[i]] < 0) {
            cout << -1 << nl;
            return;
        }
    }
    FORIN(it, tmp) if (it.se) {
        cout << -1 << nl;
        return;
    }
    
    str cur = s.substr(0, len);
    int i = len;
    FORIN(c, ord) {
        str tmp;
        FORIN(it, cur) if (it != c) tmp += it;
        cur = move(tmp);
        
        int j = 0;
        while (j < (int)cur.size()) {
            if (s[i] != cur[j]) {
                cout << -1 << nl;
                return;
            }
            i++;
            j++;
        }
    }
    
    cout << s.substr(0, len) << sp << ord << nl;
}
////////////////////////////////////////////////////////////////////////////////
int main() {
    #define TASK "test"
    // #define TASK "1560e"
    // freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    ////////////////////////////////////////
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    ////////////////////////////////////////
}