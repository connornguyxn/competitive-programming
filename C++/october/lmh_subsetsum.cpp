#if DEBUG
    #include "lib/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "subsetsum"
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

// lmh_subsetsum
// dp

int n, m;
vector<int> a;
////////////////////////////////////////7
struct sub1 {
    sub1() {
        vector<int> dp(m + 1, INF);
        dp[0] = 0;
        
        For(x, 1, m) {
            For(i, 1, n) {
                if (a[i] <= x && dp[x - a[i]] < i) {
                    dp[x] = i;
                    break;
                };
            }
        }
        
        if (dp[m] < INF) {
            cout << "YES" << nl;
            deque<int> ans;
            while (m > 0) {
                ans.push_front(dp[m]);
                m -= a[dp[m]];
            }
            Forin(it, ans) cout << it << sp;
        } else {
            cout << "NO";
        }
    }
};
////////////////////////////////////////
struct sub2 {
    sub2() {
        vector<int> cnt(N);
        vector<vector<int>> pos(N);
        
        For(i, 1, n) {
            cnt[a[i]]++;
            pos[a[i]].push_back(i);
        }
        
        vector<int> b(1);
        b.reserve(N);
        
        For(i, 1, m) {
            if (cnt[i] > 2) {
                int carry = (cnt[i] - 1) / 2;
                cnt[i * 2] += carry;
                cnt[i] -= carry * 2;
            }
            Rep(_, cnt[i]) b.push_back(i);
        }
        // print(b);
        
        vector<int> dp(m + 1, INF);
        dp[0] = 0;
        
        For(x, 1, m) {
            Fors(i, 1, b.size()) {
                if (b[i] <= x && dp[x - b[i]] < i) {
                    dp[x] = i;
                    break;
                };
            }
        }
        
        if (dp[m] < INF) {
            cout << "YES" << nl;
            deque<int> ans;
            while (m) {
                m -= b[dp[m]];
                
                int cnt = 1, cur = b[dp[m]];
                while (cnt) {
                    while (pos[cur].size() && cnt) {
                        ans.push_front(pos[cur].back());
                        pos[cur].pop_back();
                    }
                    cnt *= 2;
                    cur /= 2;
                }
            }
            Forin(it, ans) cout << it << sp;
        } else {
            cout << "NO";
        }
        
    }
};
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////////
    cin >> n >> m;
    
    a.resize(n + 1);
    For(i, 1, n) cin >> a[i];
    
    // sub1();
    sub2();
    ////////////////////
    return 0;
}