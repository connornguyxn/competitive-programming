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
void addmod(ll& a, ll b) { a = (a + b % MOD) % MOD; }
void submod(ll& a, ll b) { a = (a + MOD - b % MOD) % MOD; }
void mulmod(ll& a, ll b) { a = a * (b % MOD) % MOD; }
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


// https://cses.fi/problemset/task/1188
// segtree

int n;
vector<int> a;
int q;
vector<int> qs;
////////////////////////////////////////////////////////////////////////////////
namespace sub1 {
    ////////////////////////////////////////
    struct Node {
        int best = -1;
        int pre[2], suf[2], size;
        ////////////////////////////////////////
        friend Node operator+(const Node& ln, const Node& rn) {
            Node res;
            
            res.best = max(ln.best, rn.best);
            res.size = ln.size + rn.size;
            
            FOR(i, 0, 1) {
                res.pre[i] = ln.pre[i] + (ln.pre[i] == ln.size ? rn.pre[i] : 0);
                res.suf[i] = rn.suf[i] + (rn.suf[i] == rn.size ? ln.suf[i] : 0);
                res.best = max(res.best, ln.suf[i] + rn.pre[i]);
            }
            
            return res;
        }
        
    };
    ////////////////////////////////////////
    struct Segtree {
        vector<Node> st;
        Segtree() {
            st.assign(n * 4, Node());
        }
        ////////////////////////////////////////
        void update(int p, int v, int tl = 1, int tr = n, int tv = 1) {
            if (tl == tr) {
                st[tv] = Node();
                st[tv].best = 1;
                st[tv].pre[v] = 1;
                st[tv].suf[v] = 1;
                st[tv].size = 1;
                return;
            }
            int tm = (tl + tr) / 2;
            if (p <= tm) update(p, v, tl, tm, tvl);
            else update(p, v, tm + 1, tr, tvr);
            st[tv] = st[tvl] + st[tvr];
        }
    };
    ////////////////////////////////////////
    void main() {
        Segtree st;
        
        FOR(i, 1, n) {
            st.update(i, a[i]);
        }
        
        FORIN(cq, qs) {
            a[cq] ^= 1;
            st.update(cq, a[cq]);
            cout << st.st[1].best << sp;
        }
    }
    void run() {
        main();
        exit(0);
    }
}
////////////////////////////////////////////////////////////////////////////////
int main() {
    #define TASK "cses_1188"
    // freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    atexit(logtime);
    ////////////////////////////////////////
    str s;
    cin >> s;
    
    n = s.size();
    resize(n + 1, a);
    FOR(i, 1, n) {
        a[i] = s[i - 1] - '0';
    }
    
    cin >> q;
    resize(q, qs);
    FORIN(it, qs) cin >> it;
    
    sub1::run();
    ////////////////////////////////////////
    return 0;
}