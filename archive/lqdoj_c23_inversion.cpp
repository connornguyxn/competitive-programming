#if DEBUG
    #include "lib/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "inversion"
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
bool mxmz(T &a, T b) { return a < b ? a = b, 1 : 0; }
template <class T>
bool mnmz(T &a, T b) { return b < a ? a = b, 1 : 0; }
void add(ll &a, ll b) { a = (a + b) % MOD; }
void sub(ll &a, ll b) { a = (a + MOD - b) % MOD; }
void mul(ll &a, ll b) { a = a * (b % MOD) % MOD; }

// https://lqdoj.edu.vn/problem/lqdoj2023r7inversion
// <tags>

struct query {
    int l, r, id;
};
int n, q;
str s;
vector<query> qs;
////////////////////////////////////////
struct sub3 {
    sub3() {
        int blk = sqrt(n);
        sort(all(qs), [blk](query a, query b) {
            if (a.l / blk != b.l / blk) return a.l < b.l;
            return a.r < b.r;
        });
        
        vector<int> ans(q);
        int l = 0, r = -1, cur = 0;
        vector<int> cnt(26);
        
        Forin(qi, qs) {
            while (l > qi.l) {
                l--;
                Rep(i, s[l] - 'a') cur += cnt[i];
                cnt[s[l] - 'a']++;
            }
            while (r < qi.r) {
                r++;
                Fors(i, s[r] - 'a' + 1, 26) cur += cnt[i];
                cnt[s[r] - 'a']++;
            }
            while (l < qi.l) {
                Rep(i, s[l] - 'a') cur -= cnt[i];
                cnt[s[l] - 'a']--;
                l++;
            }
            while (r > qi.r) {
                cnt[s[r] - 'a']--;
                Fors(i, s[r] - 'a' + 1, 26) cur -= cnt[i];
                r--;
            }
            ans[qi.id] = cur;
        }
        
        Forin(x, ans) cout << x << nl;
    }
};
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////////
    cin >> n >> s >> q;
    
    qs.resize(q);
    Rep(i, q) {
        cin >> qs[i].l >> qs[i].r;
        qs[i].l--; qs[i].r--;
        qs[i].id = i;
    }
    
    sub3();
    ///////////////
    return 0;
}