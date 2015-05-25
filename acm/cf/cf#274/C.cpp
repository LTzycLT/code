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

const int N = 5005;
int mod = 1e9 + 7;
int dp[N][N], n, a, b, k;

int main() {
//    freopen("/home/zyc/Downloads/in","r",stdin);
//    freopen("/home/zyc/Downloads/out","w",stdout);
    freopen("/home/zyc/Documents/Code/cpp/in","r",stdin);
    scanf("%d%d%d%d", &n, &a, &b, &k);
    dp[0][a] = 1;
    for(int i = 1; i <= k; i++)
    {
        int ans = 0, l = 0;
        for(int j = 1; j < b; j++)
        {
            while(abs(j - l - 1) < abs(b - l - 1))
            {
                ans += dp[i - 1][++l];
                if(ans >= mod) ans -= mod;
            }
            if(ans >= mod) ans -= mod;
            dp[i][j] = (ans - dp[i - 1][j] + mod);
            if(dp[i][j] >= mod) dp[i][j] -= mod;
        }
        
        ans = 0, l = n + 1;
        for(int j = n; j > b; j--)
        {
            while(abs(j - l + 1) < abs(b - l + 1)) 
            {
                ans += dp[i - 1][--l];
                if(ans >= mod) ans -= mod;
            }
            dp[i][j] = (ans - dp[i - 1][j] + mod);
            if(dp[i][j] >= mod) dp[i][j] -= mod;
        } 
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        ans += dp[k][i];
        if(ans >= mod) ans -= mod;
    }
    printf("%d\n", ans);
    return 0;
}
