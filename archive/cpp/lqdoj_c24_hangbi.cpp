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
#define tvl (tv * 2)
#define tvr (tv * 2 + 1)
#define FOR(i, l, r) for (int i = (l), _r = (r); i <= _r; i++)
#define FORD(i, r, l) for (int i = (r), _l = (l); i >= _l; i--)
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

// https://lqdoj.edu.vn/contest/lqdojcup2024r1
// 2ptrs

int n, k, m;
vector<int> a;
////////////////////////////////////////////////////////////////////////////////
namespace sub1 {
    bool checksub() {
        return k == 1;
    }
    ////////////////////////////////////////
    void main() {
        int ans = 1;
        
        FOR(c, 1, m) {
            vector<int> tmp;
            
            FOR(i, 1, n) {
                if (a[i] != c) tmp.push_back(a[i]);
            }
            swap(tmp, a);
            
            int res = 1;
            FOR(i, 2, a.size() - 1) {
                if (a[i] == a[i - 1]) {
                    res++;
                    ans = max(ans, res);
                } else {
                    res = 1;
                }
            }
            
            swap(tmp, a);
        }
        
        cout << ans;
    }
}
////////////////////////////////////////////////////////////////////////////////
namespace sub23 {
    bool checksub() {
        return m <= 16;
    }
    ////////////////////////////////////////
    int ans = 1;
    vector<bool> exc;
    ////////////////////////////////////////
    void gen(int cur, int cnt) {
        if (cnt == 0 || cur > m) {
            vector<int> tmp;
            
            FOR(i, 1, n) {
                if (!exc[a[i]]) tmp.push_back(a[i]);
            }
            swap(tmp, a);
            
            int res = 1;
            FOR(i, 2, a.size() - 1) {
                if (a[i] == a[i - 1]) {
                    res++;
                    ans = max(ans, res);
                } else {
                    res = 1;
                }
            }
            
            swap(tmp, a);
            return;
        }
        
        exc[cur] = 1;
        gen(cur + 1, cnt - 1);
        exc[cur] = 0;
        gen(cur + 1, cnt);
    }
    ////////////////////////////////////////
    void main() {
        exc.resize(m + 1);
        gen(1, k);
        cout << ans;
    }
}
////////////////////////////////////////////////////////////////////////////////
namespace sub4 {
    bool checksub() {
        return true;
    }
    ////////////////////////////////////////
    vector<int> st;
    ////////////////////////////////////////
    void update(int p, int v, int tl = 1, int tr = n + 1, int tv = 1) {
        if (tl == tr) {
            st[tv] = v;
            return;
        }
        int tm = (tl + tr) / 2;
        if (p <= tm) update(p, v, tl, tm, tvl);
        else update(p, v, tm + 1, tr, tvr);
        st[tv] = st[tvl] + st[tvr];
    }
    ////////////////////////////////////////
    int walk(int cnt, int tl = 1, int tr = n + 1, int tv = 1) {
        if (tl == tr) return tl;
        int tm = (tl + tr) / 2;
        if (st[tvl] <= cnt) return walk(cnt - st[tvl], tm + 1, tr, tvr);
        return walk(cnt, tl, tm, tvl);
    }
    ////////////////////////////////////////
    void main() {
        vector2<int> cnt(n + 1, vector<int>(m + 1));
        FOR(i, 1, n) {
            cnt[i] = cnt[i - 1];
            cnt[i][a[i]]++;
        }
        
        st.resize(n * 4 + 4);
        update(n + 1, INF);
        
        int ans = 0;
        vector<int> last(m + 1);
        FORD(i, n, 1) {
            if (last[a[i]] != 0) {
                update(last[a[i]], 0);
            }
            update(i, 1);
            last[a[i]] = i;
            
            int r = walk(k + 1) - 1;
            FOR(c, 1, m) {
                ans = max(ans, cnt[r][c] - cnt[i - 1][c]);
            }
        }
        
        cout << ans;
    }
}
////////////////////////////////////////////////////////////////////////////////
namespace subfull {
    void main() {
        unordered_map<int, int> cnt;
        int l = 1, ans = 0;
        FOR(i, 1, n) {
            cnt[a[i]]++;
            ans = max(ans, cnt[a[i]]);
            while ((int)cnt.size() > k + 1) {
                cnt[a[l]]--;
                if (cnt[a[l]] == 0) cnt.erase(a[l]);
                l++;
            }
        }
        
        cout << ans;
    }
}
////////////////////////////////////////////////////////////////////////////////
int main() {
    // #define TASK "test"
    #define TASK "hangbi"
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    ////////////////////////////////////////
    cin >> n >> k;
    
    resize(n + 1, a);
    FOR(i, 1, n) {
        cin >> a[i];
    }
    
    auto zip = a;
    sort(all(zip));
    zip.erase(unique(all(zip)), zip.end());
    FORIN(it, a) it = lower_bound(all(zip), it) - zip.begin();
    m = zip.size() - 1;
    k = min(k, m);
    
    // if (sub1::checksub()) return sub1::main(), 0;
    // if (sub23::checksub()) return sub23::main(), 0;
    // if (sub4::checksub()) return sub4::main(), 0;
    return subfull::main(), 0;
    ////////////////////////////////////////
}