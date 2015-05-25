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

const int mod = 100007;
int dp[1005][1005];
char s[1005];
int n;

int dfs(int i, int j)
{
    if(i > j)
    {
        return 0;
    }
    else if(dp[i][j] != -1)
    {
        return dp[i][j];
    }
    else if(i == j)
    {
        dp[i][j] = 1;
        return dp[i][j];
    }

    dp[i][j] = 0;
    if(s[i] == s[j])
    {
        dp[i][j] += dfs(i + 1, j - 1) + 1;
    }
    dp[i][j] += dfs(i + 1, j) + dfs(i, j - 1) - dfs(i + 1, j - 1);
    dp[i][j] = (dp[i][j] % mod + mod) % mod;

    return dp[i][j];
}
int main() {
//    freopen("/home/zyc/Downloads/in","r",stdin);
//    freopen("/home/zyc/Downloads/out","w",stdout);
    freopen("/home/zyc/Documents/Code/cpp/in","r",stdin);
    int T;
    scanf("%d", &T);
    for(int cas = 0; cas < T; cas++)
    {
        scanf("%s", s);
        n = strlen(s);
        for(int i = 0; i < n; i++) 
        {
            for(int j = 0; j < n; j++)
            {
                dp[i][j] = -1; 
            }
        }
        dfs(0, n - 1);
        printf("Case #%d: %d\n", cas + 1, dp[0][n - 1]);
    }

    return 0;
}
