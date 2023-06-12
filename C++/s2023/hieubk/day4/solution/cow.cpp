//Dai Ca Di Hoc
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define MIN(x,y) if (x < y) x = y
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define Task "cow"
#define maxk 25
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>
#define ll long long
#define BIT(x, i) ((x >> (i)) & 1)

using namespace std;

ll h[23];
vector <int> a[25];
int m, n, k;
ll b[21][1000001];
ll dp[1<<20];
int dai[22];

void read()
{
    cin >> m >> n >> k;
    for (int i = 0; i < k; i++) cin >> h[i];
    for (int i = 1; i <= n; i++)
    {
        int c, g;
        cin >> c >> g;
        a[g-1].push_back(c);
    }
}

void Prepare()
{
    for (int i = 0; i < k; i++)
    {
        sort(a[i].begin(), a[i].end());
        int l = a[i].size();
        b[i][1] = accumulate(a[i].begin(), a[i].end(), 0ll) - (1ll * l * (l+1)/2);
        int k = 0;
        for (int j = 2; j <= m; j++)
        {
            while (k < l && a[i][k] < j+k) k++;
            b[i][j] = b[i][j-1] + k -(l-k);
        }
        dai[i] = l;
    }
}

void QHD()
{
    dp[0] = 0;
    for (int i = 1; i < (1 << k); i++)
    {
        dp[i] = 1000000000000000000ll;
        int len = 0;
        for (int j = 0; j < k; j++)
            if (BIT(i,j)) len += dai[j];
        for (int j = 0; j < k; j++)
            if (BIT(i,j))
            {
                int x = i  - (1 << j);
                dp[i] = min (dp[i], dp[x] + h[j]* (b[j][len - dai[j] + 1]));
            }
    }
    cout << dp[(1 << k) - 1];
}

int main()
{
	ios_base::sync_with_stdio(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    read();
    Prepare();
    QHD();
    return 0;
}
