#pragma GCC optimize("O3")
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
void logtime() {
    cout << flush;
    clog << nl << "[time] " << clock() * 1.0 / CLOCKS_PER_SEC << nl;
}


// cf_2014h
// offline, mo's algorithm

////////////////////////////////////////////////////////////////////////////////
namespace subf {
    ////////////////////////////////////////
    void main() {
        int n, q;
        cin >> n >> q;
        vector<int> a(n + 1);
        FOR(i, 1, n) {
            cin >> a[i];
        }
        
        vector<int> zip = a;
        sort(all(zip));
        zip.erase(unique(all(zip)), zip.end());
        FOR(i, 1, n) {
            a[i] = lower_bound(all(zip), a[i]) - zip.begin();
        }
        
        vector<array<int, 3>> qs(q);
        FOR(i, 0, q - 1) {
            cin >> qs[i][0] >> qs[i][1];
            qs[i][2] = i;
        }
        
        int blk = sqrtl(n);
        sort(all(qs), [&](array<int, 3>& a, array<int, 3>& b) {
            if (a[0] / blk != b[0] / blk) return a[0] / blk < b[0] / blk;
            return a[1] < b[1];
        });
        
        int l = 1, r = 0, odd = 0;
        vector<int> cnt(zip.size());
        cnt.reserve(n);
        
        vector<int> ans(q);
        
        FORIN(cq, qs) {
            while (r < cq[1]) {
                r++;
                cnt[a[r]]++;
                if (cnt[a[r]] % 2) {
                    odd++;
                } else {
                    odd--;
                }
            }
            while (l > cq[0]) {
                l--;
                cnt[a[l]]++;
                if (cnt[a[l]] % 2) {
                    odd++;
                } else {
                    odd--;
                }
            }
            while (r > cq[1]) {
                cnt[a[r]]--;
                if (cnt[a[r]] % 2) {
                    odd++;
                } else {
                    odd--;
                }
                r--;
            }
            while (l < cq[0]) {
                cnt[a[l]]--;
                if (cnt[a[l]] % 2) {
                    odd++;
                } else {
                    odd--;
                }
                l++;
            }
            
            ans[cq[2]] = (odd == 0 && (r - l + 1) % 2 == 0);
        }
        
        FORIN(it, ans) {
            cout << (it ? "YES" : "NO") << nl;
        }
    }
}
////////////////////////////////////////////////////////////////////////////////
int main() {
    #define TASK "cf_2014h"
    // freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    atexit(logtime);
    ////////////////////////////////////////
    int tc = 1;
    cin >> tc;
    
    while (tc--) {
        subf::main();
    }
    ////////////////////////////////////////
}