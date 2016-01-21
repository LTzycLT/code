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

int n, k, A, B;
vector<int> vc[500005];
int dp[500005][12];
int f[500005][12];
int s[12];
int ans = 0;

int main() {
    //freopen("/home/zyc/Documents/code/acm/in","r",stdin);
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d%d%d", &n, &k, &A, &B);
        
        for(int i = 2; i <= n; i++) 
        {
            int fa = ((ll)A * i + B) % (i - 1) + 1; 
            vc[fa].push_back(i);
        }

        for(int u = n; u >= 1; u--)
        {
            dp[u][0] = 1;
            for(int i = 0; i < (int)vc[u].size(); i++)
            {
                int v = vc[u][i];
                for(int j = 1; j <= k; j++)
                {
                    dp[u][j] += dp[v][j - 1];
                }
            }    
        }
        ans = 0;
        clr(f[1], 0);
        for(int u = 1; u <= n; u++)
        {
            int u_ans = 1;
            for(int i = 1; i <= k; i++) u_ans += dp[u][i] + f[u][i];
            ans ^= u_ans;

            for(int i = 0; i < (int)vc[u].size(); i++)
            {
                int v = vc[u][i]; 
                for(int j = 1; j <= k; j++) s[j] = dp[u][j] - dp[v][j - 1];
                s[0] = 1;
                for(int j = 1; j <= k; j++) f[v][j] = f[u][j - 1] + s[j - 1];
                f[v][0] = 0;
            }
        }

        printf("%d\n", ans);

        for(int i = 1; i <= n; i++)
        {
            vc[i].clear();
            for(int j = 0; j <= k; j++)
            {
                dp[i][j] = 0;
            }
        }
    }
    return 0;
}
