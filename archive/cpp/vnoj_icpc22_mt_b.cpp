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


// https://oj.vnoi.info/problem/icpc22_mt_b
// hashing, strings, binsearch

int n, q;
str a;
vector<int> qs;
////////////////////////////////////////////////////////////////////////////////
namespace subf {
    const ull N = 1e6, BASE = 311;
    ////////////////////////////////////////
    ull bp[N + 1];
    ////////////////////////////////////////
    void main() {
        bp[0] = 1;
        FOR(i, 1, N) bp[i] = bp[i - 1] * BASE;
        
        a = sp + a;
        vector<ull> h(n + 1);
        FOR(i, 1, n) {
            h[i] = h[i - 1] * BASE + a[i];
        }
        
        auto get = [&](int l, int r) {
            return h[r] - h[l - 1] * bp[r - l + 1];
        };
        
        vector<int> cnt(n + 2);
        FOR(i, 1, n) {
            int lo = 0, hi = n - i + 1, res = 0;
            while (lo <= hi) {
                int cur = (lo + hi) / 2;
                if (get(i, i + cur - 1) == get(1, cur)) {
                    res = cur;
                    lo = cur + 1;
                } else {
                    hi = cur - 1;
                }
            }
            cnt[1]++;
            cnt[res + 1]--;
        }
        
        partial_sum(all(cnt), cnt.begin());
        // print(cnt);
        
        FORIN(cq, qs) {
            if (cnt[cq] >= 3 && get(1, cq) == get(n - cq + 1, n)) {
                cout << "YES " << cnt[cq] << nl;
            } else {
                cout << "NO" << nl;
            }
        }
    }
}
////////////////////////////////////////////////////////////////////////////////
int main() {
    #define TASK "vnoj_icpc22_mt_b"
    freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    atexit(logtime);
    ////////////////////////////////////////
    cin >> a;
    n = a.size();
    
    cin >> q;
    resize(q, qs);
    FORIN(it, qs) cin >> it;
    
    return subf::main(), 0;
    ////////////////////////////////////////
}