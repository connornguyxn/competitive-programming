#include <bits/stdc++.h>
#define TASK "II"
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
const ll MOD = 20215201314;
const ull BASE = 311;
const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
const int dx[8] = {0, -1, 0, 1, -1, -1, 1, 1};
const int dy[8] = {-1, 0, 1, 0, -1, 1, 1, -1};
// template <class... T>
// void print(T&&... n) {
//     using exp = int[];
//     exp{0, (cout << n << sp, 0)...};
//     cout << endl;
// }
template <class T>
bool mxmz(T &a, T b) { return a < b ? a = b, 1 : 0; }
template <class T>
bool mnmz(T &a, T b) { return b < a ? a = b, 1 : 0; }
void add(ll &a, ll b) { a = (a + b) % MOD; }
void sub(ll &a, ll b) { a = (a + MOD - b) % MOD; }
void mul(ll &a, ll b) { a = a * (b % MOD) % MOD; }

int n, k;
ll s;
vector<ll> a;
////////////////////////////////////////
struct sub1 {
    int ans = 0;
    vector<int> b;
    
    void gen(int id) {
        if (id == n) {
            int cnt = 0;
            Rep(i, n) {
                For(j, i, n - 1) {
                    if (a[j] == b[j]) continue;
                    if (a[j] < b[j]) {
                        cnt += n - j;
                    }
                    break;
                }
            }
            // print(b);
            // print(cnt);
            ans += cnt == k;
        } else {
            For(i, 1, s) {
                b[id] = i;
                gen(id + 1);
            }
        }
    }
    
    sub1() {
        b.resize(n);
        gen(0);
        cout << ans;
    }
};
////////////////////////////////////////
struct full {
    vector<vector<vector<ll>>> dp;
    
    ll solve(int id, int ck, int eql) {
        // print(id, ck, eql);
        if (ck < 0) return 0;
        if (id == n) return ck == 0;
        
        ll& res = dp[id][ck][eql];
        if (res != -1) return res;
        res = 0;
        
        add(res, solve(id + 1, ck, 0) * (a[id] - 1));
        add(res, solve(id + 1, ck, eql + 1));
        if (eql) add(res, solve(id + 1, ck - (n - id) * eql, 0) * (s - a[id]));
        
        return res;
    }
    
    full() {
        dp.assign(n, vector<vector<ll>>(k + 1, vector<ll>(n + 1, -1)));
        cout << solve(0, k, 0);
    }
};
////////////////////////////////////////
struct sub4 {
    sub4() {
        ll ans = 1;
        Rep(i, n) {
            mul(ans, a[i]);
        }
        cout << ans;
    }
};
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////////
    cin >> n >> k >> s;
    
    a.resize(n);
    Rep(i, n) cin >> a[i];
    
    // sub1();
    // full();
    
    if (s <= 4) {
        sub1();
    } else if (k == 0) {
        sub4();
    } else {
        full();
    }
    ////////////////////
    return 0;
}