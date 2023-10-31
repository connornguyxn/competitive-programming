#if DEBUG
    #include "lib/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "fwall"
#endif
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
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define Repd(i, n) for (int i = (n); i--; )
#define For(i, l, r) for (int i = (l), _r = (r); i <= _r; i++)
#define Fors(i, l, r) for (int i = (l), _r = (r); i < _r; i++)
#define Ford(i, r, l) for (int i = (r) + 1, _l = (l); --i >= _l; )
#define Forin(it, var) for (auto& it : var)
#define bmask(i) (1ULL << (i))
#define bget(mask, i) ((mask >> (i)) & 1)
#define blog2(n) (63 - __builtin_clzll(n))
const int N = 1e6;
const ll MOD = 1e9 + 7;
const ull BASE = 311;
const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
const int dx[8] = {0, -1, 0, 1, -1, -1, 1, 1};
const int dy[8] = {-1, 0, 1, 0, -1, 1, 1, -1};
template <class... T>
void print(T&&... n) {
    using exp = int[];
    exp{0, (cout << n << sp, 0)...};
    cout << endl;
}
template <class T>
bool mxmz(T &a, T b) { if (b > a) return a = b, 1; }
template <class T>
bool mnmz(T &a, T b) { if (b < a) return a = b, 1; }
void add(ll &a, ll b) { a = (a + b) % MOD; }
void sub(ll &a, ll b) { a = (a + MOD - b) % MOD; }
void mul(ll &a, ll b) { a = a * (b % MOD) % MOD; }

// nalgae_fwall
// trie, basic

struct Trie {
    struct node {
        vector<unique_ptr<node>> child;
        int cnt = 0, end = 0;
        node() : child(26) {}
    };
    unique_ptr<node> root = make_unique<node>();
    
    void insert(const str& s) {
        auto cur = root.get();
        Forin(c, s) {
            int id = c - 'a';
            if (!cur->child[id]) cur->child[id] = make_unique<node>();
            cur = cur->child[id].get();
            cur->cnt++;
        }
        cur->end++;
    }
    
    int match(const str& s) {
        auto cur = root.get();
        int res = 0;
        Forin(c, s) {
            int id = c - 'a';
            if (!cur->child[id]) break;
            res++;
            cur = cur->child[id].get();
        }
        return res;
    }
} trie;
////////////////////////////////////////
////////////////////////////////////////
int main() {
    // freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////////
    int n;
    cin >> n;
    
    vector<str> a;
    Rep(_, n) {
        char c;
        str s;
        cin >> c >> s;
        
        if (c == '-') {
            a.push_back(s);
        } else {
            trie.insert(s);
        }
    }
    
    set<str> ans;
    Forin(it, a) {
        int p = trie.match(it);
        if (p == it.size()) {
            cout << -1;
            return 0;
        }
        ans.insert(it.substr(0, p + 1));
    }
    
    cout << ans.size() << nl;
    Forin(it, ans) cout << it << nl;
    ////////////////////
    return 0;
}