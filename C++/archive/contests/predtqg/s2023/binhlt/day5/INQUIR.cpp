#include <bits/stdc++.h>
#define TASK "INQUIR"
#define maxn 505
#define INF 1000000000
#define tr(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();++i)

using namespace std;
typedef pair<int,int> II;

int n, k, m;
II a[maxn];
int f[maxn][maxn];
vector<int> g[maxn];
int mf, x[maxn], y[maxn];
int d[maxn], q[maxn];

bool FindPath() {
    int L=1, R=0;
    for(int u=1;u<=k;++u) if (x[u]==0) {
        d[u]=0;
        q[++R]=u;
    } else d[u]=INF;
    d[0]=INF;
    while (L<=R) {
        int u=q[L++];
        tr(i,g[u]) {
            int v=*i;
            if (d[y[v]]==INF) {
                d[y[v]]=d[u]+1;
                if (y[v]) q[++R]=y[v];
            }
        }
    }
    return (d[0]!=INF);
}

bool dfs(int u) {
    if (u==0) return true;
    tr(i,g[u]) {
        int v=*i;
        if (d[y[v]]==d[u]+1)
        if (dfs(y[v])) {
            d[u]=INF;
            x[u]=v; y[v]=u;
            return true;
        }
    }
    d[u]=INF;
    return false;
}

void solve() {
    scanf("%d %d %d", &n, &k, &m);
    for(int i=1;i<=k;++i) {
        int u, v; scanf("%d %d", &u, &v);
        a[i]={u,v};
    }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j) f[i][j]=INF;
    for(int i=1;i<=m;++i) {
        int u, v, w; scanf("%d %d %d", &u, &v, &w);
        if (w<f[u][v]) f[u][v]=f[v][u]=w;
    }
    // Floy
    for(int u=1;u<=n;++u)
        for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
        if (f[i][j]>f[i][u]+f[u][j])
        f[i][j]=f[i][u]+f[u][j];
    for(int i=1;i<=n;++i) f[i][i]=0;
    // Dung do thi hai phia
    for(int u=1;u<=k;++u) g[u].clear();
    for(int i=1;i<=k;++i)
        for(int j=1;j<=k;++j) if (i!=j)
        if (f[a[i].second][a[j].second]<=a[j].first-a[i].first) g[i].push_back(j);
    // Tim cap ghep max
    mf=0;
    for(int u=1;u<=k;++u) x[u]=y[u]=0;
    while (FindPath()) {
        for(int u=1;u<=k;++u)
            if (x[u]==0)
            if (dfs(u)) mf++;
    }
    printf("%d\n",k-mf);
}

int main() {
    int T; scanf("%d",&T);
    while (T--) solve();
}
