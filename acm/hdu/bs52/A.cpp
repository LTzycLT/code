#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<map>
#include<vector>
#include<string>
#include<set>
#include<queue>
#define MP(x,y) make_pair(x,y)
#define clr(x,y) memset(x,y,sizeof(x))
#define forn(i,n) for(int i=0;i<n;i++)
#define sqr(x) ((x)*(x))
#define MAX(a,b) if(a<b) a=b;
#define ll long long
using namespace std;

int INF = 1e9;
int n, m;
int a[20][20];
int dp[1 << 16][16];

int main() {
    freopen("/home/zyc/Documents/code/acm/in","r",stdin);
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                a[i][j] = INF;
            a[i][i] = 0;
        }
        for(int i = 0; i < m; i++)
        {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            u--;v--;
            a[u][v] = a[v][u] = min(a[u][v], w);
        }
        for(int k = 0; k < n; k++)
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    a[i][j] = min(a[i][j], a[i][k] + a[k][j]);

        int sum = (1 << n);
        for(int i = 0; i < sum; i++)
            for(int j = 0; j < n; j++)
                dp[i][j] = INF;
        dp[1][0] = 0;
        for(int i = 0; i < sum; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(dp[i][j] == INF) continue; 
                for(int k = 0; k < n; k++)
                {
                    dp[i | (1 << k)][k] = min(dp[i | (1 << k)][k], dp[i][j] + a[j][k]);
                }
            }
        }
        int ans = INF;
        for(int i = 0; i < n; i++)
            ans = min(ans, dp[sum - 1][i] + a[i][0]);

        printf("%d\n", ans);
    }
    return 0;
}
