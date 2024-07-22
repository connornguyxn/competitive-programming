#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using str = string;
using pii = pair<int, int>;
#define fi first
#define se second
#define nl '\n'
#define sp ' '
#define BMASK(i) (1LL << (i))
#define BGET(n, i) (((n) >> (i)) & 1)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define REPD(i, n) for (int i = (n); i--; )
#define FOR(i, l, r) for (int i = (l), _r = (r); i <= _r; i++)
#define FORD(i, r, l) for (int i = (r), _l = (l); i >= _l; i--)
#define FORIN(it, a) for (auto& it : a)
const ll MOD = 1e9 + 7;
const int INF = 1e9 + 9;
const ll INFLL = 1e18 + 9;
template <class... T>
void print(T&&... n) {
    using exp = int[];
    exp{0, (cout << n << sp, 0)...};
    cout << endl;
}

// amsoi24r4_score
// <tags>

////////////////////////////////////////
////////////////////////////////////////
int main() {
    #define TASK "test"
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    cin.tie(nullptr)->sync_with_stdio(false);
    ////////////////////
    int n;
    cin >> n;
    
    vector<float> a(n);
    FORIN(it, a) cin >> it;
    sort(a.begin(), a.end());
    
    float sum = accumulate(a.begin(), a.end(), 0);
    REP(i, n) {
        if (round(sum / n) == 5) {
            cout << i;
            return 0;
        }
        sum -= a[i];
        sum += 5;
    }
    cout << n;
    ////////////////////
    return 0;
}