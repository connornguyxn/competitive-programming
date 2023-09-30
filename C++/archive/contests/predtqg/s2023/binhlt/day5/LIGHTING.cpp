#include <bits/stdc++.h>
#define pb push_back

using namespace std;

const int maxN = 1e5 + 5;
int M, N, K, INF;
vector <int> G[maxN];
int mf, Fleft[maxN], Fright[maxN], Remember[maxN];

void InitFlow()
{
    memset(Fright, 0, sizeof Fright);
    memset(Fleft, 0, sizeof Fleft);
    mf = 0; INF = M + N + 1;
}

int FindPath()
{
    queue <int> Q;
    for(int u = 1; u <= M; ++u)
        if(Fleft[u] == 0) Q.push(u), Remember[u] = 0;
        else Remember[u] = INF;
    Remember[0] = INF;
    while(!Q.empty())
    {
        int u = Q.front(); Q.pop();
        for(int v: G[u])
        {
            int w = Fright[v];
            if(Remember[w] == INF)
            {
                Remember[w] = Remember[u] + 1;
                if(w == 0) return (Remember[0] < INF);
                Q.push(w);
            }
        }
    }
    return (Remember[0] < INF);
}

int Match(int u)
{
    if(u == 0) return 1;
    for(int v: G[u])
    {
        int w = Fright[v];
        if(Remember[w] == Remember[u] + 1 && Match(w))
        {
            Fright[v] = u;
            Fleft[u] = v;
            return 1;
        }
    }
    Remember[u] = INF;
    return 0;
}

int A[maxN], B[maxN];
#define DU "lighting"
int main()
{
    if (fopen(DU".inp","r")) {
        freopen(DU".inp", "r", stdin);
        freopen(DU".out", "w", stdout);
    }
    scanf("%d%d%d", &M, &N, &K);
    for(int u = 1; u <= M; ++u) G[u].clear();
    for(int i = 1; i <= K; ++i)
    {
        int u, v; scanf("%d%d", &u, &v);
        G[u].pb(v);
    }
    InitFlow();
    while(FindPath())
        for(int u = 1; u <= M; ++u) if(Remember[u] == 0 && Match(u)) ++mf;
    //cerr << mf;
    memset(A, 0, sizeof A);
    memset(B, 0, sizeof B);
    for(int u = 1; u <= M; ++u) if(Remember[u] < INF)
        for(int v: G[u]) if(v != Fleft[u]) B[v] = 1;
    for(int u = 1; u <= M; ++u)
    {
        int v = Fleft[u];
        if(v && B[v] == 0) A[u] = 1;
    }
    int CountA = 0, CountB = 0;
    for(int i = 1; i <= max(M, N); ++i) CountA += A[i], CountB += B[i];
    printf("%d %d\n", CountA, CountB);
    for(int i = 1; i <= M; ++i) if(A[i]) printf("%d ", i);
    for(int j = 1; j <= N; ++j) if(B[j]) printf("%d ", j);
}
