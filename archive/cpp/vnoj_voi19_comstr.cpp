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

// https://oj.vnoi.info/problem/voi19_comstr
// strings, incomplete

int n, n1, n2, r;
str s, s1, s2;
////////////////////////////////////////////////////////////////////////////////
namespace sub1 {
    void main() {
        vector<str> seq{s2, s1};
        while ((int)seq.back().size() < n) {
            seq.push_back(end(seq)[-1] + end(seq)[-2]);
        }
        // print(seq);
        int ans = 0;
        FOR(i, 0, n - 1) {
            ans += seq.back()[i] != s[i];
        }
        cout << ans;
    }
}
////////////////////////////////////////////////////////////////////////////////
namespace sub2 {
    void main() {
        int ans = INF;
        
        FOR(stat1, 0, bmask(n1)) {
            FOR(stat2, 0, bmask(n2)) {
                vector<bitset<1000>> stat{(unsigned)stat1, (unsigned)stat2};
                vector<int> size{n1, n2};
                
                while (size.back() < r) {
                    stat.push_back(end(stat)[-1] | (end(stat)[-2] << end(size)[-1]));
                    size.push_back(end(size)[-1] + end(size)[-2]);
                }
                
                int res = 0;
                FOR(i, 0, n - 1) {
                    if (s[i] == 'A' && stat.back()[i]) res++;
                }
                
                ans = min(ans, res);
            }
        }
        
        cout << ans;
    }
}
////////////////////////////////////////////////////////////////////////////////
int main() {
    #define TASK "test"
    // #define TASK "comstr"
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    ////////////////////////////////////////
    cin >> n >> n1 >> n2 >> r;
    cin >> s;
    
    s1 = s.substr(0, n2);
    s2 = s.substr(n2, n1);
    
    if (r == 0) return sub1::main(), 0;
    return sub2::main(), 0;
    ////////////////////////////////////////
}