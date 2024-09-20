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
// template <class... T>
// void print(T&&... a) {
//     cout << "[debug] ";
//     using e = int[];
//     e{(cout << a << sp, 0)...};
//     cout << endl;
// }
// template <class Ch, class Tr, class C>
// basic_ostream<Ch, Tr>& operator<<(basic_ostream<Ch, Tr>& cout, C& a) {
//     cout << "{ ";
//     FORIN(it, a) cout << it << sp;
//     return cout << "}";
// }
// template <class T1, class T2>
// ostream& operator<<(ostream& cout, pair<T1, T2>& a) {
//     return cout << '(' << a.fi << sp << a.se << ')';
// }

// https://codeforces.com/problemset/problem/137/D
// dp, strings

int n, k;
str s;
vector2<int> cost;
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
int main() {
    #define TASK "test"
    // #define TASK "137d"
    // freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    ////////////////////////////////////////
    cin >> s;
    
    n = s.size();
    s = sp + s;
    
    cin >> k;
    
    cost.resize(n + 1, vector<int>(n + 1));
    FOR(i, 1, n) {
        cost[i][i] = 0;
        FOR(j, 1, min(i - 1, n - i)) {
            cost[i - j][i + j] = cost[i - j + 1][i + j - 1] + (s[i - j] != s[i + j]);
        }
        FOR(j, 0, min(i - 1, n - i - 1)) {
            cost[i - j][i + j + 1] = cost[i - j + 1][i + j] + (s[i - j] != s[i + j + 1]);
        }
    }
    
    vector2<int> dp(n + 1, vector<int>(k + 1, INF));
    vector2<int> trace(n + 1, vector<int>(k + 1));
    dp[0][0] = 0;
    
    FOR(i, 1, n) {
        FOR(curk, 1, k) {
            FOR(j, 1, i) {
                if (dp[i][curk] > dp[j - 1][curk - 1] + cost[j][i]) {
                    dp[i][curk] = dp[j - 1][curk - 1] + cost[j][i];
                    trace[i][curk] = j - 1;
                }
            }
        }
    }
    
    int curi = n, curk = 0;
    FOR(i, 1, k) if (dp[n][i] < dp[n][curk]) curk = i;
    cout << dp[n][curk] << nl;
    
    vector<bool> mk(n + 1);
    while (curi != 0) {
        mk[curi] = 1;
        curi = trace[curi][curk];
        curk--;
    }
    
    str cur;
    FOR(i, 1, n) {
        cur += s[i];
        if (mk[i]) {
            FOR(j, 0, cur.size() / 2) {
                cur[j] = cur[cur.size() - 1 - j];
            }
            cout << cur;
            cur.clear();
            
            if (i != n) cout << '+';
        }
    }
    //////////////////////////////////////
}