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

struct item
{
    ll a, b, c;
}p[1005];
int n, time_limit;

ll dp[2][3005];
bool cmp(item a, item b)
{
    return a.b * b.c > a.c * b.b;
}
int main() {
    freopen("/home/zyc/Documents/code/acm/in","r",stdin);
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &n, &time_limit);       
        for(int i = 0; i < n; i++)
        {
            scanf("%I64d%I64d%I64d", &p[i].a, &p[i].b, &p[i].c);
        }
        sort(p, p + n, cmp);
        clr(dp, 0);
        for(int i = 0; i < n; i++)
        {
            int s = i & 1;  
            int t = s ^ 1;
            for(int j = 0; j <= time_limit; j++) dp[s][j] = dp[t][j];
            for(int  j = p[i].c; j <= time_limit; j++)
            {
                ll w = p[i].a - j * p[i].b;
                if(w <= 0) break;
                dp[s][j] = max(dp[t][j - p[i].c] + w, dp[s][j]); 
            }
        }
        int s = (n - 1) & 1;
        ll ans = 0;
        for(int i = 0; i <= time_limit; i++)
        {
            ans = max(ans, dp[s][i]);
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
