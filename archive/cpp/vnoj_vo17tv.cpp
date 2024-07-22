#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "vo17tv"
#endif
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define str string
#define nl '\n'
#define sp ' '
#define all(var) (var).begin(), (var).end()
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define Repd(i, n) for (int i = (n); i--; )
#define For(i, l, r) for (int i = (l), _r = (r); i < _r; i++)
#define Ford(i, r, l) for (int i = (r), _l = (l); --i >= _l; )
#define Fore(i, l, r) for (int i = (l), _r = (r); i <= _r; i++)
#define Forde(i, r, l) for (int i = (r) + 1, _l = (l); --i >= _l; )
#define Forin(it, var) for (auto it : var)
#define Bmask(i) (1ULL << (i))
#define Bget(mask, i) ((mask >> (i)) & 1)
#define Blog(n) (63 - __builtin_clzll(n))
template <class T = int>
T inp() { T x; cin >> x; return x; }
template <class... T>
void print(T&&... n) {
    using exp = int[];
    exp{0, (cout << n << sp, 0)...};
    cout << nl;
}
template <class T>
void mxmz(T &a, T b) { a = max(a, b); }
template <class T>
void mnmz(T &a, T b) { a = min(a, b); }
const int N = 1e6;
const ull MOD = 1e9 + 7;
const ull BASE = 257;
const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
const int dx[8] = {0, -1, 0, 1, -1, -1, 1, 1};
const int dy[8] = {-1, 0, 1, 0, -1, 1, 1, -1};

// https://oj.vnoi.info/problem/vo17tv
// string, binsearch

////////////////////////////////////////
int main() {
    // freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////
    vector<ull> POW(N + 1);
    POW[0] = 1;
    Fore(i, 1, N) POW[i] = POW[i - 1] * BASE;
    
    int n, k;
    cin >> n >> k;
    
    vector<vector<ull>> a(n);
    Rep(i, n) {
        str tmp;
        cin >> tmp;
        
        a[i].push_back(0);
        a[i].reserve(tmp.size() + 1);
        
        Forin(c, tmp) {
            a[i].push_back(a[i].back() * BASE + (ull)c);
        }
    }
    
    auto geth = [&POW](const vector<ull>& h, int l, int r) {
        return h[r] - h[l - 1] * POW[r - l + 1];
    };
    
    int cl = 0, cr = N;
    while (cl < cr) {
        int cm = (cl + cr) / 2;
        if ([&](int len) {
            unordered_map<ull, int> cnt;
            
            Forin(cur, a) {
                unordered_set<ull> mk;
                mk.reserve(cur.size() - len);
                
                Fore(i, 1, cur.size() - len) {
                    mk.insert(geth(cur, i, i + len - 1));
                }
                
                Forin(it, mk) {
                    cnt[it]++;
                    if (cnt[it] == k) return true;
                }
            }
            
            return false;
        }(cm)) {
            cl = cm + 1;
        } else {
            cr = cm;
        }
    }
    
    cout << cl - 1;
    ////////////////
    return 0;
}