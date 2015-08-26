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

ll dp[100];
int n;

int main() {
    freopen("/home/zyc/Documents/code/acm/in","r",stdin);


    while(scanf("%d", &n) != EOF)
    {
        clr(dp, 0);
        dp[0] = 1;
        ll ans = 0;
        for(int i = 1; i <= n; i++) 
        {
            dp[i] = 1;
            for(int j = 1; j <= i - 3; j++)
            {
                dp[i] += dp[j];
            }
            ans += dp[i];
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
