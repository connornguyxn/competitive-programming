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
template <class T1, class T2>
ostream& operator<<(ostream& cout, pair<T1, T2>& a) {
    return cout << '(' << a.fi << sp << a.se << ')';
}

// https://oj.vnoi.info/problem/voi19_aspal
// dp

str p, q;
ll dp[50000][2][2][1024];
// str num;
////////////////////////////////////////////////////////////////////////////////
ll solve(str& s, int cur, bool low, bool zero, int cnt) {
    if (cur < 0) {
        print(low, zero, bitset<10>(cnt));
        if (zero) return 0;
        if (__builtin_popcount(cnt) <= 1) return 1;
        return 0;
    }
    
    ll& res = dp[cur][low][zero][cnt];
    if (res != -1) return res;
    res = 0;
    // ll res = 0;
    
    
    if (low) {
        if (zero) {
            FOR(i, 1, 9) {
                // num += i + '0';
                res = (res + solve(s, cur - 1, 1, 0, bmask(i))) % MOD;
                // num.pop_back();
            }
            // num += '0';
            res = (res + solve(s, cur - 1, 1, 1, 0)) % MOD;
            // num.pop_back();
        } else {
            FOR(i, 0, 9) {
                // num += i + '0';
                res = (res + solve(s, cur - 1, 1, 0, cnt ^ bmask(i))) % MOD;
                // num.pop_back();
            }
        }
    } else {
        int digit = s[cur] - '0';
        
        // num += digit + '0';
        res = (res + solve(s, cur - 1, 0, 0, cnt ^ bmask(digit))) % MOD;
        // num.pop_back();
        
        FOR(i, 1, digit - 1) {
            // num += i + '0';
            res = (res + solve(s, cur - 1, 1, 0, bmask(i))) % MOD;
            // num.pop_back();
        }
        
        if (digit > 0) {
            if (zero) {
                // num += '0';
                res = (res + solve(s, cur - 1, 1, 1, 0)) % MOD;
                // num.pop_back();
            } else {
                // num += '0';
                res = (res + solve(s, cur - 1, 1, 0, cnt ^ 1)) % MOD;
                // num.pop_back();
            }
        }
    }
    
    return res;
}
////////////////////////////////////////////////////////////////////////////////
int main() {
    #define TASK "test"
    // #define TASK "aspal"
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    ////////////////////////////////////////
    cin >> p >> q;
    
    memset(dp, -1, sizeof(dp));
    reverse(all(p));
    reverse(all(q));
    
    unordered_map<char, int> cnt;
    FORIN(it, p) {
        cnt[it]++;
    }
    bool ok = true, mk = false;
    FORIN(it, cnt) {
        if (it.se % 2) {
            if (mk) {
                ok = false;
                break;
            }
            mk = true;
        }
    }
    
    
    print(solve(q, q.size() - 1, 0, 1, 0));
    // print(solve(p, p.size() - 1, 0, 1, 0));
    // cout << solve(q, q.size() - 1, 0, 1, 0) - solve(p, p.size() - 1, 0, 1, 0) + ok;
    ////////////////////////////////////////
}