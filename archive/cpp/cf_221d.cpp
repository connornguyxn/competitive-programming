#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using str = string;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template <class T>
using vector2 = vector<vector<T>>;
template <class T>
using vector3 = vector<vector2<T>>;
#define sp ' '
#define nl '\n'
#define fi first
#define se second
#define size(a) ((int)(a).size())
#define all(a) begin(a), end(a)
#define tvl (tv * 2)
#define tvr (tv * 2 + 1)
#define FOR(i, l, r) for (int i = (l), _r = (r); i <= _r; i++)
#define FORD(i, r, l) for (int i = (r), _l = (l); i >= _l; i--)
#define FORIN(it, a) for (auto& it : a)
#define bmask(i) (1LL << (i))
#define bget(i, n) ((n) >> (i) & 1)
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9 + 7;
void addm(ll& a, ll b) { a = (a + b % MOD) % MOD; }
void subm(ll& a, ll b) { a = (a + MOD - b % MOD) % MOD; }
void mulm(ll& a, ll b) { a = a * (b % MOD) % MOD; }
template <class T, class... C>
void minimize(T& a, C&&... v) {
    a = min<T>({a, v...});
}
template <class T, class... C>
void maximize(T& a, C&&... v) {
    a = max<T>({a, v...});
}
template <class T, class... C>
void assign(int n, const T& v, C&&... a) {
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


// cf_221d
// <tags>



int n, q;
vector<int> a;
vector<pii> qs;
///////////////////////////////////////////////////////////////////////////////
namespace sub1 {
    ////////////////////////////////////////
    ////////////////////////////////////////
    void main() {
        int bs = ceil(sqrt(n));
        
        vector<array<int, 3>> qsidx(q);
        FOR(i, 0, q - 1) qsidx[i] = {qs[i].fi, qs[i].se, i};
        
        sort(all(qsidx), [&](const auto& x, const auto& y) {
            if (x[0] / bs != y[0] / bs) return x[0] / bs < y[0] / bs;
            return x[1] < y[1];
        });
        
        
        vector<int> zip = a;
        sort(all(zip));
        zip.erase(unique(all(zip)), zip.end());
        unordered_map<int, int> idx;
        FOR(i, 0, size(zip) - 1) idx[zip[i]] = i;
        
        int res = 0, l = 1, r = 0;
        vector<int> ans(q), cnt(n + 1);
        
        auto addp = [&](int p) {
            cnt[idx[a[p]]]++;
            if (cnt[idx[a[p]]] == a[p]) {
                res++;
            } else if (cnt[idx[a[p]]] == a[p] + 1) {
                res--;
            }
        };
        
        auto subp = [&](int p) {
            cnt[idx[a[p]]]--;
            if (cnt[idx[a[p]]] == a[p]) {
                res++;
            } else if (cnt[idx[a[p]]] == a[p] - 1) {
                res--;
            }
        };
        
        FORIN(cq, qsidx) {
            while (r < cq[1]) {
                r++;
                addp(r);
            }
            while (l > cq[0]) {
                l--;
                addp(l);
            }
            while (r > cq[1]) {
                subp(r);
                r--;
            }
            while (l < cq[0]) {
                subp(l);
                l++;
            }
            ans[cq[2]] = res;
        }
        
        FORIN(it, ans) cout << it << nl;
    }
    bool run() {
        return main(), 1;
    }
}
////////////////////////////////////////////////////////////////////////////////
int main() {
    #define TASK "cf_221d"
    freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    atexit(logtime);
    ////////////////////////////////////////
    cin >> n >> q;
    
    resize(n + 1, a);
    FOR(i, 1, n) cin >> a[i];
    
    resize(q, qs);
    FORIN(it, qs) cin >> it.fi >> it.se;
    
    if (sub1::run()) return 0;
    ////////////////////////////////////////
    return 0;
}