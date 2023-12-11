#include <bits/stdc++.h>

using namespace std;

#define int long long
#define fi first
#define se second
#define Rep(i, n)  for(int i = 1; i <= n; ++i)
#define For(i, a, b) for(int i = a; i <= b; ++i)
#define Ford(i, a, b) for(int i = a; i >= b; --i)
#define Forv(v, h) for(auto &v : h)
#define Bit(x, i) ((x) >> (i) & 1ll)
#define onbit(x, i) ((x) | (1ll << i))
#define offbit(x, i) ((x) &~ (1ll << i))
#define cnt_bit(x) __builtin_popcountll(x)
#define Log2(x) (63 - __builtin_clzll(x))
#define reset(h, v) (memset(h, v, sizeof(h)))
#define memoryof(v) (sizeof(v) / 1024 / 1024)

#define name "rsort"

using ii  = pair<int, int>;
using ull = unsigned long long;
using db  = long double;
using vi  = vector<int>;
using vvi  = vector<vi>;
using vii  = vector<ii>;

const int dx[] = {0, 0, +1, -1};
const int dy[] = {-1, +1, 0, 0};
const int MAXN = 1e4  + 10;
const int  MOD = 1e9  + 7;
const int   oo = 1e18 + 1;
const int base = 311;

template <class X, class Y> bool maximize(X &a, const Y &b) {
    if(a < b) return a = b, true;
    return false;
}
 
template <class X, class Y> bool minimize(X &a, const Y &b) {
    if(a > b) return a = b, true;
    return false;
}

int n, a[MAXN], b[MAXN], pos[MAXN], c[MAXN];

int vs[MAXN];
vi res[25];
int Max = 0;

void dnq(vi v, int k) {
	if (v.size() == 1) return;
	maximize(Max, k);
	vi v1, v2;
	int sz = (int) v.size() / 2;
	For(i, 0, sz - (!((int)v.size() & 1))) v1.emplace_back(v[i]);
	For(i, sz + ((int)v.size() & 1), (int)v.size() - 1) v2.emplace_back(v[i]);
	reverse(v1.begin(), v1.end()), dnq(v1, k + 1), dnq(v2, k + 1);
	Forv(x, v1) res[k].emplace_back(x);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);
    //_______________________________
    cin >> n;
    For(i, 1, n) cin >> a[i];
    vi h;
    For(i, 1, n) {
    	cin >> b[i];
    	h.emplace_back(b[i]);
    }
    dnq(h, 1);
    if (res[Max].size() == 0 || res[Max].back() == a[1]) Max += -1;
    cout << Max << '\n';
    Ford(k, Max, 1) {
    	if (res[k].size() > 0) {
    		cout << res[k].size() << ' ';
    		Forv(x, res[k])  cout << x << ' ';
    		cout << '\n';
    	}
    }
    cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << " s.\n";
    return 0;
}
